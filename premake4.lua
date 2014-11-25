-- A solution contains projects, and defines the available configurations
solution "Walkers"
   configurations { "Debug", "Release" }
   includedirs {"/usr/local/include", "include", "lib"}
   links {"SDL2", "SDL2_image", "SDL2_ttf", "SDL2_mixer" }
   libdirs {"/usr/local/lib", "lib"}
   kind "ConsoleApp"
   buildoptions {"-Wall", "-std=c++11" }
   language "C++"
 
   -- A project defines one build target
   project "walkers"
      files { "src/**.h", "src/**.cpp", "lib/jsoncpp.cpp" }
      excludes { "test/*" }
 
      configuration "Debug"
         defines { "DEBUG" }
         flags { "Symbols" }
 
      configuration "Release"
         defines { "NDEBUG" }
         flags { "Optimize" }

