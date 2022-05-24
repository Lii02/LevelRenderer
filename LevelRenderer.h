#ifndef LEVELRENDERER_H
#define LEVELRENDERER_H
#include "Mesh.h"
#include "Pipeline.h"
#define GATEWARE_ENABLE_CORE
#define GATEWARE_ENABLE_SYSTEM
#define GATEWARE_ENABLE_GRAPHICS
#define GATEWARE_ENABLE_MATH
#define GATEWARE_ENABLE_INPUT
#define GATEWARE_DISABLE_GDIRECTX11SURFACE
#define GATEWARE_DISABLE_GDIRECTX12SURFACE
#define GATEWARE_DISABLE_GRASTERSURFACE
#define GATEWARE_DISABLE_GOPENGLSURFACE
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

enum LightType : uint32_t {
	POINT_LIGHT = 0,
	DIRECTIONAL_LIGHT = 1
};

struct Light {
	alignas(16) VectorImpl color;
	alignas(16) VectorImpl positionDirection;
	alignas(16) VectorImpl ambient;
	float intensity;
	LightType type;
};

#define MAX_MATERIAL_COUNT 35
#define MAX_LIGHT_COUNT 5
struct SceneData {
	GW::MATH::GMATRIXF viewProjection;
	LevelMeshMaterial materials[MAX_MATERIAL_COUNT];
	Light lights[MAX_LIGHT_COUNT];
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
	GW::INPUT::GInput inputProxy;
	std::vector<LevelMesh> meshes;
	GW::MATH::GMATRIXF viewMatrix;
	StorageBuffer storageBuffer;
	std::vector<LevelMeshMaterial> sceneMaterials;
	std::vector<Light> sceneLights;
	GW::SYSTEM::GWindow* window;
public:
	LevelRenderer(GW::SYSTEM::GWindow* window, VkDevice device, VkPhysicalDevice phys, VkRenderPass renderPass, VkViewport* viewportPtr, VkRect2D* scissorPtr, uint32_t frameCount);
	~LevelRenderer();

	void Draw(VkCommandBuffer commandBuffer, float aspectRatio);
	void Update(double deltaTime);
	void Load(std::string filename);
};

#endif