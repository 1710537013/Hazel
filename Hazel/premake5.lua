workspace "Hazel"     --这是解决方案的名字
    architecture "x64"
    configurations {"Debug", "Release", "Dist"}
    --Debug完全打开调试代码，通常用于开发
    --Release是开启优化

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" --system 表示是Mac还是Windows

IncludeDir = {}
IncludeDir["GLFW"] = "Hazel/vendor/GLFW/include"
IncludeDir["Glad"] = "Hazel/vendor/Glad/include"
IncludeDir["ImGui"] = "Hazel/vendor/ImGui"
IncludeDir["glm"] = "Hazel/vendor/glm"

include"Hazel/vendor/GLFW"  --将GLFW的.lua配置包含进来
include"Hazel/vendor/Glad"  --将Glad的.lua配置包含进来
include"Hazel/vendor/ImGui"  --将Glad的.lua配置包含进来

project "Hazel" -- 项目名字
    location "Hazel" --相当于cd，切换当前目录到Hazel，接了来生成的文件都在Hazel 下
    kind "SharedLib"  -- 指定生成exe、lib还是dll，这里SharedLIb和dll一个意思
    language "C++"
    
    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir ("bin-int/"..outputdir.."/%{prj.name}")   
    --这里写 bin-int是为了让生成的bin和中间文件排在一起好删除 ..是lua中的连接符
    
    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
    }   -- **递归

    includedirs{
        "%{prj.name}/vendor/spd/include", 
        "%{prj.name}/src", 
        "%{IncludeDir.GLFW}", 
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
    }


    links{
        "GLFW",
        "opengl32.lib",
        "dwmapi.lib",
        "Glad"
        --"ImGui"
    }

    pchheader "hzpch.h"
    pchsource "%{prj.name}/src/hzpch.cpp"

    filter"system:windows" --条件过滤器，接下来设置仅在目标系统是 Windows 时生效。
     cppdialect"C++17"  -- 指定 C++ 标准，缩进无所谓
     staticruntime "On"  --将 C++ 运行时库静态链接到项目中
     systemversion "latest"  -- 或是在属性哪里看，如：10.0.17134.0
     defines{"HZ_PLATFORM_WINDOWS","HZ_BUILD_DLL","GLFW_INCLUDE_NONE"}  --相当于预定义

     postbuildcommands{("{COPY} %{cfg.buildtarget.relpath} ../bin/"..outputdir.. "/Sandbox" )} 
    filter"configurations:Debug"
       defines"HZ_DEBUG"
       buildoptions "/MDd"
       symbols"On"
       
    filter"configurations:Release"
       defines"HZ_RELEASE"
       buildoptions "/MD"
       optimize"On"
     filter"configurations:Dist"
       defines"HZ_DIST"
       buildoptions "/MD"
       optimize"On"
project "Sandbox" 
    location "Sandbox" 
    kind "ConsoleApp"  
    language "C++"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir ("bin-int/"..outputdir.."/%{prj.name}")   
    
    files{"%{prj.name}/src/**.h",  "%{prj.name}/src/**.cpp"}  
    includedirs{
        "Hazel/vendor/spd/include", 
        "Hazel/src",
        "%{IncludeDir.glm}",
        "%{IncludeDir.ImGui}"
    }

    links{"Hazel"}
    filter"system:windows" 
     cppdialect"C++17"  
     staticruntime "On"
     systemversion "latest" 
     defines{"HZ_PLATFORM_WINDOWS"} 

    filter"configurations:Debug"
       defines"HZ_DEBUG"
       buildoptions "/MDd"
       symbols"On"
    filter"configurations:Release"
       defines"HZ_RELEASE"
       buildoptions "/MD"
       optimize"On"
     filter"configurations:Dist"
       defines"HZ_DIST"
       buildoptions "/MD"
       optimize"On"