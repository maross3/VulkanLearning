#pragma once
#include <string>
#include <vector>
#include "app_device.hpp"
namespace VulkanTest {

	struct PipelineConfigInfo {
		PipelineConfigInfo() = default;
		PipelineConfigInfo(const PipelineConfigInfo&) = delete;
		PipelineConfigInfo& operator=(const PipelineConfigInfo&) = delete;


		VkViewport viewport;
		VkRect2D scissor;
		VkPipelineViewportStateCreateInfo viewportInfo;

		VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
		VkPipelineRasterizationStateCreateInfo rasterizationInfo;

		VkPipelineMultisampleStateCreateInfo multisampleInfo;
		VkPipelineColorBlendAttachmentState colorBlendAttachment;
		VkPipelineColorBlendStateCreateInfo colorBlendInfo;
		VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
		VkPipelineLayout pipelineLayout = nullptr;
		VkRenderPass renderPass = nullptr;
		uint32_t subpass = 0;
	};

	class AppPipeline
	{
	public:
		AppPipeline(
			AppDevice& device,
			const std::string& vertPathFile,
			const std::string& fragFilepath, 
			const PipelineConfigInfo& configinfo);
		~AppPipeline();

		AppPipeline(const AppPipeline&) = delete;
		void operator=(const AppPipeline&) = delete;

		void bind(VkCommandBuffer commandBuffer);

		static void defaultPipelineConfigInfo(
			PipelineConfigInfo& configInfo, uint32_t width, uint32_t height);

	private:
		static std::vector<char> readFile(const std::string& filePath);

		void createGraphicsPipline(
			const std::string& vertPathFile, 
			const std::string& fragFilepath,
			const PipelineConfigInfo& configinfo);

		void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

		AppDevice& appDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};
}
