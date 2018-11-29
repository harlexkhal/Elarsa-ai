workspace "Elarsa"

   platforms
   {
   	   "x86",
	   "x64"
   }

   configurations
   {
   	   "Debug",
	   "Release"
   }

   outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Case_Sensitivity"
   location "Case_Sensitivity"
   kind "SharedLib"
   language "C++"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("objdir/" .. outputdir .. "/%{prj.name}")

   files
   {
   	   "%{prj.name}/header/**.h",
	   "%{prj.name}/src/**.cpp"
   }

   includedirs
   {
   "%{prj.name}/header/"
   }

   filter "system:windows"
   cppdialect "C++17"
   staticruntime "On"
   systemversion "latest"

   defines
   {
   "API_SUPPORT_DLL", 
   
   "_WINDLL"
   }

   postbuildcommands
   {
     "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Elarsa"
   }

   filter "configurations:Debug"
   defines "ES_DEBUG"
   optimize "On"

   filter "configurations:Release"
   defines "ES_RELEASE"
   optimize "Off"




 project "Elarsa"
   location "Elarsa"
   kind "ConsoleApp"
   language "C++"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("objdir/" .. outputdir .. "/%{prj.name}")

   files
   {
	   "%{prj.name}/core_src/**.cpp"
   }

   links
   {
   	   "Case_Sensitivity"
   }

   includedirs
   {
   "Case_Sensitivity/header/"
   }

   filter "system:windows"
   cppdialect "C++17"
   staticruntime "On"
   systemversion "latest"

   

   filter "configurations:Debug"
   defines "ES_DEBUG"
   optimize "On"

   filter "configurations:Release"
   defines "ES_RELEASE"
   optimize "Off"