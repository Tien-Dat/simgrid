cmake_minimum_required(VERSION 2.6)

if(1)
#  add_custom_target(tesh ALL
#    DEPENDS ${CMAKE_HOME_DIRECTORY}/buildtools/Cmake/Scripts/tesh.pl
#    COMMENT "Install ${CMAKE_HOME_DIRECTORY}/buildtools/Cmake/Scripts/tesh.pl"
#    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_HOME_DIRECTORY}/buildtools/Cmake/Scripts/tesh.pl ${CMAKE_BINARY_DIR}/bin/tesh
#    )
    configure_file("${CMAKE_HOME_DIRECTORY}/buildtools/Cmake/Scripts/tesh.pl"
  "${CMAKE_BINARY_DIR}/bin/tesh" @ONLY IMMEDIATE)

    file(COPY        ${CMAKE_HOME_DIRECTORY}/buildtools/Cmake/Scripts/Diff.pm
         DESTINATION ${CMAKE_BINARY_DIR}/bin
         FILE_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                          GROUP_EXECUTE GROUP_READ)

else()
  set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

  add_executable(tesh tesh.c run_context.c signal.c)

  ### Add definitions for compile
  target_link_libraries(tesh simgrid m pthread)
endif()

set(tesh_files
  ${tesh_files}
  ${CMAKE_CURRENT_SOURCE_DIR}/setenv.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/set-output-ignore.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/set-output-sort.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/set-output-sort-1.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/set-return.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/set-signal.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/set-timeout.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/background.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/basic.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/bg-basic.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/bg-set-signal.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/catch-return.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/catch-signal.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/catch-timeout.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/catch-wrong-output.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/cd.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/IO-bigsize.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/IO-broken-pipe.tesh
  ${CMAKE_CURRENT_SOURCE_DIR}/IO-orders.tesh
  PARENT_SCOPE
  )
set(xml_files
  ${xml_files}
  PARENT_SCOPE
  )
set(tools_src
  ${tools_src}
  ${CMAKE_CURRENT_SOURCE_DIR}/run_context.c
  ${CMAKE_CURRENT_SOURCE_DIR}/run_context.h
  ${CMAKE_CURRENT_SOURCE_DIR}/signal.c
  ${CMAKE_CURRENT_SOURCE_DIR}/tesh.c
  ${CMAKE_CURRENT_SOURCE_DIR}/tesh.h
  PARENT_SCOPE
  )
set(bin_files
  ${bin_files}
  ${CMAKE_CURRENT_SOURCE_DIR}/colorize.pl
  ${CMAKE_CURRENT_SOURCE_DIR}/generate_tesh
  PARENT_SCOPE
  )
set(txt_files
  ${txt_files}
  ${CMAKE_CURRENT_SOURCE_DIR}/README
  ${CMAKE_CURRENT_SOURCE_DIR}/tesh.1
  PARENT_SCOPE
  )
