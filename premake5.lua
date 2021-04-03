workspace "Yoghurt"
    architecture "x64"
    configurations {"Debug", "FastDebug", "Release"}


include "Yoghurt/externals/glfw"


project "Yoghurt"
    location "Yoghurt"

    kind "ConsoleApp"
    language "C++"

    targetdir "bin/%{cfg.buildcfg}-%{cfg.system}"
    objdir "bin-obj/%{cfg.buildcfg}-%{cfg.system}"

    files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}
    includedirs {"%{prj.name}/externals/plog/include", "%{prj.name}/externals/glfw/include"}
    links{"GLFW", "opengl32.lib"}

    filter "system:windows"
        defines {"WIN"}
        staticruntime "On"

    filter "configurations:Debug"
        defines {"YOG_DEBUG"}
        symbols "On"

    filter "configurations:FastDebug"
        defines {"YOG_DEBUG"}
        optimize "On"
        symbols "On"

    filter "configurations:Release"
        defines {"YOG_RELEASE"}
        optimize "On"