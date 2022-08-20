#pragma once

#include "imgui.h"
#include "backends/imgui_impl_vulkan.h"
#include "../../EnginePipeline/window_main.hpp"
namespace EditorUI
{
	class MainUI
	{
	public:
		VulkanTest::window_main &window;
		MainUI(VulkanTest::window_main &window);

		void InitUIWindow();
	};
}
