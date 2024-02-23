#include<Hazel.h>


class ExampleLayer :public Hazel::Layer {
public:
	ExampleLayer() :Layer("Example") {}

	void OnUpdate()override {
		//HZ_INFO("EXampleLayer");
	}
	void OnAttach() override {

	}
	void OnDetach()override {
	};

	void OnEvent(Hazel::Event& event) {

		if (Hazel::Input::IsKeyPressed(Hazel::Key::Tab)) {
			HZ_TRACE("{0}", event);
		}
	}
};

class Sandbox :public Hazel::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushLayer(new Hazel::ImGuiLayer());
	};
	~Sandbox() {};

};

Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();
}