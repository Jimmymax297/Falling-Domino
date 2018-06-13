#version 300 es
in lowp vec3 TexCoords;
out lowp vec4 color;

uniform samplerCube Roombox;

void main()
{    
    color = texture(Roombox, TexCoords);
}