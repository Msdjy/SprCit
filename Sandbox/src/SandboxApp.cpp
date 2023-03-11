
#include <SprCit.h>


class Sandbox : public SprCit::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}

};

SprCit::Application* SprCit::CreateApplication() {

	return new Sandbox();
}