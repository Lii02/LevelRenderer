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

struct MatrixPushConstant {
	GW::MATH::GMATRIXF viewProjectionMatrix;
	GW::MATH::GMATRIXF modelMatrix;
};

struct LevelMesh {
	Mesh* mesh;
	H2B::ATTRIBUTES material;
	GW::MATH::GMATRIXF matrix;
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
public:
	LevelRenderer(VkDevice device, VkPhysicalDevice phys, VkRenderPass renderPass, VkViewport* viewportPtr, VkRect2D* scissorPtr, uint32_t frameCount);
	~LevelRenderer();

	void Draw(VkCommandBuffer commandBuffer, float aspectRatio);
	void Load(std::string filename);
};

#endif