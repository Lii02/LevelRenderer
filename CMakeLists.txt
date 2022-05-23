cmake_minimum_required(VERSION 3.10)

project(LevelRenderer)

ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)
ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)

if (WIN32)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MD")
	file(GLOB_RECURSE SRCS *.cpp)
	file(GLOB_RECURSE HDRS *.h)
	file(GLOB_RECURSE SHDRS *.hlsl *.glsl)
	add_executable(LevelRenderer ${SRCS} ${HDRS} ${SHDRS})
	target_include_directories(LevelRenderer PUBLIC $ENV{VULKAN_SDK}/Include/)
	target_link_directories(LevelRenderer PUBLIC $ENV{VULKAN_SDK}/Lib/)
	set_source_files_properties(${SHDRS} PROPERTIES
        VS_SHADER_TYPE Vertex 
        VS_SHADER_MODEL 5.0
        VS_SHADER_ENTRYPOINT VS
        VS_TOOL_OVERRIDE "None")
	set_source_files_properties(${SHDRS} PROPERTIES
        VS_SHADER_TYPE Pixel
        VS_SHADER_MODEL 5.0
        VS_SHADER_ENTRYPOINT PS
        VS_TOOL_OVERRIDE "None")
endif(WIN32)
