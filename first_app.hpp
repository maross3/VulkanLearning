#pragma once
#include "window_main.hpp"

namespace VulkanTest {
	class first_app
	{
		public:
			static constexpr int WIDTH = 800;
			static constexpr int HEIGHT = 600;
			void run();


		private:
			window_main window_main{ WIDTH, HEIGHT, "Hello world" };
	};
}

