#include<Hazel.h>
#include"glm/glm.hpp"
#include"imgui.h"

class ExampleLayer :public Hazel::Layer {
public:
	ExampleLayer() :Layer("Example") {}

	virtual void OnImGuiRender() override
	{
		/*ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();*/
	}
	void OnEvent(Hazel::Event& event) {

		if (event.GetEventType() == Hazel::EventType::KeyPressed)
		{
			Hazel::KeyPressedEvent& e = (Hazel::KeyPressedEvent&)event;
			if (e.GetKeyCode() == Hazel::Key::Tab)
				HZ_TRACE("Tab key is pressed (event)!");
			HZ_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox :public Hazel::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	};
	~Sandbox() {};

};

Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();
}