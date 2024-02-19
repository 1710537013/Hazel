#pragma once
#include"Application.h"
#include"Log.h"
#include"hzpch.h"
#ifdef HZ_PLATFORM_WINDOWS


//extern Hazel::Application* Hazel::CreateApplication();


int main(int argc, char** argv) {
	Hazel::Log::Init();

	auto app = Hazel::CreateApplication();

	app->Run();

	delete app;
}

#endif 