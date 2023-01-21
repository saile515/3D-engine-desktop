# CMakeList.txt : CMake project for CMake-test, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("3D-Engine-Desktop")

# Add source to this project's executable.
add_executable (engine

"src/main.cpp" 

"src/core/Engine.cpp" 
"src/core/Engine.h" 
"src/core/Scene.cpp" 
"src/core/Scene.h"  
"src/core/Window.cpp"
"src/core/Window.h"
"src/core/Component.cpp"
"src/core/Component.h"
"src/core/Object.cpp"
"src/core/Object.h"
"src/core/Vector3.cpp"
"src/core/Vector3.h"

"src/objects/Camera.cpp"
"src/objects/Camera.h"

"src/components/Transform.cpp"
"src/components/Transform.h"
"src/components/Mesh.cpp"
"src/components/Mesh.h"
"src/components/Shader.cpp"
"src/components/Shader.h"

"src/utils/loadShader.cpp"
"src/utils/loadShader.h"

)

find_package(GLEW REQUIRED)
target_link_libraries(engine PRIVATE GLEW::GLEW)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(engine PRIVATE glfw)

find_package(glm CONFIG REQUIRED)
target_link_libraries(engine PRIVATE glm::glm)

find_package(OpenGL REQUIRED)
target_link_libraries(engine PRIVATE OpenGL::GL)

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