cmake_minimum_required(VERSION 3.2)
project(ShockEngine)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/Core/Application.cpp src/Core/Application.hpp)
add_executable(ShockEngine ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(ShockEngine ${SFML_LIBRARIES})
endif()

find_package(THOR 2 REQUIRED)

if (THOR_FOUND)
    include_directories(${THOR_INCLUDE_DIR})
    target_link_libraries(ShockEngine ${THOR_LIBRARY})
endif()

find_package(SFGUI REQUIRED)

if (SFGUI_FOUND)
    include_directories(${SFGUI_INCLUDE_DIR})
    target_link_libraries(ShockEngine ${SFGUI_LIBRARY})
endif()