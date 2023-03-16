workspace "SprCit"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "SprCit/vendor/GLFW/include"
IncludeDir["Glad"] = "SprCit/vendor/Glad/include"
IncludeDir["ImGui"] = "SprCit/vendor/imgui"

include "SprCit/vendor/GLFW"
include "SprCit/vendor/Glad"
include "SprCit/vendor/imgui"



project "SprCit"
	location "SprCit"	
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "scpch.h"
	pchsource "SprCit/src/scpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "10.0"

		defines
		{
			"SC_BUILD_DLL",
			"SC_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SC_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SC_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SC_DIST"
		runtime "Release"
		optimize "On"


project "Sandbox"
	location "Sandbox"	
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"SprCit/vendor/spdlog/include",
		"SprCit/src"
	}

	links
	{
		"SprCit"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "10.0"

		defines
		{
			"SC_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SC_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SC_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SC_DIST"
		runtime "Release"
		optimize "On"


