#ifndef BMP_LOADER_H
#define BMP_LOADER_H
#include <cstdint>
#include <string>

#pragma pack(push, 1)
struct bmp_header_t {
	int16_t type;
	uint32_t filesize;
	int32_t reserved;
	uint32_t offset;
};

struct bmp_image_header_t {
	uint32_t headerSize;
	int32_t width;
	int32_t height;
	uint16_t planes;
	uint16_t bits;
	uint32_t compression;
	uint32_t imageSize;
	int32_t xppm;
	int32_t yppm;
	uint32_t totalColors;
	uint32_t importantColors;
};
#pragma pack(pop)

#define BMP_PALETTE_SIZE 0xFF

class BMP {
private:
	bmp_header_t header;
	bmp_image_header_t imageHeader;
	uint32_t colors[BMP_PALETTE_SIZE];
	void* pixels;
public:
	BMP();
	BMP(int32_t width, int32_t height, uint16_t bits);
	~BMP();

	void Load(std::string path);
	int32_t GetWidth() const;
	int32_t GetHeight() const;
	uint16_t GetBits() const;
	void* GetData();
	void SetPixel(int x, int y, uint32_t pixel);
};

#endif