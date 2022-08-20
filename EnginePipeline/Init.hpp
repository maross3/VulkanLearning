#pragma once

#include <vector>
#include "vulkan/vulkan.hpp"

namespace initializers
{

	struct VulkanInfoStore 
	{
		VkMemoryAllocateInfo memAllocInfo;
		VkPipelineLayoutCreateInfo pipelineLayoutCreateInfo;
		VkMappedMemoryRange mappedMemoryRange;
		VkCommandBufferAllocateInfo commandBufferAllocateInfo;
		VkCommandPoolCreateInfo cmdPoolCreateInfo;
		VkCommandBufferBeginInfo cmdBufferBeginInfo;
		VkCommandBufferInheritanceInfo cmdBufferInheritanceInfo;
		VkRenderPassCreateInfo renderPassCreateInfo;
		VkImageViewCreateInfo imageViewCreateInfo;
		VkFramebufferCreateInfo framebufferCreateInfo; 
		VkBufferCreateInfo bufCreateInfo;
		VkViewport viewport;
		VkSubmitInfo submitInfo;
		VkEventCreateInfo eventCreateInfo;
		VkFenceCreateInfo fenceCreateInfo;
		VkSemaphoreCreateInfo semaphoreCreateInfo;
		VkSamplerCreateInfo samplerCreateInfo;
		VkImageCreateInfo imageCreateInfo;
		VkMemoryBarrier memoryBarrier;
		VkBufferMemoryBarrier bufferMemoryBarrier;
		VkImageMemoryBarrier imageMemoryBarrier;
		VkRenderPassBeginInfo renderPassBeginInfo;
	};
	inline VulkanInfoStore vulkanInfoStore{};

	inline VkMemoryAllocateInfo CreateMemoryAllocateInfo()
	{
		vulkanInfoStore.memAllocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
		return vulkanInfoStore.memAllocInfo;
	}

	inline VkMappedMemoryRange CreateMappedMemoryRange()
	{
		vulkanInfoStore.mappedMemoryRange.sType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE;
		return vulkanInfoStore.mappedMemoryRange;
	}

	inline VkCommandBufferAllocateInfo CreateCommandBufferAllocateInfo(
		VkCommandPool commandPool,
		VkCommandBufferLevel level,
		uint32_t bufferCount)
	{
		vulkanInfoStore.commandBufferAllocateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		vulkanInfoStore.commandBufferAllocateInfo.commandPool = commandPool;
		vulkanInfoStore.commandBufferAllocateInfo.level = level;
		vulkanInfoStore.commandBufferAllocateInfo.commandBufferCount = bufferCount;
		return vulkanInfoStore.commandBufferAllocateInfo;
	}

	inline VkCommandPoolCreateInfo CreateCommandPoolCreateInfo()
	{
		vulkanInfoStore.cmdPoolCreateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
		return vulkanInfoStore.cmdPoolCreateInfo;
	}

	inline VkCommandBufferBeginInfo CreateCommandBufferBeginInfo()
	{
		vulkanInfoStore.cmdBufferBeginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
		return vulkanInfoStore.cmdBufferBeginInfo;
	}

	inline VkCommandBufferInheritanceInfo CreateCommandBufferInheritanceInfo()
	{
		vulkanInfoStore.cmdBufferInheritanceInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO;
		return vulkanInfoStore.cmdBufferInheritanceInfo;
	}

	inline VkRenderPassBeginInfo CreateRenderPassBeginInfo()
	{
		vulkanInfoStore.renderPassBeginInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
		return vulkanInfoStore.renderPassBeginInfo;
	}

	inline VkRenderPassCreateInfo CreateRenderPassCreateInfo()
	{
		vulkanInfoStore.renderPassCreateInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
		return vulkanInfoStore.renderPassCreateInfo;
	}

	/** @brief Initialize an image memory barrier with no image transfer ownership */
	inline VkImageMemoryBarrier CreateImageMemoryBarrier()
	{
		vulkanInfoStore.imageMemoryBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
		vulkanInfoStore.imageMemoryBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
		vulkanInfoStore.imageMemoryBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
		return vulkanInfoStore.imageMemoryBarrier;
	}

