add_executable(Tests test-main.cpp gameTests.h)

target_include_directories(Tests PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(Tests Core GameLogic)
