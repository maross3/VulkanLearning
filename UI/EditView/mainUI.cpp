#include "MainUI.hpp"

namespace EditorUI
{

	void InitUIWindow()
	{


		/*
				ImGui_ImplVulkan_InitInfo init_info = {};

				// included on AppDevice
				init_info.Instance = g_Instance;
				
				// ??
				init_info.PhysicalDevice = g_PhysicalDevice;
				
				// AppDevice
				init_info.Device = g_Device;
				init_info.QueueFamily = g_QueueFamily;
				
				// ??
				init_info.Queue = g_Queue;
				init_info.PipelineCache = g_PipelineCache;
				init_info.DescriptorPool = g_DescriptorPool;
				init_info.Subpass = 0;
				init_info.MinImageCount = g_MinImageCount;
				init_info.ImageCount = wd->ImageCount;
				init_info.MSAASamples = VK_SAMPLE_COUNT_1_BIT;
				init_info.Allocator = g_Allocator;
				init_info.CheckVkResultFn = check_vk_result;
				ImGui_ImplVulkan_Init(&init_info, wd->RenderPass);
				*/
	}
	MainUI::MainUI(VulkanTest::MainWindow& window, VulkanTest::AppDevice& device) :window{ window }, device{ device }
	{
		InitUIWindow();
		ImGui_ImplVulkan_InitInfo init_info = {};
	//	init_info.Instance = 
		auto instance = device.GetInstance();
		init_info.Instance = instance;
		init_info.Device = device.device();
		init_info.Queue = device.graphicsQueue();

	}
	void MainUI::InitUIWindow()
	{
		ImGui_ImplVulkanH_Window(window);
	}
}
