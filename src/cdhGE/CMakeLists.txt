file(GLOB CORE_SRCS core/*.cpp core/*.h)
file(GLOB UNIVERSE_SRCS universe/*.cpp universe/*.h)

set(
    SRCS
    export.h
    ${CORE_SRCS}
    ${UNIVERSE_SRCS}
)

add_library(
    cdhGE
    SHARED
    ${SRCS}
)

target_compile_definitions(
    cdhGE
    PRIVATE
    -DBUILDING_CDHGE
)

##########
# install
foreach (SRC ${SRCS})
    if (${SRC} MATCHES ".*\\.h$")
        get_filename_component(ABS_SRC ${SRC} ABSOLUTE)
        get_filename_component(ABS_DIR ${ABS_SRC} DIRECTORY)
        file(RELATIVE_PATH REL_DIR ${CMAKE_CURRENT_SOURCE_DIR} ${ABS_DIR})
        install(FILES ${SRC} DESTINATION include/cdhGE/${REL_DIR})
    endif ()
endforeach ()

install(
    TARGETS cdhGE
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

##################################
# TODO generate cdhGEConfig.cmake
