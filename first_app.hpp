#pragma once
#include "window_main.hpp"
#include "app_pipline.hpp"

namespace VulkanTest {
	class first_app
	{
		public:
			static constexpr int WIDTH = 800;
			static constexpr int HEIGHT = 600;
			void run();


		private:
			window_main window_main{ WIDTH, HEIGHT, "Hello world" };
			AppPipeline appPipeline{ "simple_shader.vert.spv", "simple_shader.frag.spv" };
	};
}

