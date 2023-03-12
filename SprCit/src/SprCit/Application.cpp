#include "Application.h"

#include "SprCit/Event/ApplicationEvent.h"
#include "SprCit/Log.h"

namespace SprCit {
	Application::Application(){
		
	}

	Application::~Application() {

	}


	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		SC_TRACE(e);

		while (true)
		{

		}
	}
}