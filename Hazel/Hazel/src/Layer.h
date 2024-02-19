#pragma once

#include "Events/Event.h"
#include"Core.h"

namespace Hazel {

	class HZ_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnEvent(Hazel::Event& event) = 0;

		const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}