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

# Get the version from the package.json
function(GetVersion)
  file(READ ${CMAKE_SOURCE_DIR}/package.json PACKAGE_JSON)
  string(JSON PACKAGE_VERSION GET ${PACKAGE_JSON} version)
  set(PACKAGE_VERSION ${PACKAGE_VERSION} PARENT_SCOPE)
endfunction()

# generate node.lib
function(GenerateNodeLib)
  if(MSVC AND CMAKE_JS_NODELIB_DEF AND CMAKE_JS_NODELIB_TARGET)
    # Generate node.lib
    execute_process(COMMAND ${CMAKE_AR} /def:${CMAKE_JS_NODELIB_DEF} /out:${CMAKE_JS_NODELIB_TARGET} ${CMAKE_STATIC_LINKER_FLAGS})
  endif()
endfunction()