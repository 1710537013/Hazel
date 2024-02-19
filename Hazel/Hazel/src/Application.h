#pragma once
#include"Core.h"
#include"Events/Event.h"
#include"Window.h"
#include <Events/ApplicationEvent.h>
#include"LayerStack.h"

namespace Hazel {

	class HZ_API Application
	{
	public:
		Application();
		~Application();

		void Run();

		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		inline Window& GetWindows() { return *m_Window; } //这里声明内联什么意思

		inline static Application& Get() { return *Instance; }
	private:
		LayerStack m_LayerStack;
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		static Application* Instance ;
	};

	//Application* CreateApplication();
	extern Hazel::Application* CreateApplication();
}

