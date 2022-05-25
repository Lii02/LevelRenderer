#ifndef TEXTURE2D_H
#define TEXTURE2D_H
#include <vulkan/vulkan.h>
#include <cstdint>
#include <string>

class Texture2D {
private:
    VkImage textureImage;
    VkDeviceMemory textureImageMemory;
    VkImageView textureImageView;
    VkSampler textureSampler;
    uint32_t width, height, bits;
    VkDevice device;
public:
    Texture2D(std::string path, VkPhysicalDevice phys, VkDevice device, VkCommandPool commandPool, VkQueue graphicsQueue);
    ~Texture2D();
};

#endif