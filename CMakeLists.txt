cmake_minimum_required(VERSION 3.23)
project(top_down_shooter)

set(CMAKE_CXX_STANDARD 17)

OPTION(SFML_ENABLE "SFML Integration" ON)

#configure_file(config.h.in config.h)
#configure_file (
#        "${PROJECT_SOURCE_DIR}/config.h.in"
#        "${PROJECT_BINARY_DIR}/config.h"
#)

add_subdirectory(Core)

add_subdirectory(Backend/GameLogic)
add_subdirectory(Frontend/Sound)
add_subdirectory(Frontend/Graphics)
add_subdirectory(Frontend/Input)

add_subdirectory(Tests)

add_executable(top_down_shooter main.cpp GameManager.cpp)

target_link_libraries(top_down_shooter GameLogic Graphics InputManager sfml-graphics sfml-window sfml-system)
