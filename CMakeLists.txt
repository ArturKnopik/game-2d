
cmake_minimum_required(VERSION 3.1)

project(SFML_GAME)

set(CMAKE_BUILD_TYPE Release)

set(SFML_ROOT "C:/SFML-2.4.2")
set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "c:/SFML_GAME_PROJECT")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)
set(SOURCE_FILES main.cpp)

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
