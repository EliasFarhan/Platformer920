cmake_minimum_required (VERSION 3.16)
project (Platformer)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(unofficial-box2d CONFIG REQUIRED)

include_directories(include/)

file(GLOB_RECURSE PLATFORMER_SRC src/*.cpp include/*.h)

add_executable(Platformer ${PLATFORMER_SRC})
target_link_libraries(Platformer PRIVATE sfml-graphics sfml-audio sfml-window sfml-system)
if(MSVC)
target_link_libraries(Platformer PRIVATE sfml-main FLAC OpenAL OpenGL Vorbis)
else()
target_link_libraries(Platformer PRIVATE X11 FLAC UDev OpenAL)
endif()
target_link_libraries(Platformer PRIVATE unofficial::box2d::box2d)