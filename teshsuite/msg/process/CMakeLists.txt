cmake_minimum_required(VERSION 2.6)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_BINARY_DIR}")

add_executable(process process.c)

### Add definitions for compile
target_link_libraries(process simgrid)

set(tesh_files
  ${tesh_files}
  ${CMAKE_CURRENT_SOURCE_DIR}/process.tesh
  PARENT_SCOPE
  )
set(xml_files
  ${xml_files}
  ${CMAKE_CURRENT_SOURCE_DIR}/process_d.xml
  PARENT_SCOPE
  )
set(teshsuite_src
  ${teshsuite_src}
  ${CMAKE_CURRENT_SOURCE_DIR}/process.c
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
