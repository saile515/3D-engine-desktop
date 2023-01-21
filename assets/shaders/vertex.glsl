#version 460 core

in vec3 vertexPosition;

uniform mat4 MVPMatrix;

void main(){
    gl_Position = MVPMatrix * vec4(vertexPosition, 1.0);
}