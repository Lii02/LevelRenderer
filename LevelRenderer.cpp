#include "LevelRenderer.h"
#include "FileHelper.h"
#include "ShaderCompiler.h"
#include "Stopwatch.h"
#include <sstream>
#include "StringHelper.h"
#include "BufferHelper.h"
#include "MatrixHelper.h"

LevelRenderer::LevelRenderer(GW::SYSTEM::GWindow* window, VkDevice device, VkPhysicalDevice phys, VkRenderPass renderPass, VkViewport* viewportPtr, VkRect2D* scissorPtr, uint32_t frameCount) {
	this->window = window;
	this->device = device;
	this->phys = phys;
	this->viewportPtr = viewportPtr;
	this->scissorPtr = scissorPtr;
	this->frameCount = frameCount;
	matrixProxy.Create();
	vectorProxy.Create();
	inputProxy.Create(*window);

	std::vector<VkVertexInputAttributeDescription> attribs = {
		{ 0, 0, VK_FORMAT_R32G32B32_SFLOAT, offsetof(MeshVertex, pos) },
		{ 1, 0, VK_FORMAT_R32G32_SFLOAT, offsetof(MeshVertex, uv) },
		{ 2, 0, VK_FORMAT_R32G32B32_SFLOAT, offsetof(MeshVertex, nrm) }
	};
	std::vector<VkPushConstantRange> pushConstants;
	VkPushConstantRange range;
	range.offset = 0;
	range.size = sizeof(MiscData);
	range.stageFlags = VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
	pushConstants.push_back(range);

	storageBuffer.size = sizeof(SceneData);
	GvkHelper::create_buffer(phys, device, storageBuffer.size,
		VK_BUFFER_USAGE_STORAGE_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
		VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &storageBuffer.buffer, &storageBuffer.bufferMemory);

	Stopwatch compileWatch;
	compileWatch.Begin();
	ShaderCompiler shaderCompiler;
	std::string shaderSource;
	FileHelper::LoadFile(shaderSource, "../DefaultShader.hlsl");
	ShaderCompilerResult compiledShaders;
	shaderCompiler.Compile(device, shaderSource, "VS", "PS", compiledShaders);
	compileWatch.End();
	std::cout << "Shader compiling took " << compileWatch.GetDeltaMillis() << " milliseconds!" << std::endl;
	pipeline = new Pipeline(device, renderPass, *viewportPtr, *scissorPtr, attribs, frameCount, storageBuffer, sizeof(MeshVertex), pushConstants);
	pipeline->Create(compiledShaders.vertexShader, compiledShaders.pixelShader, "VS", "PS");
	this->vertexShader = compiledShaders.vertexShader;
	this->pixelShader = compiledShaders.pixelShader;

	Light light;
	light.type = LightType::DIRECTIONAL_LIGHT;
	light.intensity = 1.0f;
	light.color = { 1, 1, 1 };
	light.ambient = { 0.1f, 0.1f, 0.1f };
	light.positionDirection = { -1, -1, 2 };
	sceneLights.push_back(light);
	light.type = LightType::POINT_LIGHT;
	light.intensity = 1.0f;
	light.color = { 1, 0, 0 };
	light.ambient = { 0.1f, 0.0f, 0.0f };
	light.falloff = { 0.1f, 0.1f, 0.1f };
	light.positionDirection = { -1, 2.5, -2 };
	sceneLights.push_back(light);

	Stopwatch loadingWatch;
	loadingWatch.Begin();
	Load("../GameLevel.txt");
	loadingWatch.End();
	std::cout << "Level loading took " << loadingWatch.GetDeltaMillis() << " milliseconds!" << std::endl;
}

LevelRenderer::~LevelRenderer() {
	for (LevelMesh& lm : meshes) {
		delete lm.mesh;
	}
	vkFreeMemory(device, storageBuffer.bufferMemory, nullptr);
	vkDestroyBuffer(device, storageBuffer.buffer, nullptr);
	vkDestroyShaderModule(device, vertexShader, nullptr);
	vkDestroyShaderModule(device, pixelShader, nullptr);
	delete pipeline;
}

