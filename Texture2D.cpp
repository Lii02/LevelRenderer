#include "Texture2D.h"
#define GATEWARE_ENABLE_GRAPHICS
#include "Gateware.h"
#include "BMPLoader.h"

Texture2D::Texture2D(std::string path, VkPhysicalDevice phys, VkDevice device, VkCommandPool commandPool, VkQueue graphicsQueue) {
	this->device = device;

	BMP* bmp = new BMP();
	bmp->Load(path);
	VkDeviceSize imageSize = bmp->GetWidth() * bmp->GetHeight() * (bmp->GetBits() / 8);
	VkBuffer stagingBuffer;
	VkDeviceMemory stagingBufferMemory;
	GvkHelper::create_buffer(phys, device, imageSize, 
		VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, 
		&stagingBuffer, &stagingBufferMemory);
	GvkHelper::write_to_buffer(device, stagingBufferMemory, bmp->GetData(), imageSize);
	this->width = bmp->GetWidth();
	this->height = bmp->GetHeight();
	this->bits = bmp->GetBits();
	VkExtent3D extent = { width, height, 1 };
	
	VkFormat format = VK_FORMAT_R8G8B8A8_SRGB;
	GvkHelper::create_image(phys, device, extent, 1, VK_SAMPLE_COUNT_1_BIT, format, VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, nullptr, &textureImage, &textureImageMemory);
	GvkHelper::transition_image_layout(device, commandPool, graphicsQueue, 1, textureImage, format, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
	GvkHelper::copy_buffer_to_image(device, commandPool, graphicsQueue, stagingBuffer, textureImage, extent);
	GvkHelper::transition_image_layout(device, commandPool, graphicsQueue, 1, textureImage, format, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
	delete bmp;
	vkDestroyBuffer(device, stagingBuffer, nullptr);
	vkFreeMemory(device, stagingBufferMemory, nullptr);

	GvkHelper::create_image_view(device, textureImage, format, VK_IMAGE_ASPECT_COLOR_BIT, 1, nullptr, &textureImageView);

	VkPhysicalDeviceProperties properties;
	vkGetPhysicalDeviceProperties(phys, &properties);
	VkSamplerCreateInfo samplerInfo = { };
	samplerInfo.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
	samplerInfo.magFilter = VK_FILTER_NEAREST;
	samplerInfo.minFilter = VK_FILTER_NEAREST;
	samplerInfo.addressModeU = VK_SAMPLER_ADDRESS_MODE_REPEAT;
	samplerInfo.addressModeV = VK_SAMPLER_ADDRESS_MODE_REPEAT;
	samplerInfo.addressModeW = VK_SAMPLER_ADDRESS_MODE_REPEAT;
	samplerInfo.anisotropyEnable = VK_TRUE;
	samplerInfo.maxAnisotropy = properties.limits.maxSamplerAnisotropy;
	samplerInfo.borderColor = VK_BORDER_COLOR_INT_OPAQUE_BLACK;
	samplerInfo.unnormalizedCoordinates = VK_FALSE;
	samplerInfo.compareEnable = VK_FALSE;
	samplerInfo.compareOp = VK_COMPARE_OP_ALWAYS;
	samplerInfo.mipmapMode = VK_SAMPLER_MIPMAP_MODE_LINEAR;
	vkCreateSampler(device, &samplerInfo, nullptr, &textureSampler);
}

Texture2D::~Texture2D() {
	vkDestroySampler(device, textureSampler, nullptr);
	vkDestroyImageView(device, textureImageView, nullptr);
	vkDestroyImage(device, textureImage, nullptr);
	vkFreeMemory(device, textureImageMemory, nullptr);
}

VkImage Texture2D::GetImage() {
	return textureImage;
}

VkImageView Texture2D::GetImageView() {
	return textureImageView;
}

VkSampler Texture2D::GetSampler() {
	return textureSampler;
}