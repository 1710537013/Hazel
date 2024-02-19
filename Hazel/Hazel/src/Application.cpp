#include"hzpch.h"
#include "Application.h"

#include"glad/glad.h"

namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1) 
	
	Application* Application::Instance = nullptr;

	Hazel::Application::Application()
	{
		Instance = this;
		m_Window = std::unique_ptr<Window>( Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

	}

	Hazel::Application::~Application()
	{
	}

	void Hazel::Application::Run()
	{
		while (m_Running) {
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));


		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;

		return false;
	}
	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}
	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}
}
