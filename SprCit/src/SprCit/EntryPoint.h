#pragma once

#ifdef SC_PLATFORM_WINDOWS

extern SprCit::Application* SprCit::CreateApplication();

int main(int argc, char** argv) {
	printf("SprCit Engine\n");
	auto app = SprCit::CreateApplication();
	app->Run();
	delete app;

}


#endif // SC_PLATFORM_WINDOWS