void LevelRenderer::Draw(VkCommandBuffer commandBuffer, float aspectRatio) {
	GW::MATH::GMATRIXF viewMatrix = cameraTransform.GetTransform(matrixProxy);

	SceneData* sceneData = new SceneData;
	memset(sceneData, 0, sizeof(SceneData));
	GW::MATH::GMATRIXF projection;
	matrixProxy.ProjectionVulkanLHF(G_DEGREE_TO_RADIAN(65.0f), aspectRatio, 0.1f, 100.0f, projection);
	matrixProxy.MultiplyMatrixF(viewMatrix, projection, sceneData->viewProjection);
	MiscData miscData;
	miscData.lightsUsed = sceneLights.size();
	memcpy(sceneData->materials, sceneMaterials.data(), sizeof(LevelMeshMaterial) * sceneMaterials.size());
	memcpy(sceneData->lights, sceneLights.data(), sizeof(Light) * sceneLights.size());
	BufferHelper::WriteToBuffer(device, storageBuffer.bufferMemory, sceneData, sizeof(SceneData));
	delete sceneData;

	pipeline->Bind(commandBuffer, *viewportPtr, *scissorPtr);
	for (size_t i = 0; i < meshes.size(); i++) {
		LevelMesh& lm = meshes[i];
		miscData.model = lm.model;
		miscData.cameraPosition = cameraTransform.position;
		for (int j = 0; j < lm.batchCount; j++) {
			lm.mesh->Bind(commandBuffer);
			miscData.index = j;
			miscData.materialIndex = lm.firstMaterial + lm.materialIndices[j];
			pipeline->BindDescriptors(commandBuffer);
			pipeline->PushConstant(commandBuffer, 0, &miscData);
			lm.mesh->DrawInstanced(commandBuffer, lm.batches[j].indexCount, lm.batches[j].indexOffset);
		}
	}
}

void LevelRenderer::Update(double deltaTime) {
	const float speed = 10.0f;
	const float rotationSpeed = 50.0f;
	float wState = 0, sState = 0, dState = 0, aState = 0, shiftState = 0, spaceState, upState = 0, downState = 0, leftState = 0, rightState = 0;
	inputProxy.GetState(G_KEY_W, wState);
	inputProxy.GetState(G_KEY_A, aState);
	inputProxy.GetState(G_KEY_S, sState);
	inputProxy.GetState(G_KEY_D, dState);
	inputProxy.GetState(G_KEY_SPACE, spaceState);
	inputProxy.GetState(G_KEY_LEFTSHIFT, shiftState);
	inputProxy.GetState(G_KEY_LEFT, leftState);
	inputProxy.GetState(G_KEY_RIGHT, rightState);
	inputProxy.GetState(G_KEY_UP, upState);
	inputProxy.GetState(G_KEY_DOWN, downState);
	GW::MATH::GMATRIXF viewMatrix = cameraTransform.GetTransform(matrixProxy);

	auto forward = MatrixHelper::Forward(matrixProxy, vectorProxy, viewMatrix);
	auto left = MatrixHelper::Left(matrixProxy, vectorProxy, viewMatrix);

	float dt = speed * deltaTime;
	if (wState)
	{
		cameraTransform.position.x += forward.x * -dt;
		cameraTransform.position.z += forward.z * -dt;
	} else if (sState) {
		cameraTransform.position.x += forward.x * dt;
		cameraTransform.position.z += forward.z * dt;
	}

	if (aState) {
		cameraTransform.position.x += left.x * dt;
		cameraTransform.position.z += -left.z * -dt;
	} else if (dState) {
		cameraTransform.position.x += left.x * -dt;
		cameraTransform.position.z += left.z * -dt;
	}

	if (shiftState) {
		cameraTransform.position.y += dt;
	} else if (spaceState) {
		cameraTransform.position.y -= dt;
	}

	cameraTransform.rotation.x += (upState - downState) * rotationSpeed * deltaTime;
	cameraTransform.rotation.y += (leftState - rightState) * rotationSpeed * deltaTime;
}

