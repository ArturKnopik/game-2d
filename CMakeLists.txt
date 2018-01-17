
cmake_minimum_required(VERSION 3.1)

project(SFML_GAME)

set(CMAKE_BUILD_TYPE Release)

set(SFML_ROOT "C:/SFML-2.4.2")
set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "c:/SFML_GAME_PROJECT")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)
set(SOURCE_FILES main.cpp src/GameStates/MenuState.cpp include/GameStates/MenuState.h src/Buttoms/BasicButton.cpp include/Buttoms/BasicButton.h src/Buttoms/Button.cpp include/Buttoms/Button.h src/GameStates/GameState.cpp include/GameStates/GameState.h src/GameStates/PlayState.cpp include/GameStates/PlayState.h src/GameStates/PauseState.cpp include/GameStates/PauseState.h src/Blocks/Block.cpp include/Blocks/Block.h src/Blocks/Entity.cpp include/Blocks/Entity.h src/Game.cpp include/Game.h src/settings.cpp src/SomeRandomStaff/Test.cpp include/SomeRandomStaff/Test.h src/Systems/CollisionChecker.cpp include/Systems/CollisionChecker.h src/Systems/CreatureSpawner.cpp include/Systems/CreatureSpawner.h src/Blocks/Static.cpp include/Blocks/Static.h src/Blocks/Dynamic.cpp include/Blocks/Dynamic.h src/Blocks/Player.cpp include/Blocks/Player.h)

set(EXECUTABLE_NAME ${PROJECT_NAME})

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(SFML_STATIC_LIBRARIES ON)
find_package(SFML 2 REQUIRED graphics window system)
if (SFML_FOUND)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_DEPENDENCIES})
else()
message(SEND_ERROR "SFML library not found. Please set SFML_ROOT.")
endif()
