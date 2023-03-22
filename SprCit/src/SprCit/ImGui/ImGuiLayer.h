#pragma once

#include "SprCit/Layer.h"

#include "SprCit/Events/ApplicationEvent.h"
#include "SprCit/Events/MouseEvent.h"
#include "SprCit/Events/KeyEvent.h"

namespace SprCit {

	class SPRCIT_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}
