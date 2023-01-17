file(GLOB SRCS */*.cpp */*.h)

add_library(
  s3ge
  SHARED
  ${SRCS}
)

set_property(
  TARGET s3ge
  PROPERTY INTERFACE_INCLUDE_DIRECTORIES
  ${CMAKE_CURRENT_SOURCE_DIR}/../
)

target_link_libraries(
  s3ge
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
    install(FILES ${SRC} DESTINATION include/s3ge/${REL_DIR})
  endif ()
endforeach ()

install(
  TARGETS s3ge
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

##################################
# TODO generate s3geConfig.cmake