	/** @brief Initialize a buffer memory barrier with no image transfer ownership */
	inline VkBufferMemoryBarrier CreateBufferMemoryBarrier()
	{
		vulkanInfoStore.bufferMemoryBarrier.sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
		vulkanInfoStore.bufferMemoryBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
		vulkanInfoStore.bufferMemoryBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
		return vulkanInfoStore.bufferMemoryBarrier;
	}

	inline VkMemoryBarrier CreateMemoryBarrier()
	{
		vulkanInfoStore.memoryBarrier.sType = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
		return vulkanInfoStore.memoryBarrier;
	}

	inline VkImageCreateInfo CreateImageCreateInfo()
	{
		vulkanInfoStore.imageCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
		return vulkanInfoStore.imageCreateInfo;
	}

	inline VkSamplerCreateInfo CreateSamplerCreateInfo()
	{
		vulkanInfoStore.samplerCreateInfo.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
		vulkanInfoStore.samplerCreateInfo.maxAnisotropy = 1.0f;
		return vulkanInfoStore.samplerCreateInfo;
	}

	inline VkImageViewCreateInfo CreateImageViewCreateInfo()
	{
		vulkanInfoStore.imageViewCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
		return vulkanInfoStore.imageViewCreateInfo;
	}

	inline VkFramebufferCreateInfo CreateFramebufferCreateInfo()
	{
		vulkanInfoStore.framebufferCreateInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
		return vulkanInfoStore.framebufferCreateInfo;
	}

	inline VkSemaphoreCreateInfo CreateSemaphoreCreateInfo()
	{
		vulkanInfoStore.semaphoreCreateInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
		return vulkanInfoStore.semaphoreCreateInfo;
	}

	inline VkFenceCreateInfo CreateFenceCreateInfo(VkFenceCreateFlags flags = 0)
	{
		vulkanInfoStore.fenceCreateInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
		vulkanInfoStore.fenceCreateInfo.flags = flags;
		return vulkanInfoStore.fenceCreateInfo;
	}

	inline VkEventCreateInfo CreateEventCreateInfo()
	{
		vulkanInfoStore.eventCreateInfo.sType = VK_STRUCTURE_TYPE_EVENT_CREATE_INFO;
		return vulkanInfoStore.eventCreateInfo;
	}

	inline VkSubmitInfo CreateSubmitInfo()
	{
		vulkanInfoStore.submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		return vulkanInfoStore.submitInfo;
	}

	inline VkViewport CreateViewport(
		float width,
		float height,
		float minDepth,
		float maxDepth)
	{
		vulkanInfoStore.viewport.width = width;
		vulkanInfoStore.viewport.height = height;
		vulkanInfoStore.viewport.minDepth = minDepth;
		vulkanInfoStore.viewport.maxDepth = maxDepth;
		return vulkanInfoStore.viewport;
	}

	inline VkRect2D CreateRect2D(
		int32_t width,
		int32_t height,
		int32_t offsetX,
		int32_t offsetY)
	{
		VkRect2D rect2D{};
		rect2D.extent.width = width;
		rect2D.extent.height = height;
		rect2D.offset.x = offsetX;
		rect2D.offset.y = offsetY;
		return rect2D;
	}

	inline VkBufferCreateInfo CreateBufferCreateInfo()
	{
		vulkanInfoStore.bufCreateInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		return vulkanInfoStore.bufCreateInfo;
	}

	inline VkBufferCreateInfo CreateBufferCreateInfo(
		VkBufferUsageFlags usage,
		VkDeviceSize size)
	{
		vulkanInfoStore.bufCreateInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		vulkanInfoStore.bufCreateInfo.usage = usage;
		vulkanInfoStore.bufCreateInfo.size = size;
		return vulkanInfoStore.bufCreateInfo;
	}

	inline VkDescriptorPoolCreateInfo descriptorPoolCreateInfo(
		uint32_t poolSizeCount,
		VkDescriptorPoolSize* pPoolSizes,
		uint32_t maxSets)
	{
		VkDescriptorPoolCreateInfo descriptorPoolInfo{};
		descriptorPoolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
		descriptorPoolInfo.poolSizeCount = poolSizeCount;
		descriptorPoolInfo.pPoolSizes = pPoolSizes;
		descriptorPoolInfo.maxSets = maxSets;
		return descriptorPoolInfo;
	}

