#ifndef MESH_H
#define MESH_H
#include <vulkan/vulkan.h>
#include <vector>

struct MeshVertex {
	float pos[3];
	float uv[2];
	float nrm[3];
};

typedef std::vector<MeshVertex> Vertices;
typedef std::vector<unsigned int> Indices;

class Mesh {
private:
	VkDevice device;
	VkPhysicalDevice phys;
	VkBuffer vertexBuffer, indexBuffer;
	VkDeviceMemory vertexMemory, indexMemory;
	uint32_t indexCount;
public:
	Mesh(VkDevice device, VkPhysicalDevice phys);
	~Mesh();

	void SetData(const Vertices& vertices, const Indices& indices);
	void Draw(VkCommandBuffer commandBuffer);
	void DrawInstanced(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t firstIndex);
};

#endif