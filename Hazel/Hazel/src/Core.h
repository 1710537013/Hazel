#pragma once

#ifdef HZ_PLATFORM_WINDOWS

	#ifdef HZ_BUILD_DLL
		#define HZ_API _declspec(dllexport)
	#else 
		#define HZ_API _declspec(dllimport)
	#endif // HZ_BUILD_DLL

#else
	#error ONLY WINDOWS!
#endif // HZ_PLATFORM_WINDOWS
