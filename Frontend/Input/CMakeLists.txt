add_library(InputManager InputManager.cpp InputManager.h)

target_include_directories(InputManager PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(InputManager sfml-window sfml-system)