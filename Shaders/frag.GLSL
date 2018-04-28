#version 400
in vec2 TexCoords;

out vec4 color;

uniform sampler2D image;
uniform vec3 spriteColor;
uniform float offset;
uniform int frameCount;

void main()
{
	float x = TexCoords.x/frameCount + offset;
	
	vec4 texel = texture(image, vec2(x, TexCoords.y));
	if(texel.a < 0.5)
		discard;
    color = vec4(spriteColor, 1.0) * texel;
}