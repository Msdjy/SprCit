#pragma once

#include "SprCit/Core.h"

namespace SprCit {

	class SPRCIT_API Input
	{
	public:
		inline static bool IsKeyPressed(int keycode) {return s_Instance->IsKeyPressedImpl(keycode);}

		inline static bool IsMouseButtonPressed(int button) { return s_Instance->isMouseButtonPressedImpl(button); }
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(int keycode)=0;

		virtual bool isMouseButtonPressedImpl(int button)=0;
		virtual std::pair<float, float> GetMousePositionImpl()=0;
		virtual float GetMouseXImpl()=0;
		virtual float GetMouseYImpl()=0;
	private:
		static Input* s_Instance;
	};

	

}