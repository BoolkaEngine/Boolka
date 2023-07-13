if(OUTPUT_PATH)
    set(OUTPUT_PATH ${OUTPUT_PATH}/${PLATFORM_OS}${PLATFORM_ARCH})
    set_target_output(${PROJECT_NAME} ${OUTPUT_PATH})
endif()

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
