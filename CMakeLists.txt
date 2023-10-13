cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
# Name of the project (will be the name of the plugin)
project(nodeml_opencv)

include(${CMAKE_SOURCE_DIR}/utils.cmake)

set(OPENCV_VERSION 4.8.1)
set(CMAKE_CXX_STANDARD 17)

set(OPENCV_DEPS_DIR "${CMAKE_SOURCE_DIR}/deps/dynamic/opencv")
list(APPEND CMAKE_PREFIX_PATH ${OPENCV_DEPS_DIR})

list(APPEND CMAKE_PREFIX_PATH)
# GetNodeMlLib(NODEML_TORCH_DIR "torch")


# Build a shared library named after the project from the files in `src/`
file(GLOB SOURCE_FILES "src/*.cc" "src/*.h")

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC} ${NODEML_TORCH_SOURCE_FILES})

# Gives our library file a .node extension without any "lib" prefix
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

# Essential include files to build a node addon,
# You should add this line in every CMake.js based project
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_JS_INC})


# Include N-API wrappers
IncludeNapi(${PROJECT_NAME})

# Build Opencv
if(NOT EXISTS ${OPENCV_DEPS_DIR})
  execute_process(
    COMMAND git clone --depth 1 --branch ${OPENCV_VERSION} https://github.com/opencv/opencv
  )
  execute_process(
    COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release -S "${CMAKE_CURRENT_BINARY_DIR}/opencv/" -B "${CMAKE_CURRENT_BINARY_DIR}/opencv/build/"
  )
  execute_process(
    COMMAND ${CMAKE_COMMAND} --build "${CMAKE_CURRENT_BINARY_DIR}/opencv/build" --config Release
  )
  execute_process(
    COMMAND ${CMAKE_COMMAND} --install "${CMAKE_CURRENT_BINARY_DIR}/opencv/build" --prefix ${OPENCV_DEPS_DIR}
  )
  file(REMOVE_RECURSE ${CMAKE_SOURCE_DIR}/opencv)
endif()


#Open CV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS}) # not needed for opencv>=4.0
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_include_directories(${PROJECT_NAME} PRIVATE "${OPENCV_DEPS_DIR}/include")


# Essential library files to link to a node addon
# You should add this line in every CMake.js based project
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})



if (MSVC)
  file(GLOB OPENCV_DLLS "${OPENCV_DEPS_DIR}/x64/vc17/bin/*.dll")
  add_custom_command(TARGET ${PROJECT_NAME}
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${OPENCV_DLLS}
                     $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif (MSVC)