	inline VkDescriptorPoolCreateInfo descriptorPoolCreateInfo(
		const std::vector<VkDescriptorPoolSize>& poolSizes,
		uint32_t maxSets)
	{
		VkDescriptorPoolCreateInfo descriptorPoolInfo{};
		descriptorPoolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
		descriptorPoolInfo.poolSizeCount = static_cast<uint32_t>(poolSizes.size());
		descriptorPoolInfo.pPoolSizes = poolSizes.data();
		descriptorPoolInfo.maxSets = maxSets;
		return descriptorPoolInfo;
	}

	inline VkDescriptorPoolSize descriptorPoolSize(
		VkDescriptorType type,
		uint32_t descriptorCount)
	{
		VkDescriptorPoolSize descriptorPoolSize{};
		descriptorPoolSize.type = type;
		descriptorPoolSize.descriptorCount = descriptorCount;
		return descriptorPoolSize;
	}

	inline VkDescriptorSetLayoutBinding descriptorSetLayoutBinding(
		VkDescriptorType type,
		VkShaderStageFlags stageFlags,
		uint32_t binding,
		uint32_t descriptorCount = 1)
	{
		VkDescriptorSetLayoutBinding setLayoutBinding{};
		setLayoutBinding.descriptorType = type;
		setLayoutBinding.stageFlags = stageFlags;
		setLayoutBinding.binding = binding;
		setLayoutBinding.descriptorCount = descriptorCount;
		return setLayoutBinding;
	}

	inline VkDescriptorSetLayoutCreateInfo descriptorSetLayoutCreateInfo(
		const VkDescriptorSetLayoutBinding* pBindings,
		uint32_t bindingCount)
	{
		VkDescriptorSetLayoutCreateInfo descriptorSetLayoutCreateInfo{};
		descriptorSetLayoutCreateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
		descriptorSetLayoutCreateInfo.pBindings = pBindings;
		descriptorSetLayoutCreateInfo.bindingCount = bindingCount;
		return descriptorSetLayoutCreateInfo;
	}

	inline VkDescriptorSetLayoutCreateInfo descriptorSetLayoutCreateInfo(
		const std::vector<VkDescriptorSetLayoutBinding>& bindings)
	{
		VkDescriptorSetLayoutCreateInfo descriptorSetLayoutCreateInfo{};
		descriptorSetLayoutCreateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
		descriptorSetLayoutCreateInfo.pBindings = bindings.data();
		descriptorSetLayoutCreateInfo.bindingCount = static_cast<uint32_t>(bindings.size());
		return descriptorSetLayoutCreateInfo;
	}

	inline VkPipelineLayoutCreateInfo CreatePipelineLayoutCreateInfo(
		const VkDescriptorSetLayout* pSetLayouts,
		uint32_t setLayoutCount = 1)
	{
		vulkanInfoStore.pipelineLayoutCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		vulkanInfoStore.pipelineLayoutCreateInfo.setLayoutCount = setLayoutCount;
		vulkanInfoStore.pipelineLayoutCreateInfo.pSetLayouts = pSetLayouts;
		return vulkanInfoStore.pipelineLayoutCreateInfo;
	}

	inline VkPipelineLayoutCreateInfo CreatePipelineLayoutCreateInfo(
		uint32_t setLayoutCount = 1)
	{
		vulkanInfoStore.pipelineLayoutCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		vulkanInfoStore.pipelineLayoutCreateInfo.setLayoutCount = setLayoutCount;
		return vulkanInfoStore.pipelineLayoutCreateInfo;
	}

	inline VkDescriptorSetAllocateInfo descriptorSetAllocateInfo(
		VkDescriptorPool descriptorPool,
		const VkDescriptorSetLayout* pSetLayouts,
		uint32_t descriptorSetCount)
	{
		VkDescriptorSetAllocateInfo descriptorSetAllocateInfo{};
		descriptorSetAllocateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
		descriptorSetAllocateInfo.descriptorPool = descriptorPool;
		descriptorSetAllocateInfo.pSetLayouts = pSetLayouts;
		descriptorSetAllocateInfo.descriptorSetCount = descriptorSetCount;
		return descriptorSetAllocateInfo;
	}

