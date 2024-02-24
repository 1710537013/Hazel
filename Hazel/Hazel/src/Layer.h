#pragma once

#include"Core.h"
#include "Events/Event.h"

namespace Hazel {

	class HZ_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Hazel::Event& event) {};

		const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}