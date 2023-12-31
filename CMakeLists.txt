cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
# Name of the project (will be the name of the plugin)


include(${CMAKE_SOURCE_DIR}/utils.cmake)

GetVersion()

project(nodeml_opencv VERSION ${PACKAGE_VERSION})

set(OPENCV_VERSION 4.8.1)

set(CMAKE_CXX_STANDARD 17)

# Build a shared library named after the project from the files in `src/`
file(GLOB_RECURSE SOURCE_FILES "src/*.cc" "src/*.h")

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC})

# Gives our library file a .node extension without any "lib" prefix
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

# Essential include files to build a node addon,
# You should add this line in every CMake.js based project
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_JS_INC})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)

#Build OpenCV
BuildOpenCV(${OPENCV_VERSION} ${CMAKE_SOURCE_DIR}/deps OPENCV_DEPS_DIR)
list(APPEND CMAKE_PREFIX_PATH ${OPENCV_DEPS_DIR})

#Open CV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS}) # not needed for opencv>=4.0
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})
target_include_directories(${PROJECT_NAME} PRIVATE ${OPENCV_DEPS_DIR}/include)


GenerateNodeLib()

if (MSVC)
  file(GLOB OPENCV_DLLS "${OPENCV_DEPS_DIR}/x64/vc17/bin/*.dll")
  add_custom_command(TARGET ${PROJECT_NAME}
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${OPENCV_DLLS}
                     $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif (MSVC)