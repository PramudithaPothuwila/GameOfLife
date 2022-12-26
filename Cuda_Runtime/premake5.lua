project "Cuda_Runtime"
    kind "StaticLib"
    language "C++"       
    cppdialect "C++17"
    staticruntime "on"
    targetdir "bin/%{cfg.buildcfg}"
    
	files {"src/**.cuh", "src/**.cu"}

    filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "RELEASE" }
      optimize "On"