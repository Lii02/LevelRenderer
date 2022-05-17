#ifndef MESH_H
#define MESH_H
#include <vulkan/vulkan.h>
#include <vector>

class Mesh {
private:
	VkDevice device;
	VkPhysicalDevice phys;
	VkBuffer vertexBuffer, indexBuffer;
	VkDeviceMemory vertexMemory, indexMemory;
	size_t indexCount;
public:
	Mesh(VkDevice device, VkPhysicalDevice phys);
	~Mesh();

	void SetData(std::vector<float> vertices, std::vector<int> indices);
	void Draw(VkCommandBuffer commandBuffer);
};

#endif