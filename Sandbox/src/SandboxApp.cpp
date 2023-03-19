#include <SprCit.h>

class ExampleLayer : public SprCit::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		//SC_INFO("ExampleLayer::Update");
		if (SprCit::Input::IsKeyPressed(SC_KEY_TAB))
			SC_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(SprCit::Event& event) override
	{
		//SC_TRACE("{0}", event);
		//if (event.GetEventType() == SprCit::EventType::KeyPressed)
		//{
		//	SprCit::KeyPressedEvent& e = (SprCit::KeyPressedEvent&)event;
		//	if (e.GetKeyCode() == SC_KEY_TAB)
		//		SC_TRACE("Tab key is pressed (event)!");
		//	SC_TRACE("{0}", (char)e.GetKeyCode());
		//}
	}
};


class Sandbox : public SprCit::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new SprCit::ImGuiLayer());
	}
	~Sandbox() {

	}

};

SprCit::Application* SprCit::CreateApplication() {

	return new Sandbox();
}