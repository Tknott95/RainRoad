#version 440 core

out vec4 FragColor;
in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture0;
uniform vec3 lightColor;

void main() {
  FragColor = texture(texture0, TexCoord); // * vec4(ourColor, 1.0);
  //FragColor = vec4(ourColor, TexCoord);
  // vec4(texture0, TexCoord) * vec4(ourColor, 1.0);
}
