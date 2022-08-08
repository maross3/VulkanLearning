#include "first_app.hpp"

namespace VulkanTest {
	void first_app::run() {

		while (!window_main.shouldClose()) {
			glfwPollEvents();
		}
	}
}