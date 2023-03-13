#pragma once


#ifdef SC_PLATFORM_WINDOWS
	#ifdef SC_BUILD_DLL
		#define SPRCIT_API __declspec(dllexport)	
	#else
		#define SPRCIT_API __declspec(dllimport)	
	#endif // SC_BUILD_DLL
#else
	#error SprCit only support Windows!
#endif // SC_PLATFORM_WINDOWS

#ifdef SC_ENABLE_ASSERTS
#define SC_ASSERT(x, ...) { if(!(x)) { SC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define SC_CORE_ASSERT(x, ...) { if(!(x)) { SC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define SC_ASSERT(x, ...)
#define SC_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)