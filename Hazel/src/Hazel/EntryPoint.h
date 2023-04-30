#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {

	Hazel::Log::Init();
	HZ_CORE_INFO("HELLO_INIT");

	int a = 2;
	HZ_WARN("Client: {0}",2);
	
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif