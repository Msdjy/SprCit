#pragma once

#include "SprCit/Input.h"

namespace SprCit {

	class WindowsInput :public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode)override;

		virtual bool isMouseButtonPressedImpl(int button)override;
		virtual std::pair<float, float> GetMousePositionImpl()override;
		virtual float GetMouseXImpl()override;
		virtual float GetMouseYImpl()override;
	};


}