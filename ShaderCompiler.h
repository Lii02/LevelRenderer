#ifndef SHADERCOMPILER_H
#define SHADERCOMPILER_H
#include "shaderc/shaderc.h"
#include <vulkan/vulkan.h>
#include <string>

enum class ShaderLanguage {
	GLSL = 0,
	HLSL = 1
};

struct ShaderCompilerResult {
	VkShaderModule vertexShader;
	VkShaderModule pixelShader;
};

class ShaderCompiler {
private:
	bool invertY;
	ShaderLanguage language;
	shaderc_compiler_t compiler;
	shaderc_compile_options_t options;
public:
	ShaderCompiler(ShaderLanguage language = ShaderLanguage::HLSL, bool invertY = false);
	~ShaderCompiler();

	bool Compile(VkDevice device, const std::string& shaderSource, std::string vertexEntry, std::string pixelEntry, ShaderCompilerResult& output);
};

#endif