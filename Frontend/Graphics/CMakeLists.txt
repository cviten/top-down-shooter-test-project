add_library(Graphics SFMLDrawer.cpp Graphics.cpp Graphics.h)

target_include_directories(Graphics PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(Graphics sfml-graphics sfml-window sfml-system)