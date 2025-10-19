cmake_minimum_required(VERSION 3.16)
project(mcdpcm LANGUAGES C)
set(CMAKE_C_STANDARD 90)

add_executable(mcdpcm
	"src/helpers.c"
	"src/main.c"
	"src/wav.c"
)
	
install(TARGETS mcdpcm)