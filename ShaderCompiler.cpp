#include "ShaderCompiler.h"
#define GATEWARE_DISABLE_GDIRECTX11SURFACE
#define GATEWARE_DISABLE_GDIRECTX12SURFACE
#define GATEWARE_DISABLE_GRASTERSURFACE
#define GATEWARE_DISABLE_GOPENGLSURFACE
#define GATEWARE_ENABLE_GRAPHICS
#include "Gateware.h"

using namespace GW;

ShaderCompiler::ShaderCompiler(ShaderLanguage language, bool invertY) {
	this->language = language;
	this->invertY = invertY;
	this->compiler = shaderc_compiler_initialize();
	this->options = shaderc_compile_options_initialize();

	shaderc_compile_options_set_source_language(options, static_cast<shaderc_source_language>(language));
	shaderc_compile_options_set_invert_y(options, invertY);
#ifndef NDEBUG
	shaderc_compile_options_set_generate_debug_info(options);
#endif
}

ShaderCompiler::~ShaderCompiler() {
	shaderc_compile_options_release(options);
	shaderc_compiler_release(compiler);
}

bool ShaderCompiler::Compile(VkDevice device, const std::string& shaderSource, std::string vertexEntry, std::string pixelEntry, ShaderCompilerResult& output) {
	shaderc_compilation_result_t result;

	result = shaderc_compile_into_spv(compiler, shaderSource.c_str(), shaderSource.length(), shaderc_vertex_shader, "", vertexEntry.c_str(), options);
	bool vertexShaderStatus = true;
	if (shaderc_result_get_compilation_status(result) != shaderc_compilation_status_success) {
		std::cout << shaderc_result_get_error_message(result) << std::endl;
		vertexShaderStatus = false;
	}
	GvkHelper::create_shader_module(device, shaderc_result_get_length(result), (char*)shaderc_result_get_bytes(result), &output.vertexShader);
	shaderc_result_release(result);

	result = shaderc_compile_into_spv(compiler, shaderSource.c_str(), shaderSource.length(), shaderc_fragment_shader, "", pixelEntry.c_str(), options);
	bool pixelShaderStatus = true;
	if (shaderc_result_get_compilation_status(result) != shaderc_compilation_status_success) {
		std::cout << shaderc_result_get_error_message(result) << std::endl;
		pixelShaderStatus = false;
	}
	GvkHelper::create_shader_module(device, shaderc_result_get_length(result), (char*)shaderc_result_get_bytes(result), &output.pixelShader);
	shaderc_result_release(result);
	
	return vertexShaderStatus && pixelShaderStatus;
}