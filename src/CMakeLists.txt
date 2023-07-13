file(GLOB SUBDIRECTORIES LIST_DIRECTORIES true "*")

foreach(SUBDIRECTORY ${SUBDIRECTORIES})
    if(IS_DIRECTORY ${SUBDIRECTORY})
        add_subdirectory(${SUBDIRECTORY})
    endif()
endforeach()
