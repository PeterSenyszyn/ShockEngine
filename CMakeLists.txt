cmake_minimum_required(VERSION 3.2)
project(ShockEngine)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -lz")
set(SOURCE_FILES main.cpp src/Core/Application.cpp include/Core/Application.hpp src/Input/InputManager.cpp include/Input/InputManager.hpp include/Input/KeyActionIds.hpp include/Input/Manager.hpp src/Core/State.cpp include/Core/State.hpp src/Core/StateStack.cpp include/Core/StateStack.hpp include/Core/StateIds.hpp src/States/GameState.cpp include/States/GameState.hpp src/States/PauseState.cpp include/States/PauseState.hpp src/Core/ContextBuffer.cpp include/Core/ContextBuffer.hpp src/Render/Diagnostics.cpp include/Render/Diagnostics.hpp src/Render/RenderedObject.cpp include/Render/RenderedObject.hpp include/Resource/ResourceHolder.hpp include/Resource/ResourceIdentifiers.hpp src/Render/RenderedObjectManager.cpp include/Render/RenderedObjectManager.hpp src/Render/TileMap.cpp include/Render/TileMap.hpp include/Utilities/String/StringUtils.hpp include/Utilities/Math/Matrix.hpp src/Game/World.cpp include/Game/World.hpp src/Game/Instance.cpp include/Game/Instance.hpp src/Game/InstanceManager.cpp include/Game/InstanceManager.hpp src/Game/Entity.cpp include/Game/Entity.hpp include/Utilities/File/Filepath.hpp)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML REQUIRED system window graphics network audio)
find_package(THOR 2 REQUIRED)
find_package(SFGUI REQUIRED)

include_directories(${SFML_INCLUDE_DIR})
include_directories(${THOR_INCLUDE_DIR})
include_directories(${SFGUI_INCLUDE_DIR})

add_executable(ShockEngine ${SOURCE_FILES})

target_link_libraries(ShockEngine ${SFML_LIBRARIES})
target_link_libraries(ShockEngine ${THOR_LIBRARY})
target_link_libraries(ShockEngine ${SFGUI_LIBRARY})