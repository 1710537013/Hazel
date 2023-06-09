#pragma once
#include"Core.h"

namespace Hazel {

	class __declspec(dllexport) Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}
