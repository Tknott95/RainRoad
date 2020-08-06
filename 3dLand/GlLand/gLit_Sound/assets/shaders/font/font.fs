#version 440 core

in vec2 oTexCoords;
out vec4 outColor;

uniform sampler2D text;
uniform vec3 textColor;

void main() {
  vec4 _textColor = texture(text, oTexCoords).rgba;
  if(_textColor.a < 0.1) discard;
  outColor = vec4(textColor, 1.0) * _textColor;
}