solution "memepool"
language "C++"
configurations { "Debug", "Release" }
includedirs { "include", "src/include" }
files { "include/**.h" }

defines { "MP_BUILD" }

if os.is("windows") then
	defines("WIN32")
end

configuration "Debug"
defines { "DEBUG" }
flags { "Symbols" }
targetdir "build/debug"

configuration "Release"
defines { "NDEBUG" }
flags { "OptimizeSpeed",
	"ExtraWarnings",
	"FatalWarnings",
	"NoFramePointer" }
targetdir "build/release"

project "memepool"
kind "StaticLib"
files { "src/**.c", "src/**.cpp" }

project "memepool-dynamic"
kind "SharedLib"
files { "src/**.c", "src/**.cpp" }
targetname "memepool"

project "tests"
kind "ConsoleApp"
files { "tests/**.cpp" }
links { "memepool" }
configuration "Debug"
postbuildcommands("build/debug/tests")
configuration "Release"
postbuildcommands("build/release/tests")
