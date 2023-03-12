#pragma once

#ifdef SC_PLATFORM_WINDOWS

extern SprCit::Application* SprCit::CreateApplication();

int main(int argc, char** argv) {
	printf("SprCit Engine\n");

	SprCit::Log::Init();
	SC_CORE_WARN("Initialized Log!");
	int a = 5;
	SC_INFO("Hello! Var={0}", a);
	auto app = SprCit::CreateApplication();
	app->Run();
	delete app;
	//
}


#endif // SC_PLATFORM_WINDOWS
