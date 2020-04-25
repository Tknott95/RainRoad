#include "../headers/draw.h"
#include "../headers/utils/cube_vertices.h"

void Draw::init() {
  // const char* vertexSource = R"glsl(
  //   #version 150 core
  //   in vec2 position;
  //   void main()
  //   {
  //     gl_Position = vec4(position, 0.0, 1.0);
  //   }
  // )glsl";

  // const char* fragmentSource = R"glsl(
  // #version 150 core
  // out vec4 outColor;
  // void main()
  // {
  //   outColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);    }
  // )glsl";

  shader0.compile("src/shaders/basic/gl.vs", "src/shaders/basic/gl.fs");

  float vertices[] = {
    0.0f, 0.5f,
    0.5f, -0.5f,
    -0.5f, -0.5f
  };

  // creating a vertexArrayObject
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);
  glBindVertexArray(vao);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  // glShaderSource(vertexShader, 1, &vertexSource, NULL);
  // glCompileShader(vertexShader);

  // GLint status;
  // // glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
  // // // grabbing compile log
  // // char buffer[512];
  // // glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
  // // fragmentShader
  // // @TODO double check glsl for frag shader
  // GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  // glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
  // glCompileShader(fragmentShader);

  // shader0.use();
  // shader0.setMat4("position", )


  // GLuint shaderProgram = glCreateProgram();
  // glAttachShader(shaderProgram, vertexShader);
  // glAttachShader(shaderProgram, fragmentShader);
  // glBindFragDataLocation(shaderProgram, 0, "outColor");
  // glLinkProgram(shaderProgram);
  // glUseProgram(shaderProgram);
  // GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
  // glEnableVertexAttribArray(posAttrib);
  // glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
}

void Draw::update() {
  shader0.use();
  glBindVertexArray(vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}