cmake_minimum_required(VERSION 3.9)

project(3D-Engine-desktop)

#========== Global Configurations =============#
#----------------------------------------------#

# Set the C++ standard for all targets (It sets the flags
# (-std=c++11, -std=c++14 ...) on Clang or GCC. and /std=c++17 on MSVC
# OPTIONAL:
#---------------------------------
set(CMAKE_CXX_STANDARD 17)     
set(CMAKE_VERBOSE_MAKEFILE ON)

#========== Targets Configurations ============#

include(${PROJECT_SOURCE_DIR}/cmake/SourceList.cmake)

add_executable(engine ${engine_SRC})

# Set executable dependency libraries
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

find_package(glfw3 REQUIRED)
target_link_libraries(engine ${GLFW3_LIBRARY})
target_include_directories(engine PUBLIC ${GLFW3_INCLUDE_DIR})

list(APPEND CMAKE_PREFIX_PATH "C:/GLEW")

set(GLEW_USE_STATIC_LIBS true)

find_package(GLEW REQUIRED)
target_link_libraries(engine GLEW::glew_s)

find_package(OpenGL REQUIRED)
target_link_libraries(engine OpenGL::GL)

# Add extension .bin to executable name to make it easier
# to identify that the binary file is an executable.
if(UNIX)
  set_target_properties(engine PROPERTIES SUFFIX ".bin")
endif()

# Add target to run executable 
add_custom_target(run-ex1
    COMMAND engine 
    DEPENDS engine 
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)