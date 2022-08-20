#pragma once

#include "imgui.h"
#include "backends/imgui_impl_vulkan.h"
#include "../../EnginePipeline/window_main.hpp"
#include "../../EnginePipeline/app_device.hpp"

namespace EditorUI
{
	class MainUI
	{
	public:

		MainUI(VulkanTest::window_main &window, VulkanTest::AppDevice &device);

		void InitUIWindow();
	
	private:
		VulkanTest::window_main& window;
		VulkanTest::AppDevice& device;
	
	};

}
