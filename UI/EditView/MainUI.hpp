#pragma once

#include "imgui.h"
#include "backends/imgui_impl_vulkan.h"
#include "../../EnginePipeline/MainWindow.hpp"
#include "../../EnginePipeline/app_device.hpp"

namespace EditorUI
{
	class MainUI
	{
	public:

		MainUI(VulkanTest::MainWindow &window, VulkanTest::AppDevice &device);

		void InitUIWindow();
	
	private:
		VulkanTest::MainWindow& window;
		VulkanTest::AppDevice& device;
	
	};

}
