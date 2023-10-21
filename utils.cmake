function(DownloadBuiltDep DEPENDENCY VERSION DESTINATION)
  if(WIN32)
    set(PLATFORM win)
  else()
    set(PLATFORM linux)
  endif()

  if(NOT EXISTS ${DESTINATION}/${DEPENDENCY})
    file(DOWNLOAD https://github.com/nodeml/deps/releases/download/${DEPENDENCY}-${PLATFORM}-${VERSION}/${DEPENDENCY}.zip ${CMAKE_CURRENT_SOURCE_DIR}/${DEPENDENCY}.zip SHOW_PROGRESS)
    message(STATUS "Extracting")
    file(ARCHIVE_EXTRACT INPUT ${CMAKE_CURRENT_SOURCE_DIR}/${DEPENDENCY}.zip DESTINATION ${DESTINATION})
    message(STATUS "Done Extracting")
    file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/${DEPENDENCY}.zip)
  endif()
endfunction()

macro(IncludeNapi project_name)
    # Include N-API wrappers
    execute_process(COMMAND node -p "require('node-addon-api').include"
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            OUTPUT_VARIABLE NODE_ADDON_API_DIR
            )
    string(REPLACE "\n" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
    string(REPLACE "\"" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
    target_include_directories(${project_name} PRIVATE ${NODE_ADDON_API_DIR})
    add_definitions(-DNAPI_VERSION=3)
endmacro()