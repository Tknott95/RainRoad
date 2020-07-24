#version 440 core

in vec2 oTexCoords;
out vec4 outColor;

uniform sampler2D _text;
uniform vec3 _textColor;

void main() {
  vec4 sampled = vec4(1.0, 1.0, 1.0. texture(_text, oTexCoords).r);
  outColor = vec4(_textColor, 1.0) * sampled;
}