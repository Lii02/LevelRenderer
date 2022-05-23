#ifndef LEVELRENDERER_H
#define LEVELRENDERER_H
#include "Mesh.h"
#include "Pipeline.h"
#define GATEWARE_DISABLE_GDIRECTX11SURFACE
#define GATEWARE_DISABLE_GDIRECTX12SURFACE
#define GATEWARE_DISABLE_GRASTERSURFACE
#define GATEWARE_DISABLE_GOPENGLSURFACE
#define GATEWARE_ENABLE_GRAPHICS
#define GATEWARE_ENABLE_MATH
#define GATEWARE_ENABLE_INPUT
#include "Gateware.h"
#include "h2bParser.h"

struct VectorImpl {
	float x, y, z;
};

struct LevelMeshMaterial {
	VectorImpl Kd;
	float d;
	VectorImpl Ks;
	float Ns;
	VectorImpl Ka;
	float sharpness;
	VectorImpl Tf;
	float Ni;
	VectorImpl Ke;
	int illum;
};

#define MAX_MATERIAL_COUNT 100
struct SceneData {
	GW::MATH::GMATRIXF viewProjection;
	LevelMeshMaterial* materials;

	static size_t GetSize() {
		return sizeof(GW::MATH::GMATRIXF) + (sizeof(LevelMeshMaterial) * MAX_MATERIAL_COUNT);
	}
};

struct MiscData {
	int index;
	int materialIndex;
	alignas(16) GW::MATH::GMATRIXF model;
	GW::MATH::GVECTORF cameraPosition;
};

struct LevelMesh {
	Mesh* mesh;
	std::vector<unsigned int> materialIndices;
	int materialCount;
	int firstMaterial;
	GW::MATH::GMATRIXF model;
	std::vector<H2B::BATCH> batches;
	size_t batchCount;
};

class LevelRenderer {
private:
	VkDevice device;
	VkPhysicalDevice phys;
	VkViewport* viewportPtr;
	VkRect2D* scissorPtr;
	Pipeline* pipeline;
	uint32_t frameCount;
	VkShaderModule vertexShader, pixelShader;
	GW::MATH::GMatrix matrixProxy;
	GW::MATH::GVector vectorProxy;
	std::vector<LevelMesh> meshes;
	GW::MATH::GMATRIXF cameraMatrix;
	StorageBuffer storageBuffer;
	std::vector<LevelMeshMaterial> sceneMaterials;
public:
	LevelRenderer(VkDevice device, VkPhysicalDevice phys, VkRenderPass renderPass, VkViewport* viewportPtr, VkRect2D* scissorPtr, uint32_t frameCount);
	~LevelRenderer();

	void Draw(VkCommandBuffer commandBuffer, float aspectRatio);
	void Load(std::string filename);
};

#endif