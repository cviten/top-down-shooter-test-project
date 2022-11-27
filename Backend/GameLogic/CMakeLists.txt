add_library(GameLogic GameEntites.h GameObject.h Bodies/CollisionBody.cpp Bodies/CollisionBody.h Bodies/VisualBody.cpp Bodies/VisualBody.h GameWorld.cpp GameWorld.h)

target_include_directories(GameLogic PUBLIC ${PROJECT_SOURCE_DIR}/Core)
target_link_libraries(GameLogic Core)