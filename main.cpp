#include "EnginePipeline/first_app.hpp"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "UI/EditView/MainUI.hpp"

int main() {
	VulkanTest::FirstApp app{};
	
	try {
		app.Run();
		
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