GW::MATH::GMATRIXF ParseMatrix(GW::MATH::GMatrix& matrixProxy, std::istringstream& stream) {
	GW::MATH::GMATRIXF matrix;
	for (int i = 0; i < 4; i++) {
		std::string matrixLine;
		std::getline(stream, matrixLine);
		StringHelper::TrimString(matrixLine);
		GW::MATH::GVECTORF vec;
		if (i == 0) {
			std::sscanf(matrixLine.c_str(), "<Matrix4x4(%f,%f,%f,%f)", &vec.x, &vec.y, &vec.z, &vec.w);
		} else if (i == 3) {
			std::sscanf(matrixLine.c_str(), "(%f,%f,%f,%f)>", &vec.x, &vec.y, &vec.z, &vec.w);
		} else {
			std::sscanf(matrixLine.c_str(), "(%f,%f,%f,%f)", &vec.x, &vec.y, &vec.z, &vec.w);
		}

		switch (i) {
		case 0:
			matrix.row1 = vec;
			break;
		case 1:
			matrix.row2 = vec;
			break;
		case 2:
			matrix.row3 = vec;
			break;
		case 3:
			matrix.row4 = vec;
			break;
		}
	}
	return matrix;
}

void LevelRenderer::Load(std::string filename) {
	std::string fileData;
	FileHelper::LoadFile(fileData, filename);
	H2B::Parser parser;
	std::istringstream input;
	input.str(fileData);

	while (true) {
		std::string line;
		std::getline(input, line);

		if (std::strcmp(line.c_str(), "MESH") == 0) {
			std::string meshName;
			std::getline(input, meshName);
			std::string meshPath = "../Assets/" + meshName + ".h2b";
			parser.Parse(meshPath.c_str());
			LevelMesh levelMesh;
			levelMesh.mesh = new Mesh(device, phys);
			Vertices vertices(parser.vertexCount);
			for (size_t i = 0; i < parser.vertexCount; i++) {
				memcpy(&vertices[i].pos, &parser.vertices[i].pos, sizeof(H2B::VECTOR));
				memcpy(&vertices[i].uv, &parser.vertices[i].uvw, sizeof(float) * 2);
				memcpy(&vertices[i].nrm, &parser.vertices[i].nrm, sizeof(H2B::VECTOR));
			}
			levelMesh.materialCount = parser.materialCount;
			levelMesh.firstMaterial = sceneMaterials.size();
			for (size_t i = 0; i < parser.materialCount; i++) {
				LevelMeshMaterial material;
				memcpy(&material, &parser.materials[i].attrib, sizeof(LevelMeshMaterial));
				sceneMaterials.push_back(material);
				levelMesh.batches.push_back(parser.batches[i]);
				levelMesh.materialIndices.push_back(parser.meshes[i].materialIndex);
			}
			levelMesh.batchCount = parser.meshCount;
			levelMesh.mesh->SetData(vertices, parser.indices);
			levelMesh.model = ParseMatrix(matrixProxy, input);

			meshes.push_back(levelMesh);
			parser.Clear();
		} else if (std::strcmp(line.c_str(), "CAMERA") == 0) {
			std::string cameraName;
			std::getline(input, cameraName);
			GW::MATH::GMATRIXF viewMatrix, parsedMatrix;
			parsedMatrix = ParseMatrix(matrixProxy, input);
			matrixProxy.InverseF(parsedMatrix, viewMatrix);
			matrixProxy.GetTranslationF(parsedMatrix, cameraTransform.position);
			cameraTransform.position = { -cameraTransform.position.x, -cameraTransform.position.y, -cameraTransform.position.z };
			matrixProxy.GetRotationF(parsedMatrix, cameraTransform.rotation);
			matrixProxy.GetScaleF(parsedMatrix, cameraTransform.scale);
		}

		if (line.empty())
			break;
	}
}