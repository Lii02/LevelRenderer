#ifndef PIPELINE_H
#define PIPELINE_H
#include <vulkan/vulkan.h>
#include <string>

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
public:
	Pipeline(VkDevice device, VkRenderPass renderPass, VkViewport viewport, VkRect2D scissor, VkPolygonMode polygonMode = VK_POLYGON_MODE_FILL, VkPrimitiveTopology topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST);
	~Pipeline();

	void Create(VkShaderModule vertexShader, VkShaderModule pixelShader, std::string vertexEntry, std::string pixelEntry);
	void Bind(VkCommandBuffer commandBuffer, VkViewport viewport, VkRect2D scissor);
	void SetTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology topology);
};

#endif