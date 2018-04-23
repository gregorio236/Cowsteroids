#version 400
in vec2 TexCoords;

out vec4 color;

uniform sampler2D image;
uniform vec3 spriteColor;

void main()
{
	vec4 texel = texture(image, TexCoords);
	if(texel.a < 0.5)
		discard;
    color = vec4(spriteColor, 1.0) * texel;
}