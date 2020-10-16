cmake_minimum_required (VERSION 3.16)
project (Platformer)


set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set_property(GLOBAL PROPERTY USE_FOLDERS On)


file(GLOB_RECURSE DATA_FILES data/*)
source_group("Data/" FILES ${DATA_FILES})
foreach(DATA ${DATA_FILES})
    get_filename_component(FILE_NAME ${DATA} NAME)
    get_filename_component(PATH_NAME ${DATA} DIRECTORY)
    get_filename_component(EXTENSION ${DATA} EXT)
    file(RELATIVE_PATH PATH_NAME "${PROJECT_SOURCE_DIR}" ${PATH_NAME})
    set(DATA_OUTPUT "${PROJECT_BINARY_DIR}/${PATH_NAME}/${FILE_NAME}")
    add_custom_command(
            OUTPUT ${DATA_OUTPUT}
            DEPENDS ${DATA}
            DEPENDS
            COMMAND ${CMAKE_COMMAND} -E copy ${DATA} "${PROJECT_BINARY_DIR}/${PATH_NAME}/${FILE_NAME}"
    )
    list(APPEND DATA_BINARY_FILES ${DATA_OUTPUT})
endforeach()

add_custom_target(
        DataTarget
        DEPENDS ${DATA_BINARY_FILES} ${DATA_FILES})

find_package(OpenGL REQUIRED)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(unofficial-box2d CONFIG REQUIRED)

include_directories(include/)

file(GLOB_RECURSE PLATFORMER_SRC src/*.cpp include/*.h)

add_executable(Platformer ${PLATFORMER_SRC})
add_dependencies(Platformer DataTarget)
target_link_libraries(Platformer PRIVATE sfml-graphics sfml-audio sfml-window sfml-system)

if(MSVC)
target_link_libraries(Platformer PRIVATE sfml-main FLAC OpenAL OpenGL Vorbis)
else()
target_link_libraries(Platformer PRIVATE X11 FLAC UDev OpenAL  ${OPENGL_LIBRARIES} )
endif()

target_link_libraries(Platformer PRIVATE unofficial::box2d::box2d)