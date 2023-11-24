function(BuildOpenCV VERSION DESTINATION RESULT)
  if(NOT EXISTS ${DESTINATION}/opencv)
    set(CLONED_DIR ${CMAKE_CURRENT_BINARY_DIR}/opencv)
    execute_process(
      COMMAND git clone --depth 1 --branch ${OPENCV_VERSION} https://github.com/opencv/opencv ${CLONED_DIR}
    )

    execute_process(
      COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release -DWITH_TBB=ON -DWITH_OPENMP=ON -DWITH_IPP=ON -DBUILD_EXAMPLES=OFF -DBUILD_DOCS=OFF -DBUILD_PERF_TESTS=OFF -DBUILD_TESTS=OFF -DWITH_CSTRIPES=ON -DWITH_OPENCL=ON -S ${CLONED_DIR} -B ${CLONED_DIR}/build/
    )

    execute_process(
      COMMAND ${CMAKE_COMMAND} --build ${CLONED_DIR}/build --config Release
    )

    execute_process(
      COMMAND ${CMAKE_COMMAND} --install ${CLONED_DIR}/build --prefix ${DESTINATION}/opencv
    )
  endif()

  set(${RESULT} ${DESTINATION}/opencv PARENT_SCOPE)
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