#include <iostream>
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
#include "Stopwatch.h"
#include "LevelRenderer.h"

using namespace GW;
using namespace CORE;
using namespace SYSTEM;
using namespace MATH;
using namespace GRAPHICS;
#ifdef _WIN32
	#pragma comment(lib, "shaderc_combined.lib") 
#endif

int main(int argc, char** argv) {
	GWindow win;
	GEventResponder msgs;
	GVulkanSurface vulkan;
	GEventReceiver shutdown;

	if (+win.Create(100, 100, 1280, 720, GWindowStyle::WINDOWEDBORDERED)) {
		win.SetWindowName("Luke Inlow - Vulkan");
		VkClearValue clrAndDepth[2];
		clrAndDepth[0].color = { {0.7f, 0.12f, 0.3f, 1} };
		clrAndDepth[1].depthStencil = { 1.0f, 0u };
		win.Register(msgs);
#ifndef NDEBUG
		const char* debugLayers[] = {
			"VK_LAYER_KHRONOS_validation",
			//"VK_LAYER_RENDERDOC_Capture"
		};
		if (+vulkan.Create(win, GW::GRAPHICS::DEPTH_BUFFER_SUPPORT,
			sizeof(debugLayers) / sizeof(debugLayers[0]),
			debugLayers, 0, nullptr, 0, nullptr, false)) {
#else
		if (+vulkan.Create(win, GW::GRAPHICS::DEPTH_BUFFER_SUPPORT)) {
#endif
			Stopwatch deltaStopwatch;

			VkDevice device;
			VkPhysicalDevice phys;
			VkRenderPass renderPass;
			vulkan.GetDevice((void**)&device);
			vulkan.GetPhysicalDevice((void**)&phys);
			vulkan.GetRenderPass((void**)&renderPass);
			uint32_t frameCount;
			vulkan.GetSwapchainImageCount(frameCount);
			VkPhysicalDeviceProperties deviceProperties;
			vkGetPhysicalDeviceProperties(phys, &deviceProperties);
			// Debug stats
			std::cout << "Using device: " << deviceProperties.deviceName << std::endl;
			std::cout << "Storage buffer alignment: " << deviceProperties.limits.minStorageBufferOffsetAlignment << std::endl;
			std::cout << "Max storage buffer size: " << deviceProperties.limits.maxStorageBufferRange << std::endl;
			std::cout << "Max uniform buffer size: " << deviceProperties.limits.maxUniformBufferRange << std::endl;
			std::cout << "Max push constant size: " << deviceProperties.limits.maxPushConstantsSize << std::endl;
			
			auto getViewportScissor = [=](VkViewport& viewport, VkRect2D& scissor) {
				unsigned int width, height;
				win.GetClientWidth(width);
				win.GetClientHeight(height);
				viewport = {
					0, 0, static_cast<float>(width), static_cast<float>(height), 0, 1
				};
				scissor = { {0, 0}, {width, height} };
			};
			
			VkViewport viewport;
			VkRect2D scissor;

			LevelRenderer* level = new LevelRenderer(&win, &vulkan, &viewport, &scissor);
			
			shutdown.Create(vulkan, [&]() {
				if (+shutdown.Find(GW::GRAPHICS::GVulkanSurface::Events::RELEASE_RESOURCES, true)) {
					vkDeviceWaitIdle(device);
					delete level;
				}
			});

			bool canUnloadLevel;
			while (+win.ProcessWindowEvents()) {
				if (+vulkan.StartFrame(2, clrAndDepth)) {
					deltaStopwatch.Begin();
					uint32_t currentFrame;
					vulkan.GetSwapchainCurrentImage(currentFrame);
					VkCommandBuffer commandBuffer;
					vulkan.GetCommandBuffer(currentFrame, (void**)&commandBuffer);
					getViewportScissor(viewport, scissor);

					float aspectRatio;
					vulkan.GetAspectRatio(aspectRatio);
					level->Draw(commandBuffer, aspectRatio);
					vulkan.EndFrame(true);

					level->Update(currentFrame, deltaStopwatch.GetDeltaSeconds());
					deltaStopwatch.End();
				}
			}
		}
	}
	return 0;
}