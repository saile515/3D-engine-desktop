#version 330 core
layout(location = 0) in vec3 vertexPosition;

uniform mat4 MVPMatrix;

void main(){
    gl_Position = MVPMatrix * vec4(vertexPosition, 1.0);
}