workspace "chess"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "chess"

	location "chess"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin_obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Dependencies/glfw/include",
		"Dependencies/glew/include",
		"Dependencies/glm/glm",
		"%{prj.name}/src/vendor"
	}

	filter "system:windows"

		systemversion "latest"
		cppdialect "C++17"
		staticruntime "off"

		links
		{
			"glfw3",
			"opengl32",
			"User32",
			"Gdi32",
			"Shell32",
			"glew32s"
		}	

		libdirs
		{
			"Dependencies/glew/lib/Release/x64",
			"Dependencies/glfw/lib-vc2019"
		}

		defines
		{
			"GLEW_STATIC";
		}
	
	filter "system:macosx"

		cppdialect "C++17"
		staticruntime "off"

		links
		{
			"glfw3",
			"GLEW",
			"Cocoa.framework",
			"IOKit.framework",
			"Opengl.framework"
		}	

		libdirs
		{
			"Dependencies/glew/lib/Release/x64",
			"Dependencies/glfw_mac/lib-macos"
		}

		defines
		{
			"GLEW_STATIC";
		}

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"