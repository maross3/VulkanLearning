#include "first_app.hpp"
#include <array>
#include <stdexcept>
namespace VulkanTest {
	FirstApp::FirstApp() {
		createPipelineLayout();
		createPipeline();
		createCommandBuffers();
	}
	FirstApp::~FirstApp() { vkDestroyPipelineLayout(appDevice.device(), pipelineLayout, nullptr); }
	void FirstApp::run() {

		while (!window_main.shouldClose()) {
			glfwPollEvents();
			drawFrame();
		}

		vkDeviceWaitIdle(appDevice.device());
	}

	void FirstApp::createPipelineLayout() {
		VkPipelineLayoutCreateInfo pipelineLayoutInfo{  };
		
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 0;
		pipelineLayoutInfo.pSetLayouts = nullptr;
		pipelineLayoutInfo.pushConstantRangeCount = 0;
		pipelineLayoutInfo.pPushConstantRanges = nullptr;

		if (vkCreatePipelineLayout(appDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create pipeline layout!");
		}
	}

	void FirstApp::createPipeline() {
		// auto pipelineConfig = AppPipeline::defaultPipelineConfigInfo(appSwapChain.width(), appSwapChain.height());
		PipelineConfigInfo pipelineConfig{};

		AppPipeline::defaultPipelineConfigInfo(
			pipelineConfig,
			appSwapChain.width(),
			appSwapChain.height());

		pipelineConfig.renderPass = appSwapChain.getRenderPass();
		pipelineConfig.pipelineLayout = pipelineLayout;
		
		appPipeline = std::make_unique<AppPipeline>(appDevice, 
			"simple_shader.vert.spv", 
			"simple_shader.frag.spv", 
			pipelineConfig);
	}
	void FirstApp::createCommandBuffers() {
		commandBuffers.resize(appSwapChain.imageCount());
		VkCommandBufferAllocateInfo allocInfo{};
		allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
		allocInfo.commandPool = appDevice.getCommandPool();
		allocInfo.commandBufferCount = static_cast<uint32_t>(commandBuffers.size());
		if (vkAllocateCommandBuffers(appDevice.device(), &allocInfo, commandBuffers.data()) !=
			VK_SUCCESS) {
			throw std::runtime_error("failed to allocate command buffers!");
		}
		for (int i = 0; i < commandBuffers.size(); i++) {
			VkCommandBufferBeginInfo beginInfo{};
			beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

			if (vkBeginCommandBuffer(commandBuffers[i], &beginInfo) != VK_SUCCESS)
				throw std::runtime_error("failed to begin recording command buffer!");

			VkRenderPassBeginInfo renderPassInfo{};
			renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
			renderPassInfo.renderPass = appSwapChain.getRenderPass();
			renderPassInfo.framebuffer = appSwapChain.getFrameBuffer(i);

			renderPassInfo.renderArea.offset = { 0, 0 };
			renderPassInfo.renderArea.extent = appSwapChain.getSwapChainExtent();

			std::array<VkClearValue, 2> clearValues{};

			// TODO make an enum for descriptor
			clearValues[0].color = { 0.2f, 0.2f, 0.2f, 1.0f }; // assigned color attachement
			clearValues[1].depthStencil = { 1.0f, 0 }; // assigned depth attachement

			renderPassInfo.clearValueCount = static_cast<uint32_t>(clearValues.size());
			renderPassInfo.pClearValues = clearValues.data();


			// For using secondary, pass below to vkCmdBeginRenderPass as third argument:
			//VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS
			vkCmdBeginRenderPass(commandBuffers[i], &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);
			appPipeline->bind(commandBuffers[i]);

			vkCmdDraw(commandBuffers[i], 3, 1, 0, 0);

			vkCmdEndRenderPass(commandBuffers[i]);
			if (vkEndCommandBuffer(commandBuffers[i]) != VK_SUCCESS)
				throw new std::runtime_error("Failed to record buffer");

		}
	}
	void FirstApp::drawFrame() {
		uint32_t imageIndex;
		auto result = appSwapChain.acquireNextImage(&imageIndex);
		if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR)
			throw std::runtime_error("Failed to aquire swap chain image");

		result = appSwapChain.submitCommandBuffers(&commandBuffers[imageIndex], &imageIndex);
		if (result != VK_SUCCESS)
			throw std::runtime_error("failed to present swap chain image");
	}
}