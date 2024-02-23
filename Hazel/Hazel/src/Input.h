#pragma once

#include "Events/KeyCodes.h"
#include "Events/MouseCodes.h"
//#include <utility>

namespace Hazel {

	class HZ_API Input
	{
	public:
		static bool IsKeyPressed(KeyCode key) { return s_Instance->IsKeyPressedImpl(key); };

		static bool IsMouseButtonPressed(MouseCode button) { return s_Instance->IsMouseButtonPressedImpl(button); };
		static std::pair<float, float>  GetMousePosition() { return s_Instance->GetMousePositionImpl(); };
		static float GetMouseX() { return s_Instance->GetMouseXImpl(); };
		static float GetMouseY() { return s_Instance->GetMouseYImpl(); };

	protected:
		virtual bool IsKeyPressedImpl(KeyCode key) = 0;
		virtual bool IsMouseButtonPressedImpl(MouseCode button)=0;
		virtual std::pair<float, float> GetMousePositionImpl()=0;
		virtual float GetMouseXImpl()=0;
		virtual float GetMouseYImpl() =0;

	private:
		static Input* s_Instance;
	};
}
