#include "Mesh.h"
#define GATEWARE_DISABLE_GDIRECTX11SURFACE
#define GATEWARE_DISABLE_GDIRECTX12SURFACE
#define GATEWARE_DISABLE_GRASTERSURFACE
#define GATEWARE_DISABLE_GOPENGLSURFACE
#define GATEWARE_ENABLE_GRAPHICS
#include "Gateware.h"

using namespace GW;

Mesh::Mesh(VkDevice device, VkPhysicalDevice phys) {
	this->device = device;
	this->phys = phys;
}

Mesh::~Mesh() {
	vkDestroyBuffer(device, vertexBuffer, nullptr);
	vkFreeMemory(device, vertexMemory, nullptr);
	vkDestroyBuffer(device, indexBuffer, nullptr);
	vkFreeMemory(device, indexMemory, nullptr);
}

void Mesh::SetData(const Vertices& vertices, const Indices& indices) {
	this->indexCount = indices.size();
	GvkHelper::create_buffer(phys, device, vertices.size() * sizeof(MeshVertex),
		VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
		VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &vertexBuffer, &vertexMemory);
	GvkHelper::write_to_buffer(device, vertexMemory, vertices.data(), vertices.size() * sizeof(MeshVertex));

	GvkHelper::create_buffer(phys, device, indices.size() * sizeof(int),
		VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
		VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &indexBuffer, &indexMemory);
	GvkHelper::write_to_buffer(device, indexMemory, indices.data(), indices.size() * sizeof(int));
}

void Mesh::Bind(VkCommandBuffer commandBuffer) {
	VkDeviceSize offsets[] = { 0 };
	vkCmdBindVertexBuffers(commandBuffer, 0, 1, &vertexBuffer, offsets);
	vkCmdBindIndexBuffer(commandBuffer, indexBuffer, 0, VK_INDEX_TYPE_UINT32);
}

void Mesh::Draw(VkCommandBuffer commandBuffer) {
	vkCmdDrawIndexed(commandBuffer, indexCount, 1, 0, 0, 0);
}

void Mesh::DrawInstanced(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t firstIndex) {
	vkCmdDrawIndexed(commandBuffer, indexCount, 1, firstIndex, 0, 0);
}