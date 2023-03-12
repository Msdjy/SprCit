#pragma once

#include<memory>

#include "Core.h"
#include"spdlog/spdlog.h"

namespace SprCit {
	class SPRCIT_API Log
	{
	public:
		static void  Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	
	};
}

// Core log macros
#define SC_CORE_ERROR(...)     ::SprCit::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SC_CORE_WARN(...)      ::SprCit::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SC_CORE_INFO(...)      ::SprCit::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SC_CORE_TRACE(...)     ::SprCit::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SC_CORE_FATAL(...)     ::SprCit::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SC_ERROR(...)   ::SprCit::Log::GetClientLogger()->error(__VA_ARGS__)
#define SC_WARN(...)    ::SprCit::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SC_INFO(...)    ::SprCit::Log::GetClientLogger()->info(__VA_ARGS__)
#define SC_TRACE(...)   ::SprCit::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SC_FATAL(...)   ::SprCit::Log::GetClientLogger()->fatal(__VA_ARGS__)