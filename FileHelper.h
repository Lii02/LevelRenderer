#ifndef FILEHELPER_H
#define FILEHELPER_H
#include <string>
#include <vector>
#include <cstdint>
#include <fstream>

typedef std::vector<uint8_t> ByteBuffer;

namespace FileHelper {
	template <typename T = std::string>
	bool LoadFile(T& buffer, std::string path) {
		std::ifstream stream(path, std::ios::in);
		if (!stream.is_open())
			return false;
		stream.seekg(0, stream.end);
		std::string str;
		buffer.resize(stream.tellg(), ' ');
		stream.seekg(0, stream.beg);
		stream.read((char*)&buffer[0], buffer.size());
		stream.close();
		return true;
	}
}

#endif