#include "app_pipline.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace VulkanTest {

	AppPipeline::AppPipeline(const std::string& vertPathFile, const std::string& fragFilepath) {
		createGraphicsPipline(vertPathFile, fragFilepath);
	}

	std::vector<char> AppPipeline::readFile(const std::string& filepath) {
		// ate = when files open, we seek to end immediately
		std::ifstream file(filepath, std::ios::ate | std::ios::binary);
		if (!file.is_open()) {
			throw std::runtime_error("failed to open file " + filepath);
		}

		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);
		file.close();

		return buffer;
	}
	void AppPipeline::createGraphicsPipline(const std::string& vertPathFile, const std::string& fragFilepath) {
		auto vertCode = readFile(vertPathFile);
		auto fragCode = readFile(fragFilepath);

		std::cout << "Vertex shader code size: " << vertCode.size() << '\n';
		std::cout << "Fragment shader code size: " << fragCode.size() << '\n';

	}
}
