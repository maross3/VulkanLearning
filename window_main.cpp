#include "window_main.hpp"

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
}

