#version 400
layout (location = 0) in vec4 vertex; // vec2 pos + vec2 texPos

out vec2 TexCoords;

uniform mat4 model;
uniform mat4 projection;
uniform float z;

void main()
{
	TexCoords = vertex.zw;
    gl_Position = projection * model * vec4(vertex.xy, z, 1.0);
}