	inline VkDescriptorImageInfo descriptorImageInfo(VkSampler sampler, VkImageView imageView, VkImageLayout imageLayout)
	{
		VkDescriptorImageInfo descriptorImageInfo{};
		descriptorImageInfo.sampler = sampler;
		descriptorImageInfo.imageView = imageView;
		descriptorImageInfo.imageLayout = imageLayout;
		return descriptorImageInfo;
	}

	inline VkWriteDescriptorSet writeDescriptorSet(
		VkDescriptorSet dstSet,
		VkDescriptorType type,
		uint32_t binding,
		VkDescriptorBufferInfo* bufferInfo,
		uint32_t descriptorCount = 1)
	{
		VkWriteDescriptorSet writeDescriptorSet{};
		writeDescriptorSet.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		writeDescriptorSet.dstSet = dstSet;
		writeDescriptorSet.descriptorType = type;
		writeDescriptorSet.dstBinding = binding;
		writeDescriptorSet.pBufferInfo = bufferInfo;
		writeDescriptorSet.descriptorCount = descriptorCount;
		return writeDescriptorSet;
	}

	inline VkWriteDescriptorSet writeDescriptorSet(
		VkDescriptorSet dstSet,
		VkDescriptorType type,
		uint32_t binding,
		VkDescriptorImageInfo* imageInfo,
		uint32_t descriptorCount = 1)
	{
		VkWriteDescriptorSet writeDescriptorSet{};
		writeDescriptorSet.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		writeDescriptorSet.dstSet = dstSet;
		writeDescriptorSet.descriptorType = type;
		writeDescriptorSet.dstBinding = binding;
		writeDescriptorSet.pImageInfo = imageInfo;
		writeDescriptorSet.descriptorCount = descriptorCount;
		return writeDescriptorSet;
	}

	inline VkVertexInputBindingDescription vertexInputBindingDescription(
		uint32_t binding,
		uint32_t stride,
		VkVertexInputRate inputRate)
	{
		VkVertexInputBindingDescription vInputBindDescription{};
		vInputBindDescription.binding = binding;
		vInputBindDescription.stride = stride;
		vInputBindDescription.inputRate = inputRate;
		return vInputBindDescription;
	}

	inline VkVertexInputAttributeDescription vertexInputAttributeDescription(
		uint32_t binding,
		uint32_t location,
		VkFormat format,
		uint32_t offset)
	{
		VkVertexInputAttributeDescription vInputAttribDescription{};
		vInputAttribDescription.location = location;
		vInputAttribDescription.binding = binding;
		vInputAttribDescription.format = format;
		vInputAttribDescription.offset = offset;
		return vInputAttribDescription;
	}

	inline VkPipelineVertexInputStateCreateInfo pipelineVertexInputStateCreateInfo()
	{
		VkPipelineVertexInputStateCreateInfo pipelineVertexInputStateCreateInfo{};
		pipelineVertexInputStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
		return pipelineVertexInputStateCreateInfo;
	}

	inline VkPipelineVertexInputStateCreateInfo pipelineVertexInputStateCreateInfo(
		const std::vector<VkVertexInputBindingDescription>& vertexBindingDescriptions,
		const std::vector<VkVertexInputAttributeDescription>& vertexAttributeDescriptions
	)
	{
		VkPipelineVertexInputStateCreateInfo pipelineVertexInputStateCreateInfo{};
		pipelineVertexInputStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
		pipelineVertexInputStateCreateInfo.vertexBindingDescriptionCount = static_cast<uint32_t>(vertexBindingDescriptions.size());
		pipelineVertexInputStateCreateInfo.pVertexBindingDescriptions = vertexBindingDescriptions.data();
		pipelineVertexInputStateCreateInfo.vertexAttributeDescriptionCount = static_cast<uint32_t>(vertexAttributeDescriptions.size());
		pipelineVertexInputStateCreateInfo.pVertexAttributeDescriptions = vertexAttributeDescriptions.data();
		return pipelineVertexInputStateCreateInfo;
	}

