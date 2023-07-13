add_library(${PROJECT_NAME} SHARED ${PROJECT_SRC})

if(NOT OUTPUT_PATH)
    set(OUTPUT_PATH ${CMAKE_SOURCE_DIR}/out/bin)
endif()

add_compile_definitions(PLATFORM_EXPORT)

include(base)
