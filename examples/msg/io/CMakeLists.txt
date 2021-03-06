cmake_minimum_required(VERSION 2.6)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_BINARY_DIR}")

add_executable(file file.c)
add_executable(file_unlink file_unlink.c)
add_executable(storage storage.c)
add_executable(remote remote.c)

### Add definitions for compile
if(NOT WIN32)
  target_link_libraries(file simgrid pthread)
  target_link_libraries(file_unlink simgrid pthread)
  target_link_libraries(remote simgrid pthread)
  target_link_libraries(storage simgrid pthread)
else()
  target_link_libraries(file simgrid)
  target_link_libraries(file_unlink simgrid)
  target_link_libraries(remote simgrid)
  target_link_libraries(storage simgrid)
endif()

set(tesh_files
  ${tesh_files}
  ${CMAKE_CURRENT_SOURCE_DIR}/io.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/storage.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/remote.tesh
  PARENT_SCOPE
  )
set(xml_files
  ${xml_files}
  PARENT_SCOPE
  )
set(examples_src
  ${examples_src}
  ${CMAKE_CURRENT_SOURCE_DIR}/file.c
  ${CMAKE_CURRENT_SOURCE_DIR}/file_unlink.c
  ${CMAKE_CURRENT_SOURCE_DIR}/storage.c
  ${CMAKE_CURRENT_SOURCE_DIR}/remote.c
  PARENT_SCOPE
  )
set(bin_files
  ${bin_files}
  PARENT_SCOPE
  )
set(txt_files
  ${txt_files}
  PARENT_SCOPE
  )
