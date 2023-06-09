#pragma once


#ifdef SC_PLATFORM_WINDOWS
#if SC_DYNAMIC_LINK
	#ifdef SC_BUILD_DLL
		#define SPRCIT_API __declspec(dllexport)	
	#else
		#define SPRCIT_API __declspec(dllimport)	
	#endif // SC_BUILD_DLL
#else
	#define SPRCIT_API
#endif
#else
	#error SprCit only support Windows!
#endif // SC_PLATFORM_WINDOWS

#ifdef SC_DEBUG
	#define SC_ENABLE_ASSERTS
#endif

#ifdef SC_ENABLE_ASSERTS
#define SC_ASSERT(x, ...) { if(!(x)) { SC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define SC_CORE_ASSERT(x, ...) { if(!(x)) { SC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define SC_ASSERT(x, ...)
#define SC_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define SC_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)