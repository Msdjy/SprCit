#pragma once

#include "Core.h"

#include "Window.h"
#include "SprCit/LayerStack.h"
#include "Events/Event.h"
#include "SprCit/Events/ApplicationEvent.h"

#include "SprCit/ImGui/ImGuiLayer.h"

namespace SprCit {

	class SPRCIT_API Application
	{
	public:
		Application();
		virtual ~Application();


		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);


		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		ImGuiLayer* m_ImGuiLayer;
		std::unique_ptr<Window> m_Window;

		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}