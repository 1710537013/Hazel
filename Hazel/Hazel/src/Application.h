#pragma once
#include"Core.h"

namespace Hazel {

	class HZ_API Application
	{
	public:
		Application();
		~Application();

		void Run();

	};

	//Application* CreateApplication();
	extern Hazel::Application* CreateApplication();
}

