#pragma once
#include"Core.h"
#include"Events/Event.h"
#include"Window.h"

namespace Hazel {

	class HZ_API Application
	{
	public:
		Application();
		~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Runing = true;
	};

	//Application* CreateApplication();
	extern Hazel::Application* CreateApplication();
}

