#version 450

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexNormal;

uniform mat4 modelViewProjection;

out vec3 normal;

void main()
{
    gl_Position = modelViewProjection * vec4(vertexPosition, 1.0);
    normal = vertexNormal;
}
