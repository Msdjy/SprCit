workspace "SprCit"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SprCit"
	location "SprCit"	
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

		defines
		{
			"SC_BUILD_DLL",
			"SC_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SC_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"	
	kind "ConsoleApp"
	language "C++"

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
		staticruntime "On"
		systemversion "10.0"

		defines
		{
			"SC_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SC_DIST"
		optimize "On"


