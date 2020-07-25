#version 440 core

in vec2 oTexCoords;
out vec4 outColor;

uniform sampler2D text;
uniform vec3 textColor;

void main() {
  vec4 texColor = texture(text, oTexCoords).rgba;
  if(texColor.a < 0.1) discard;
  vec4 sampled = vec4(1.0, 1.0, 1.0, texColor); /* was .r */
  outColor = vec4(textColor, 1.0) * sampled;
}