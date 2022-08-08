#include "window_main.hpp"
#include <stdexcept>
namespace VulkanTest {
	window_main::window_main(int w, int h, std::string name) :width{ w }, height{ h }, windowName{ name }{
		initWindow();
	}
	window_main::~window_main() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	void window_main::initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}
	void window_main::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
			throw std::runtime_error("failed to create window surfacce");
		}
	}
}

