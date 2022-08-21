#pragma once
#include "MainWindow.hpp"
#include "app_pipline.hpp"
#include "app_device.hpp"
#include "app_swap_chain.hpp"
#include "../UI/EditView/MainUI.hpp"

#include <memory>
#include <vector>

namespace VulkanTest
{
	class FirstApp
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;
		FirstApp();
		~FirstApp();

		FirstApp(const FirstApp&) = delete;
		FirstApp& operator=(const FirstApp&) = delete;

		void Run();

	private:
		void CreatePipelineLayout();
		void CreatePipeline();
		void CreateCommandBuffers();
		void DrawFrame();
		MainWindow window_main{WIDTH, HEIGHT, "Hello world"};

		AppDevice appDevice{window_main};

		AppSwapChain appSwapChain{appDevice, window_main.GetExtent()};

		// IS BROKEN
		EditorUI::MainUI ui{window_main, appDevice};

		std::unique_ptr<AppPipeline> appPipeline;
		VkPipelineLayout pipelineLayout;
		std::vector<VkCommandBuffer> commandBuffers;
	};
}
