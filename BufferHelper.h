#ifndef BUFFER_HELPER_H
#define BUFFER_HELPER_H

namespace BufferHelper {
	void WriteToBuffer(const VkDevice& device, VkDeviceMemory& memory, void* data_to_write, unsigned int num_bytes, unsigned int offset = 0) {
		void* data;
		VkResult result = vkMapMemory(device, memory, offset, num_bytes, 0, &data);
		if (!data)
			return;
		
		memcpy(data, data_to_write, num_bytes);
		vkUnmapMemory(device, memory);
	}
}

#endif