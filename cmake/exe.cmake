if(PLATFORM_WINDOWS)
    add_executable(${PROJECT_NAME} WIN32 ${PROJECT_SRC})
else()
    add_executable(${PROJECT_NAME} ${PROJECT_SRC})
endif()

if(NOT OUTPUT_PATH)
    set(OUTPUT_PATH ${CMAKE_SOURCE_DIR}/out/bin)
endif()

include(base)
