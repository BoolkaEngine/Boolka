project(game)

file(GLOB_RECURSE PROJECT_SRC "*.cc")

include(dll)

target_link_libraries(${PROJECT_NAME} PUBLIC engine)
