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
	alignas(16) VectorImpl falloff;
	float intensity;
	LightType type;
};

#define MAX_MATERIAL_COUNT 35
#define MAX_LIGHT_COUNT 5
struct SceneData {
	GW::MATH::GMATRIXF viewProjection;
	LevelMeshMaterial materials[MAX_MATERIAL_COUNT];
	Light lights[MAX_LIGHT_COUNT];
	// This should not be higher than MAX_LIGHT_COUNT
	int lightsUsed;
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

struct Transform {
	GW::MATH::GVECTORF position;
	GW::MATH::GQUATERNIONF rotation;
	GW::MATH::GVECTORF scale;

	GW::MATH::GMATRIXF GetTransform(GW::MATH::GMatrix& proxy) {
		GW::MATH::GMATRIXF matrix;
		proxy.IdentityF(matrix);
		proxy.ScaleLocalF(matrix, scale, matrix);
		proxy.RotateXLocalF(matrix, G_DEGREE_TO_RADIAN(rotation.x), matrix);
		proxy.RotateYLocalF(matrix, G_DEGREE_TO_RADIAN(rotation.y), matrix);
		proxy.RotateZLocalF(matrix, G_DEGREE_TO_RADIAN(rotation.z), matrix);
		proxy.TranslateLocalF(matrix, position, matrix);
		return matrix;
	}
};

class LevelRenderer {
private:
	GW::GRAPHICS::GVulkanSurface* vulkan;
	VkDevice device;
	VkPhysicalDevice phys;
	VkRenderPass renderPass;
	VkViewport* viewportPtr;
	VkRect2D* scissorPtr;
	Pipeline* pipeline;
	uint32_t frameCount;
	VkShaderModule vertexShader, pixelShader;
	GW::MATH::GMatrix matrixProxy;
	GW::MATH::GVector vectorProxy;
	GW::INPUT::GInput inputProxy;
	std::vector<LevelMesh> meshes;
	Transform cameraTransform;
	StorageBuffer storageBuffer;
	std::vector<LevelMeshMaterial> sceneMaterials;
	std::vector<Light> sceneLights;
	GW::SYSTEM::GWindow* window;
public:
	LevelRenderer(GW::SYSTEM::GWindow* window, GW::GRAPHICS::GVulkanSurface* vulkan, VkViewport* viewportPtr, VkRect2D* scissorPtr);
	~LevelRenderer();

	void Draw(VkCommandBuffer commandBuffer, float aspectRatio);
	void Update(uint32_t currentFrame, double deltaTime);
	void Load(std::string filename);
	void UnloadLevel();
};

#endif