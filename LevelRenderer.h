#ifndef LEVELRENDERER_H
#define LEVELRENDERER_H
#include "Mesh.h"
#include "Pipeline.h"
#define GATEWARE_DISABLE_GDIRECTX11SURFACE
#define GATEWARE_DISABLE_GDIRECTX12SURFACE
#define GATEWARE_DISABLE_GRASTERSURFACE
#define GATEWARE_DISABLE_GOPENGLSURFACE
#define GATEWARE_ENABLE_GRAPHICS
#define GATEWARE_ENABLE_CORE
#define GATEWARE_ENABLE_SYSTEM
#define GATEWARE_ENABLE_GRAPHICS
#define GATEWARE_ENABLE_MATH
#define GATEWARE_ENABLE_INPUT
#include "Gateware.h"

struct SceneData {
	GW::MATH::GMATRIXF projectionMatrix;
	GW::MATH::GMATRIXF viewMatrix;
	GW::MATH::GMATRIXF modelMatrix;
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
	StorageBuffer storageBuffer;
public:
	LevelRenderer(VkDevice device, VkPhysicalDevice phys, VkRenderPass renderPass, VkViewport* viewportPtr, VkRect2D* scissorPtr, uint32_t frameCount);
	~LevelRenderer();
};

#endif