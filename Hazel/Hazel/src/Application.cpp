#include"hzpch.h"
#include "Application.h"

namespace Hazel {

	Hazel::Application::Application()
	{
		m_Window = std::unique_ptr<Window>( Window::Create());
	}

	Hazel::Application::~Application()
	{
	}

	void Hazel::Application::Run()
	{
		while (m_Runing) {
			//m_Window->OnUpdate();
		}

	}
}
