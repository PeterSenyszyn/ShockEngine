cmake_minimum_required(VERSION 3.2)
project(ShockEngine)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/Core/Application.cpp include/Core/Application.hpp src/Input/InputManager.cpp include/Input/InputManager.hpp include/Input/KeyActionIds.hpp include/Input/Manager.hpp src/Core/State.cpp include/Core/State.hpp src/Core/StateStack.cpp include/Core/StateStack.hpp include/Core/StateIds.hpp src/States/GameState.cpp include/States/GameState.hpp src/States/PauseState.cpp include/States/PauseState.hpp src/Core/ContextBuffer.cpp include/Core/ContextBuffer.hpp src/Render/Diagnostics.cpp include/Render/Diagnostics.hpp src/Render/RenderedObject.cpp include/Render/RenderedObject.hpp include/Resource/ResourceHolder.hpp include/Resource/ResourceIdentifiers.hpp src/Render/RenderedObjectManager.cpp include/Render/RenderedObjectManager.hpp)
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