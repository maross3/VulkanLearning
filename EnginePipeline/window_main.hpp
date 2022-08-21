#pragma once

#define GLFW_INCLUDE_VULKAN
#include<GLFW/glfw3.h>
#include<string>

namespace VulkanTest
{
	class window_main
	{
	public:
		window_main(int w, int h, std::string name);
		~window_main();

		window_main(const window_main&) = delete;
		window_main& operator=(const window_main) = delete;

		bool shouldClose() { return glfwWindowShouldClose(window); }
		VkExtent2D getExtent() { return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)}; }
		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
		void initWindow();

		const int width;
		const int height;

		std::string windowName;
		GLFWwindow* window;
	};
}
