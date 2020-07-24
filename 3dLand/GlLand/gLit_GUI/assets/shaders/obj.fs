#version 440 core

out vec4 FragColor;

in vec4 VertexColor;
// in vec3 Position;
in vec2 TexCoords;

uniform sampler2D myTexture;

void main() {
  FragColor = texture(myTexture, TexCoords); //VertexColor;
}