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
		SC_INFO("ExampleLayer::Update");
	}

	void OnEvent(SprCit::Event& event) override
	{
		SC_TRACE("{0}", event);
	}
};


class Sandbox : public SprCit::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {

	}

};

SprCit::Application* SprCit::CreateApplication() {

	return new Sandbox();
}