	inline VkPipelineInputAssemblyStateCreateInfo pipelineInputAssemblyStateCreateInfo(
		VkPrimitiveTopology topology,
		VkPipelineInputAssemblyStateCreateFlags flags,
		VkBool32 primitiveRestartEnable)
	{
		VkPipelineInputAssemblyStateCreateInfo pipelineInputAssemblyStateCreateInfo{};
		pipelineInputAssemblyStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		pipelineInputAssemblyStateCreateInfo.topology = topology;
		pipelineInputAssemblyStateCreateInfo.flags = flags;
		pipelineInputAssemblyStateCreateInfo.primitiveRestartEnable = primitiveRestartEnable;
		return pipelineInputAssemblyStateCreateInfo;
	}

	inline VkPipelineRasterizationStateCreateInfo pipelineRasterizationStateCreateInfo(
		VkPolygonMode polygonMode,
		VkCullModeFlags cullMode,
		VkFrontFace frontFace,
		VkPipelineRasterizationStateCreateFlags flags = 0)
	{
		VkPipelineRasterizationStateCreateInfo pipelineRasterizationStateCreateInfo{};
		pipelineRasterizationStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
		pipelineRasterizationStateCreateInfo.polygonMode = polygonMode;
		pipelineRasterizationStateCreateInfo.cullMode = cullMode;
		pipelineRasterizationStateCreateInfo.frontFace = frontFace;
		pipelineRasterizationStateCreateInfo.flags = flags;
		pipelineRasterizationStateCreateInfo.depthClampEnable = VK_FALSE;
		pipelineRasterizationStateCreateInfo.lineWidth = 1.0f;
		return pipelineRasterizationStateCreateInfo;
	}

	inline VkPipelineColorBlendAttachmentState pipelineColorBlendAttachmentState(
		VkColorComponentFlags colorWriteMask,
		VkBool32 blendEnable)
	{
		VkPipelineColorBlendAttachmentState pipelineColorBlendAttachmentState{};
		pipelineColorBlendAttachmentState.colorWriteMask = colorWriteMask;
		pipelineColorBlendAttachmentState.blendEnable = blendEnable;
		return pipelineColorBlendAttachmentState;
	}

	inline VkPipelineColorBlendStateCreateInfo pipelineColorBlendStateCreateInfo(
		uint32_t attachmentCount,
		const VkPipelineColorBlendAttachmentState* pAttachments)
	{
		VkPipelineColorBlendStateCreateInfo pipelineColorBlendStateCreateInfo{};
		pipelineColorBlendStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
		pipelineColorBlendStateCreateInfo.attachmentCount = attachmentCount;
		pipelineColorBlendStateCreateInfo.pAttachments = pAttachments;
		return pipelineColorBlendStateCreateInfo;
	}

	inline VkPipelineDepthStencilStateCreateInfo pipelineDepthStencilStateCreateInfo(
		VkBool32 depthTestEnable,
		VkBool32 depthWriteEnable,
		VkCompareOp depthCompareOp)
	{
		VkPipelineDepthStencilStateCreateInfo pipelineDepthStencilStateCreateInfo{};
		pipelineDepthStencilStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
		pipelineDepthStencilStateCreateInfo.depthTestEnable = depthTestEnable;
		pipelineDepthStencilStateCreateInfo.depthWriteEnable = depthWriteEnable;
		pipelineDepthStencilStateCreateInfo.depthCompareOp = depthCompareOp;
		pipelineDepthStencilStateCreateInfo.back.compareOp = VK_COMPARE_OP_ALWAYS;
		return pipelineDepthStencilStateCreateInfo;
	}

	inline VkPipelineViewportStateCreateInfo pipelineViewportStateCreateInfo(
		uint32_t viewportCount,
		uint32_t scissorCount,
		VkPipelineViewportStateCreateFlags flags = 0)
	{
		VkPipelineViewportStateCreateInfo pipelineViewportStateCreateInfo{};
		pipelineViewportStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
		pipelineViewportStateCreateInfo.viewportCount = viewportCount;
		pipelineViewportStateCreateInfo.scissorCount = scissorCount;
		pipelineViewportStateCreateInfo.flags = flags;
		return pipelineViewportStateCreateInfo;
	}

