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


#define BIT(x) (1 << x)