#include "BMPLoader.h"
#include "FileHelper.h"

BMP::BMP() {
}

BMP::BMP(int32_t width, int32_t height, uint16_t bits) {
	imageHeader.width = width;
	imageHeader.height = height;
	imageHeader.bits = bits;
	std::malloc(width * height * (bits / 8));
}

BMP::~BMP() {
	std::free(pixels);
}

void BMP::Load(std::string path) {
	std::vector<uint8_t> imageData;
	FileHelper::LoadFile<std::vector<uint8_t>>(imageData, path);
	uint8_t* ptr = &imageData[0];

	memcpy(&header, ptr, sizeof(bmp_header_t));
	ptr += sizeof(bmp_header_t);
	memcpy(&imageHeader, ptr, sizeof(bmp_image_header_t));
	ptr += sizeof(bmp_image_header_t);

	if (imageHeader.bits <= 8) {
		uint8_t* colorPtr = (uint8_t*)&colors;
		unsigned colorBlockLength = sizeof(uint32_t) * 0xFF;
		memcpy(colorPtr, ptr, colorBlockLength);
		ptr += colorBlockLength;
	}

	ptr = imageData.data() + header.offset;
	size_t imageSize = imageHeader.width * imageHeader.height * (imageHeader.bits / 8);
	this->imageHeader.imageSize = imageSize;
	pixels = std::malloc(imageSize);
	memcpy(pixels, ptr, imageSize);
}

int32_t BMP::GetWidth() const {
	return imageHeader.width;
}

int32_t BMP::GetHeight() const {
	return imageHeader.height;
}

uint16_t BMP::GetBits() const {
	return imageHeader.bits;
}

void* BMP::GetData() {
	return pixels;
}

void BMP::SetPixel(int x, int y, uint32_t pixel) {
	static_cast<uint32_t*>(pixels)[y * imageHeader.width + x] = pixel;
}