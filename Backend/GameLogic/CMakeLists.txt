add_library(GameLogic GameObject.h Bodies/CollisionBody.cpp Bodies/CollisionBody.h Bodies/VisualBody.cpp Bodies/VisualBody.h GameWorld.cpp GameWorld.h GameObjects/GaneObjects.h Bodies/Body.h Level.h GameLog.cpp GameLog.h)

target_include_directories(GameLogic PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(GameLogic Core)