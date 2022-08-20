#pragma once

#include "imgui.h"
#include "backends/imgui_impl_vulkan.h"
#include "../../EnginePipeline/first_app.hpp"
namespace EditorUI
{
	class MainUI
	{
	public:
		VulkanTest::window_main mainWindow;

		MainUI(VulkanTest::window_main& window);

		void InitUIWindow();
	};
}
