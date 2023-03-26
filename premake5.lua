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

-- Include tories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "SprCit/vendor/GLFW/include"
IncludeDir["Glad"] = "SprCit/vendor/Glad/include"
IncludeDir["ImGui"] = "SprCit/vendor/imgui"
IncludeDir["glm"] = "SprCit/vendor/glm"

include "SprCit/vendor/GLFW"
include "SprCit/vendor/Glad"
include "SprCit/vendor/imgui"



project "SprCit"
	location "SprCit"	
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "scpch.h"
	pchsource "SprCit/src/scpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}


	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"SC_BUILD_DLL",
			"SC_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "SC_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SC_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SC_DIST"
		runtime "Release"
		optimize "on"


project "Sandbox"
	location "Sandbox"	
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"SprCit/src",
		"SprCit/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"SprCit"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"SC_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SC_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SC_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SC_DIST"
		runtime "Release"
		optimize "on"


