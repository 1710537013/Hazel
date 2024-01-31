#pragma once
#include"Application.h"
#include"Log.h"

#ifdef HZ_PLATFORM_WINDOWS


//extern Hazel::Application* Hazel::CreateApplication();


int main(int argc, char** argv) {

	auto app = Hazel::CreateApplication();

	Hazel::Log::Init();
	HZ_CORE_ERROR("Core Error");
	HZ_INFO("Client Info");
	app->Run();

	delete app;
}

#endif 