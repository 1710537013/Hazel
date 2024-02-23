#pragma once

#include"Core.h"
#include"Input.h"

namespace Hazel {
	class  WindowsInput :public Input
	{
		// 通过 Input 继承
		virtual bool IsKeyPressedImpl(KeyCode key) override;
		virtual bool IsMouseButtonPressedImpl(MouseCode button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}
