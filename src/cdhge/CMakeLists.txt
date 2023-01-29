file(GLOB SRCS */*.cpp */*.h)

add_library(
  cdhge
  SHARED
  ${SRCS}
)

set_property(
  TARGET cdhge
  PROPERTY INTERFACE_INCLUDE_DIRECTORIES
  ${CMAKE_CURRENT_SOURCE_DIR}/../
)

target_link_libraries(
  cdhge
  PUBLIC
  glm::glm
)

##########
# install
foreach (SRC ${SRCS})
  if (${SRC} MATCHES ".*\\.h$")
    get_filename_component(ABS_SRC ${SRC} ABSOLUTE)
    get_filename_component(ABS_DIR ${ABS_SRC} DIRECTORY)
    file(RELATIVE_PATH REL_DIR ${CMAKE_CURRENT_SOURCE_DIR} ${ABS_DIR})
    install(FILES ${SRC} DESTINATION include/cdhge/${REL_DIR})
  endif ()
endforeach ()

install(
  TARGETS cdhge
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

##################################
# TODO generate cdhgeConfig.cmake
