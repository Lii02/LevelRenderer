#include "LevelRenderer.h"
#include "FileHelper.h"
#include "ShaderCompiler.h"

LevelRenderer::LevelRenderer(VkDevice device, VkPhysicalDevice phys, VkRenderPass renderPass, VkViewport* viewportPtr, VkRect2D* scissorPtr, uint32_t frameCount) {
	this->device = device;
	this->phys = phys;
	this->viewportPtr = viewportPtr;
	this->scissorPtr = scissorPtr;
	this->frameCount = frameCount;
	matrixProxy.Create();
	vectorProxy.Create();

	storageBuffer.binding = 0;
	storageBuffer.size = sizeof(SceneData);
	GvkHelper::create_buffer(phys, device, sizeof(SceneData),
		VK_BUFFER_USAGE_STORAGE_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
		VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &storageBuffer.buffer, &storageBuffer.bufferMemory);

	std::vector<VkVertexInputAttributeDescription> attribs = {
				{ 0, 0, VK_FORMAT_R32G32B32_SFLOAT, offsetof(MeshVertex, pos) },
				{ 1, 0, VK_FORMAT_R32G32_SFLOAT, offsetof(MeshVertex, uv) },
				{ 2, 0, VK_FORMAT_R32G32B32_SFLOAT, offsetof(MeshVertex, nrm) }
	};
	pipeline = new Pipeline(device, renderPass, *viewportPtr, *scissorPtr, attribs, frameCount, sizeof(MeshVertex), &storageBuffer);

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
}

LevelRenderer::~LevelRenderer() {
	for (LevelMesh& lm : meshes) {
		delete lm.mesh;
	}
	vkDestroyBuffer(device, storageBuffer.buffer, nullptr);
	vkFreeMemory(device, storageBuffer.bufferMemory, nullptr);
	vkDestroyShaderModule(device, vertexShader, nullptr);
	vkDestroyShaderModule(device, pixelShader, nullptr);
	delete pipeline;
}

void LevelRenderer::Draw(VkCommandBuffer commandBuffer, float aspectRatio) {
	pipeline->Bind(commandBuffer, *viewportPtr, *scissorPtr);
	for (LevelMesh& lm : meshes) {
		SceneData sceneData;
		sceneData.modelMatrix = lm.matrix;
		matrixProxy.IdentityF(sceneData.viewMatrix);
		matrixProxy.TranslateGlobalF(sceneData.viewMatrix, cameraPosition, sceneData.viewMatrix);
		matrixProxy.ProjectionVulkanLHF(G_DEGREE_TO_RADIAN(90.0f), aspectRatio, 0.1f, 100.0f, sceneData.projectionMatrix);
		GvkHelper::write_to_buffer(device, storageBuffer.bufferMemory, &sceneData, sizeof(SceneData));
		lm.mesh->Draw(commandBuffer);
	}
}