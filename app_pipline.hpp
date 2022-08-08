#pragma once
#include <string>
#include <vector>
namespace VulkanTest {
	class AppPipeline
	{
	public:
		AppPipeline(const std::string& vertPathFile, const std::string& fragFilepath);

	private:
		static std::vector<char> readFile(const std::string& filePath);

		void createGraphicsPipline(const std::string& vertPathFile, const std::string& fragFilepath);
	};
}
