#include "hzpch.h"
#include "WindowsInput.h"
#include"GLFW/glfw3.h"
#include <Application.h>

namespace Hazel {
	Input* Input::s_Instance = new WindowsInput();   //初始化单例

	bool Hazel::WindowsInput::IsKeyPressedImpl(KeyCode key)
	{
		auto window = (GLFWwindow*)Application::Get().GetWindows().GetNativeWindow();
		auto state = glfwGetKey(window, key);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Hazel::WindowsInput::IsMouseButtonPressedImpl(MouseCode button)
	{
		auto window = (GLFWwindow*)Application::Get().GetWindows().GetNativeWindow();
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS || state == GLFW_REPEAT; //GLFW_PRESS?
	}

	std::pair<float, float> Hazel::WindowsInput::GetMousePositionImpl()
	{
		auto window = (GLFWwindow*)Application::Get().GetWindows().GetNativeWindow();
		double posX, posY;
		glfwGetCursorPos(window, &posX, &posY);
		return { posX, posY };
	}

	float Hazel::WindowsInput::GetMouseXImpl()
	{
		std::pair<float, float> posX = GetMousePositionImpl();
		return posX.first;
	}

	float Hazel::WindowsInput::GetMouseYImpl()
	{
		std::pair<float, float> posX = GetMousePositionImpl();
		return posX.second;
	}
}