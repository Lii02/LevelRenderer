#ifndef PIPELINE_H
#define PIPELINE_H
#include <vulkan/vulkan.h>
#include <string>
#include <vector>

struct StorageBuffer {
	uint32_t binding;
	size_t size;
	VkBuffer buffer;
	VkDeviceMemory bufferMemory;
};

class Pipeline {
private:
	VkViewport viewport;
	VkRect2D scissor;
	VkDevice device;
	VkPipeline pipeline;
	VkPipelineLayout layout;
	VkRenderPass renderPass;
	VkPrimitiveTopology topology;
	VkPolygonMode polygonMode;
	std::vector<VkVertexInputAttributeDescription> attribs;
	std::vector<VkPushConstantRange> pushConstantRanges;
	size_t stride;
	uint32_t frameCount;
	VkDescriptorPool descriptorPool;
	VkDescriptorSetLayout descriptorSetLayout;
	std::vector<VkDescriptorSet> descriptorSets;
	StorageBuffer storageBuffer;
public:
	Pipeline(VkDevice device, VkRenderPass renderPass, VkViewport viewport, VkRect2D scissor, std::vector<VkVertexInputAttributeDescription> attribs, uint32_t frameCount, StorageBuffer storageBuffer, size_t stride = 32, std::vector<VkPushConstantRange> pushConstantRanges = {}, VkPolygonMode polygonMode = VK_POLYGON_MODE_FILL, VkPrimitiveTopology topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST);
	~Pipeline();

	void Create(VkShaderModule vertexShader, VkShaderModule pixelShader, std::string vertexEntry, std::string pixelEntry);
	void Bind(VkCommandBuffer commandBuffer, VkViewport viewport, VkRect2D scissor);
	void SetTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology topology);
	void PushConstant(VkCommandBuffer commandBuffer, uint32_t rangeIndex, void* block);
	void BindDescriptors(VkCommandBuffer commandBuffer);
};

#endif