	inline VkPipelineMultisampleStateCreateInfo pipelineMultisampleStateCreateInfo(
		VkSampleCountFlagBits rasterizationSamples,
		VkPipelineMultisampleStateCreateFlags flags = 0)
	{
		VkPipelineMultisampleStateCreateInfo pipelineMultisampleStateCreateInfo{};
		pipelineMultisampleStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
		pipelineMultisampleStateCreateInfo.rasterizationSamples = rasterizationSamples;
		pipelineMultisampleStateCreateInfo.flags = flags;
		return pipelineMultisampleStateCreateInfo;
	}

	inline VkPipelineDynamicStateCreateInfo pipelineDynamicStateCreateInfo(
		const VkDynamicState* pDynamicStates,
		uint32_t dynamicStateCount,
		VkPipelineDynamicStateCreateFlags flags = 0)
	{
		VkPipelineDynamicStateCreateInfo pipelineDynamicStateCreateInfo{};
		pipelineDynamicStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
		pipelineDynamicStateCreateInfo.pDynamicStates = pDynamicStates;
		pipelineDynamicStateCreateInfo.dynamicStateCount = dynamicStateCount;
		pipelineDynamicStateCreateInfo.flags = flags;
		return pipelineDynamicStateCreateInfo;
	}

	inline VkPipelineDynamicStateCreateInfo pipelineDynamicStateCreateInfo(
		const std::vector<VkDynamicState>& pDynamicStates,
		VkPipelineDynamicStateCreateFlags flags = 0)
	{
		VkPipelineDynamicStateCreateInfo pipelineDynamicStateCreateInfo{};
		pipelineDynamicStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
		pipelineDynamicStateCreateInfo.pDynamicStates = pDynamicStates.data();
		pipelineDynamicStateCreateInfo.dynamicStateCount = static_cast<uint32_t>(pDynamicStates.size());
		pipelineDynamicStateCreateInfo.flags = flags;
		return pipelineDynamicStateCreateInfo;
	}

	inline VkPipelineTessellationStateCreateInfo pipelineTessellationStateCreateInfo(uint32_t patchControlPoints)
	{
		VkPipelineTessellationStateCreateInfo pipelineTessellationStateCreateInfo{};
		pipelineTessellationStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO;
		pipelineTessellationStateCreateInfo.patchControlPoints = patchControlPoints;
		return pipelineTessellationStateCreateInfo;
	}

	inline VkGraphicsPipelineCreateInfo pipelineCreateInfo(
		VkPipelineLayout layout,
		VkRenderPass renderPass,
		VkPipelineCreateFlags flags = 0)
	{
		VkGraphicsPipelineCreateInfo pipelineCreateInfo{};
		pipelineCreateInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
		pipelineCreateInfo.layout = layout;
		pipelineCreateInfo.renderPass = renderPass;
		pipelineCreateInfo.flags = flags;
		pipelineCreateInfo.basePipelineIndex = -1;
		pipelineCreateInfo.basePipelineHandle = VK_NULL_HANDLE;
		return pipelineCreateInfo;
	}

	inline VkGraphicsPipelineCreateInfo pipelineCreateInfo()
	{
		VkGraphicsPipelineCreateInfo pipelineCreateInfo{};
		pipelineCreateInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
		pipelineCreateInfo.basePipelineIndex = -1;
		pipelineCreateInfo.basePipelineHandle = VK_NULL_HANDLE;
		return pipelineCreateInfo;
	}

	inline VkComputePipelineCreateInfo computePipelineCreateInfo(
		VkPipelineLayout layout,
		VkPipelineCreateFlags flags = 0)
	{
		VkComputePipelineCreateInfo computePipelineCreateInfo{};
		computePipelineCreateInfo.sType = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
		computePipelineCreateInfo.layout = layout;
		computePipelineCreateInfo.flags = flags;
		return computePipelineCreateInfo;
	}

