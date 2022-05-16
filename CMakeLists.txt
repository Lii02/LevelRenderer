cmake_minimum_required(VERSION 3.10)

project(LevelRenderer)

ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)
ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)

if (WIN32)
	file(GLOB_RECURSE SRCS *.cpp)
	file(GLOB_RECURSE HDRS *.h)
	file(GLOB_RECURSE SHDRS *.hlsl)
	add_executable(LevelRenderer ${SRCS} ${HDRS} ${SHDRS})
	target_include_directories(LevelRenderer PUBLIC $ENV{VULKAN_SDK}/Include/)
	target_link_directories(LevelRenderer PUBLIC $ENV{VULKAN_SDK}/Lib/)
endif(WIN32)
