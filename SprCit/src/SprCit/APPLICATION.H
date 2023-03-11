#pragma once

#include "Core.h"


namespace SprCit {

	class SPRCIT_API Application
	{
	public:
		Application();
		virtual ~Application();


		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}