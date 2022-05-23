#include "LevelRenderer.h"
#include "FileHelper.h"
#include "ShaderCompiler.h"
#include "Stopwatch.h"
#include <sstream>
#include "StringHelper.h"

LevelRenderer::LevelRenderer(VkDevice device, VkPhysicalDevice phys, VkRenderPass renderPass, VkViewport* viewportPtr, VkRect2D* scissorPtr, uint32_t frameCount) {
	this->device = device;
	this->phys = phys;
	this->viewportPtr = viewportPtr;
	this->scissorPtr = scissorPtr;
	this->frameCount = frameCount;
	matrixProxy.Create();
	vectorProxy.Create();

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
	GvkHelper::create_buffer(phys, device, sizeof(SceneData),
		VK_BUFFER_USAGE_STORAGE_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
		VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &storageBuffer.buffer, &storageBuffer.bufferMemory);

	pipeline = new Pipeline(device, renderPass, *viewportPtr, *scissorPtr, attribs, frameCount, storageBuffer, sizeof(MeshVertex), pushConstants);
	ShaderCompiler shaderCompiler;
	std::string shaderSource;
	FileHelper::LoadFile(shaderSource, "../DefaultShader.hlsl");
	std::string vertexEntry = "VS";
	std::string pixelEntry = "PS";
	ShaderCompilerResult compiledShaders;
	shaderCompiler.Compile(device, shaderSource, vertexEntry, pixelEntry, compiledShaders);
	pipeline->Create(compiledShaders.vertexShader, compiledShaders.pixelShader, vertexEntry, pixelEntry);
	this->vertexShader = compiledShaders.vertexShader;
	this->pixelShader = compiledShaders.pixelShader;

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
	SceneData sceneData;
	GW::MATH::GMATRIXF projection;
	matrixProxy.ProjectionVulkanLHF(G_DEGREE_TO_RADIAN(65.0f), aspectRatio, 0.1f, 100.0f, projection);
	matrixProxy.MultiplyMatrixF(cameraMatrix, projection, sceneData.viewProjection);
	MiscData miscData;
	memcpy(&sceneData.materials, sceneMaterials.data(), sizeof(H2B::ATTRIBUTES) * MAX_MATERIAL_COUNT);
	GvkHelper::write_to_buffer(device, storageBuffer.bufferMemory, &sceneData, sizeof(SceneData));

	pipeline->Bind(commandBuffer, *viewportPtr, *scissorPtr);
	for (size_t i = 0; i < meshes.size(); i++) {
		LevelMesh& lm = meshes[i];
		miscData.model = lm.model;
		matrixProxy.GetTranslationF(cameraMatrix, miscData.cameraPosition);
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
			matrixProxy.IdentityF(cameraMatrix);
			matrixProxy.InverseF(ParseMatrix(matrixProxy, input), cameraMatrix);
		}

		if (line.empty())
			break;
	}
}