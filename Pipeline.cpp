#include "Pipeline.h"

Pipeline::Pipeline(VkDevice device, VkRenderPass renderPass, VkViewport viewport, VkRect2D scissor, std::vector<VkVertexInputAttributeDescription> attribs, uint32_t frameCount, StorageBuffer storageBuffer, size_t stride, std::vector<VkPushConstantRange> pushConstantRanges, VkPolygonMode polygonMode, VkPrimitiveTopology topology) {
	this->device = device;
	this->renderPass = renderPass;
	this->viewport = viewport;
	this->scissor = scissor;
	this->attribs = attribs;
	this->frameCount = frameCount;
	this->stride = stride;
	this->storageBuffer = storageBuffer;
	this->pushConstantRanges = pushConstantRanges;
	this->polygonMode = polygonMode;
	this->topology = topology;
}

Pipeline::~Pipeline() {
	vkDestroyDescriptorSetLayout(device, descriptorSetLayout, nullptr);
	vkDestroyDescriptorPool(device, descriptorPool, nullptr);
	vkDestroyPipelineLayout(device, layout, nullptr);
	vkDestroyPipeline(device, pipeline, nullptr);
}

void Pipeline::Create(VkShaderModule vertexShader, VkShaderModule pixelShader, std::string vertexEntry, std::string pixelEntry, Texture2D* diffuse, Texture2D* specular) {
	VkPipelineShaderStageCreateInfo stageCreateInfo[2] = {};
	stageCreateInfo[0].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	stageCreateInfo[0].stage = VK_SHADER_STAGE_VERTEX_BIT;
	stageCreateInfo[0].module = vertexShader;
	stageCreateInfo[0].pName = vertexEntry.c_str();
	
	stageCreateInfo[1].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	stageCreateInfo[1].stage = VK_SHADER_STAGE_FRAGMENT_BIT;
	stageCreateInfo[1].module = pixelShader;
	stageCreateInfo[1].pName = pixelEntry.c_str();

	VkPipelineInputAssemblyStateCreateInfo assemblyCreateInfo = {};
	assemblyCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
	assemblyCreateInfo.topology = topology;
	assemblyCreateInfo.primitiveRestartEnable = false;

	VkVertexInputBindingDescription vertexBindingDescription = {};
	vertexBindingDescription.binding = 0;
	vertexBindingDescription.stride = stride;
	vertexBindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

	VkPipelineVertexInputStateCreateInfo inputVertexInfo = {};
	inputVertexInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
	inputVertexInfo.vertexBindingDescriptionCount = 1;
	inputVertexInfo.pVertexBindingDescriptions = &vertexBindingDescription;
	inputVertexInfo.vertexAttributeDescriptionCount = attribs.size();
	inputVertexInfo.pVertexAttributeDescriptions = attribs.data();

	VkPipelineViewportStateCreateInfo viewportCreateInfo = {};
	viewportCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
	viewportCreateInfo.viewportCount = 1;
	viewportCreateInfo.pViewports = &viewport;
	viewportCreateInfo.scissorCount = 1;
	viewportCreateInfo.pScissors = &scissor;

	VkPipelineRasterizationStateCreateInfo rasterizationCreateInfo = {};
	rasterizationCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
	rasterizationCreateInfo.rasterizerDiscardEnable = VK_FALSE;
	rasterizationCreateInfo.polygonMode = polygonMode;
	rasterizationCreateInfo.lineWidth = 1.0f;
	rasterizationCreateInfo.cullMode = VK_CULL_MODE_BACK_BIT;
	rasterizationCreateInfo.frontFace = VK_FRONT_FACE_CLOCKWISE;
	rasterizationCreateInfo.depthClampEnable = VK_FALSE;
	rasterizationCreateInfo.depthBiasEnable = VK_FALSE;
	rasterizationCreateInfo.depthBiasClamp = 0.0f;
	rasterizationCreateInfo.depthBiasConstantFactor = 0.0f;
	rasterizationCreateInfo.depthBiasSlopeFactor = 0.0f;

	VkPipelineMultisampleStateCreateInfo multisampleCreateInfo = {};
	multisampleCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
	multisampleCreateInfo.sampleShadingEnable = VK_FALSE;
	multisampleCreateInfo.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
	multisampleCreateInfo.minSampleShading = 1.0f;
	multisampleCreateInfo.pSampleMask = VK_NULL_HANDLE;
	multisampleCreateInfo.alphaToCoverageEnable = VK_FALSE;
	multisampleCreateInfo.alphaToOneEnable = VK_FALSE;

	VkPipelineDepthStencilStateCreateInfo depthStencilCreateInfo = {};
	depthStencilCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
	depthStencilCreateInfo.depthTestEnable = VK_TRUE;
	depthStencilCreateInfo.depthWriteEnable = VK_TRUE;
	depthStencilCreateInfo.depthCompareOp = VK_COMPARE_OP_LESS;
	depthStencilCreateInfo.depthBoundsTestEnable = VK_FALSE;
	depthStencilCreateInfo.minDepthBounds = 0.0f;
	depthStencilCreateInfo.maxDepthBounds = 1.0f;
	depthStencilCreateInfo.stencilTestEnable = VK_FALSE;

	VkPipelineColorBlendAttachmentState colorBlendAttachmentState = {};
	colorBlendAttachmentState.colorWriteMask = 0xF;
	colorBlendAttachmentState.blendEnable = VK_FALSE;
	colorBlendAttachmentState.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_COLOR;
	colorBlendAttachmentState.dstColorBlendFactor = VK_BLEND_FACTOR_DST_COLOR;
	colorBlendAttachmentState.colorBlendOp = VK_BLEND_OP_ADD;
	colorBlendAttachmentState.srcAlphaBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
	colorBlendAttachmentState.dstAlphaBlendFactor = VK_BLEND_FACTOR_DST_ALPHA;
	colorBlendAttachmentState.alphaBlendOp = VK_BLEND_OP_ADD;

	VkPipelineColorBlendStateCreateInfo colorBlendCreateInfo = {};
	colorBlendCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
	colorBlendCreateInfo.logicOpEnable = VK_FALSE;
	colorBlendCreateInfo.logicOp = VK_LOGIC_OP_COPY;
	colorBlendCreateInfo.attachmentCount = 1;
	colorBlendCreateInfo.pAttachments = &colorBlendAttachmentState;
	colorBlendCreateInfo.blendConstants[0] = 0.0f;
	colorBlendCreateInfo.blendConstants[1] = 0.0f;
	colorBlendCreateInfo.blendConstants[2] = 0.0f;
	colorBlendCreateInfo.blendConstants[3] = 0.0f;

	VkDynamicState dynamicState[2] = {
		VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR
	};
	VkPipelineDynamicStateCreateInfo dynamicCreateInfo = {};
	dynamicCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
	dynamicCreateInfo.dynamicStateCount = 2;
	dynamicCreateInfo.pDynamicStates = dynamicState;
	size_t descriptorSize = 1;
	if (diffuse)
		descriptorSize++;
	if (specular)
		descriptorSize++;

	std::vector<VkDescriptorSetLayoutBinding> descriptorSetLayoutBindings;
	descriptorSetLayoutBindings.resize(descriptorSize);
	descriptorSetLayoutBindings[0].binding = 0;
	descriptorSetLayoutBindings[0].descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
	descriptorSetLayoutBindings[0].descriptorCount = 1;
	descriptorSetLayoutBindings[0].stageFlags = VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
	
	if (diffuse) {
		descriptorSetLayoutBindings[1].binding = 1;
		descriptorSetLayoutBindings[1].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		descriptorSetLayoutBindings[1].descriptorCount = 1;
		descriptorSetLayoutBindings[1].stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
	}

	if (specular) {
		int index = 2;
		if (!diffuse)
			index = 1;
		descriptorSetLayoutBindings[index].binding = index;
		descriptorSetLayoutBindings[index].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		descriptorSetLayoutBindings[index].descriptorCount = 1;
		descriptorSetLayoutBindings[index].stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
	}

	VkDescriptorSetLayoutCreateInfo descriptorSetLayoutCreate = {};
	descriptorSetLayoutCreate.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
	descriptorSetLayoutCreate.bindingCount = descriptorSetLayoutBindings.size();
	descriptorSetLayoutCreate.pBindings = &descriptorSetLayoutBindings[0];
	vkCreateDescriptorSetLayout(device, &descriptorSetLayoutCreate, nullptr, &descriptorSetLayout);

	std::vector<VkDescriptorPoolSize> poolSizes;
	poolSizes.resize(descriptorSize);
	poolSizes[0].type = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
	poolSizes[0].descriptorCount = frameCount;
	if(diffuse) {
		poolSizes[1].type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		poolSizes[1].descriptorCount = frameCount;
	}

	if (specular) {
		int index = 2;
		if (!diffuse)
			index = 1;
		poolSizes[index].type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		poolSizes[index].descriptorCount = frameCount;
	}

	VkDescriptorPoolCreateInfo descriptorPoolCreate = {};
	descriptorPoolCreate.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
	descriptorPoolCreate.poolSizeCount = poolSizes.size();
	descriptorPoolCreate.pPoolSizes = &poolSizes[0];
	descriptorPoolCreate.maxSets = frameCount;
	vkCreateDescriptorPool(device, &descriptorPoolCreate, nullptr, &descriptorPool);

	descriptorSets.resize(frameCount);
	for (int i = 0; i < frameCount; i++) {
		VkDescriptorSetAllocateInfo allocateInfo = { };
		allocateInfo.descriptorPool = descriptorPool;
		allocateInfo.descriptorSetCount = 1;
		allocateInfo.pSetLayouts = &descriptorSetLayout;
		allocateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
		vkAllocateDescriptorSets(device, &allocateInfo, &descriptorSets[i]);

		VkDescriptorBufferInfo descriptorBufferInfo = {};
		descriptorBufferInfo.buffer = storageBuffer.buffer;
		descriptorBufferInfo.offset = 0;
		descriptorBufferInfo.range = storageBuffer.size;

		std::vector<VkWriteDescriptorSet> writeDescriptorSets;
		writeDescriptorSets.resize(descriptorSize);
		writeDescriptorSets[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		writeDescriptorSets[0].dstSet = descriptorSets[i];
		writeDescriptorSets[0].dstBinding = 0;
		writeDescriptorSets[0].dstArrayElement = 0;
		writeDescriptorSets[0].descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
		writeDescriptorSets[0].descriptorCount = 1;
		writeDescriptorSets[0].pBufferInfo = &descriptorBufferInfo;

		if(diffuse) {
			VkDescriptorImageInfo imageInfo;
			imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
			imageInfo.imageView = diffuse->GetImageView();
			imageInfo.sampler = diffuse->GetSampler();

			writeDescriptorSets[1].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
			writeDescriptorSets[1].dstSet = descriptorSets[i];
			writeDescriptorSets[1].dstBinding = 1;
			writeDescriptorSets[1].dstArrayElement = 0;
			writeDescriptorSets[1].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
			writeDescriptorSets[1].descriptorCount = 1;
			writeDescriptorSets[1].pImageInfo = &imageInfo;
		}

		if (specular) {
			int index = 2;
			if (!diffuse)
				index = 1;
			VkDescriptorImageInfo imageInfo;
			imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
			imageInfo.imageView = diffuse->GetImageView();
			imageInfo.sampler = diffuse->GetSampler();

			writeDescriptorSets[index].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
			writeDescriptorSets[index].dstSet = descriptorSets[i];
			writeDescriptorSets[index].dstBinding = index;
			writeDescriptorSets[index].dstArrayElement = 0;
			writeDescriptorSets[index].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
			writeDescriptorSets[index].descriptorCount = 1;
			writeDescriptorSets[index].pImageInfo = &imageInfo;
		}
		
		vkUpdateDescriptorSets(device, writeDescriptorSets.size(), &writeDescriptorSets[0], 0, nullptr);
	}

	VkPipelineLayoutCreateInfo pipelineLayoutCreateInfo = {};
	pipelineLayoutCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
	pipelineLayoutCreateInfo.setLayoutCount = 1;
	pipelineLayoutCreateInfo.pSetLayouts = &descriptorSetLayout;
	pipelineLayoutCreateInfo.pushConstantRangeCount = pushConstantRanges.size();
	pipelineLayoutCreateInfo.pPushConstantRanges = &pushConstantRanges[0];
	vkCreatePipelineLayout(device, &pipelineLayoutCreateInfo, nullptr, &layout);

	VkGraphicsPipelineCreateInfo pipelineCreateInfo = {};
	pipelineCreateInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
	pipelineCreateInfo.stageCount = 2;
	pipelineCreateInfo.pStages = stageCreateInfo;
	pipelineCreateInfo.pInputAssemblyState = &assemblyCreateInfo;
	pipelineCreateInfo.pVertexInputState = &inputVertexInfo;
	pipelineCreateInfo.pViewportState = &viewportCreateInfo;
	pipelineCreateInfo.pRasterizationState = &rasterizationCreateInfo;
	pipelineCreateInfo.pMultisampleState = &multisampleCreateInfo;
	pipelineCreateInfo.pDepthStencilState = &depthStencilCreateInfo;
	pipelineCreateInfo.pColorBlendState = &colorBlendCreateInfo;
	pipelineCreateInfo.pDynamicState = &dynamicCreateInfo;
	pipelineCreateInfo.layout = layout;
	pipelineCreateInfo.renderPass = renderPass;
	pipelineCreateInfo.subpass = 0;
	pipelineCreateInfo.basePipelineHandle = VK_NULL_HANDLE;
	vkCreateGraphicsPipelines(device, VK_NULL_HANDLE, 1, &pipelineCreateInfo, nullptr, &pipeline);
}

void Pipeline::Bind(VkCommandBuffer commandBuffer, VkViewport viewport, VkRect2D scissor) {
	this->viewport = viewport;
	this->scissor = scissor;
	vkCmdSetViewport(commandBuffer, 0, 1, &viewport);
	vkCmdSetScissor(commandBuffer, 0, 1, &scissor);
	vkCmdBindPipeline(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline);
}

void Pipeline::SetTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology topology) {
	this->topology = topology;
	vkCmdSetPrimitiveTopology(commandBuffer, topology);
}

void Pipeline::PushConstant(VkCommandBuffer commandBuffer, uint32_t rangeIndex, void* block) {
	VkPushConstantRange range = pushConstantRanges[rangeIndex];
	vkCmdPushConstants(commandBuffer, layout, range.stageFlags, range.offset, range.size, block);
}

void Pipeline::BindDescriptors(VkCommandBuffer commandBuffer) {
	for (size_t i = 0; i < descriptorSets.size(); i++) {
		vkCmdBindDescriptorSets(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, layout, 0, 1, &descriptorSets[i], 0, nullptr);
	}
}

VkPipelineLayout Pipeline::GetLayout() {
	return layout;
}