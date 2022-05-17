#ifndef MESH_H
#define MESH_H
#include <vulkan/vulkan.h>
#include <vector>

struct Vertex {
	float pos[3];
	float uv[2];
	float nrm[3];
};

typedef std::vector<Vertex> Vertices;
typedef std::vector<int> Indices;

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

	void SetData(const Vertices& vertices, const Indices& indices);
	void Draw(VkCommandBuffer commandBuffer);
};

#endif