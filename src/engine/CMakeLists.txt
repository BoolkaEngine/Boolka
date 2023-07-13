project(engine)

file(GLOB_RECURSE PROJECT_SRC "*.cc")

include(dll)

find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC glfw OpenGL::GL)
