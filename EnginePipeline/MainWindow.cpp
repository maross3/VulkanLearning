#include "MainWindow.hpp"
#include <stdexcept>

namespace VulkanTest
{
	MainWindow::MainWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name}
	{
		InitWindow();
	}

	MainWindow::~MainWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	MainWindow::MainWindow(const MainWindow&)
	{
	}

	MainWindow& MainWindow::operator=(MainWindow)
	{
	}

	void MainWindow::InitWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}

	void MainWindow::CreateWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
	{
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
		{
			throw std::runtime_error("failed to create window surfacce");
		}
	}
}