	inline VkPushConstantRange pushConstantRange(
		VkShaderStageFlags stageFlags,
		uint32_t size,
		uint32_t offset)
	{
		VkPushConstantRange pushConstantRange{};
		pushConstantRange.stageFlags = stageFlags;
		pushConstantRange.offset = offset;
		pushConstantRange.size = size;
		return pushConstantRange;
	}

	inline VkBindSparseInfo bindSparseInfo()
	{
		VkBindSparseInfo bindSparseInfo{};
		bindSparseInfo.sType = VK_STRUCTURE_TYPE_BIND_SPARSE_INFO;
		return bindSparseInfo;
	}

	/** @brief Initialize a map entry for a shader specialization constant */
	inline VkSpecializationMapEntry specializationMapEntry(uint32_t constantID, uint32_t offset, size_t size)
	{
		VkSpecializationMapEntry specializationMapEntry{};
		specializationMapEntry.constantID = constantID;
		specializationMapEntry.offset = offset;
		specializationMapEntry.size = size;
		return specializationMapEntry;
	}

	/** @brief Initialize a specialization constant info structure to pass to a shader stage */
	inline VkSpecializationInfo specializationInfo(uint32_t mapEntryCount, const VkSpecializationMapEntry* mapEntries, size_t dataSize, const void* data)
	{
		VkSpecializationInfo specializationInfo{};
		specializationInfo.mapEntryCount = mapEntryCount;
		specializationInfo.pMapEntries = mapEntries;
		specializationInfo.dataSize = dataSize;
		specializationInfo.pData = data;
		return specializationInfo;
	}

	/** @brief Initialize a specialization constant info structure to pass to a shader stage */
	inline VkSpecializationInfo specializationInfo(const std::vector<VkSpecializationMapEntry>& mapEntries, size_t dataSize, const void* data)
	{
		VkSpecializationInfo specializationInfo{};
		specializationInfo.mapEntryCount = static_cast<uint32_t>(mapEntries.size());
		specializationInfo.pMapEntries = mapEntries.data();
		specializationInfo.dataSize = dataSize;
		specializationInfo.pData = data;
		return specializationInfo;
	}

	// Ray tracing related
	inline VkAccelerationStructureGeometryKHR accelerationStructureGeometryKHR()
	{
		VkAccelerationStructureGeometryKHR accelerationStructureGeometryKHR{};
		accelerationStructureGeometryKHR.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR;
		return accelerationStructureGeometryKHR;
	}

	inline VkAccelerationStructureBuildGeometryInfoKHR accelerationStructureBuildGeometryInfoKHR()
	{
		VkAccelerationStructureBuildGeometryInfoKHR accelerationStructureBuildGeometryInfoKHR{};
		accelerationStructureBuildGeometryInfoKHR.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR;
		return accelerationStructureBuildGeometryInfoKHR;
	}

	inline VkAccelerationStructureBuildSizesInfoKHR accelerationStructureBuildSizesInfoKHR()
	{
		VkAccelerationStructureBuildSizesInfoKHR accelerationStructureBuildSizesInfoKHR{};
		accelerationStructureBuildSizesInfoKHR.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR;
		return accelerationStructureBuildSizesInfoKHR;
	}

	inline VkRayTracingShaderGroupCreateInfoKHR rayTracingShaderGroupCreateInfoKHR()
	{
		VkRayTracingShaderGroupCreateInfoKHR rayTracingShaderGroupCreateInfoKHR{};
		rayTracingShaderGroupCreateInfoKHR.sType = VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR;
		return rayTracingShaderGroupCreateInfoKHR;
	}

	inline VkRayTracingPipelineCreateInfoKHR rayTracingPipelineCreateInfoKHR()
	{
		VkRayTracingPipelineCreateInfoKHR rayTracingPipelineCreateInfoKHR{};
		rayTracingPipelineCreateInfoKHR.sType = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR;
		return rayTracingPipelineCreateInfoKHR;
	}

	inline VkWriteDescriptorSetAccelerationStructureKHR writeDescriptorSetAccelerationStructureKHR()
	{
		VkWriteDescriptorSetAccelerationStructureKHR writeDescriptorSetAccelerationStructureKHR{};
		writeDescriptorSetAccelerationStructureKHR.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR;
		return writeDescriptorSetAccelerationStructureKHR;
	}


}

