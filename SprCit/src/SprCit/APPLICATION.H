#pragma once

#include "Core.h"
#include "Event/Event.h"

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