#include "../headers/shader.h"

/* @TODO - clean this shit up, make a switch and single function? Will it slow down speed? */
void Shader::compile(const char* vertPath, const char* fragPath, const char* geometrySource) {
  const char* geometryPath = nullptr;
  std::string vertexCode, fragmentCode, geometryCode;
  std::ifstream vShaderFile, fShaderFile, gShaderFile;

  try {
    vShaderFile.open(vertPath);
    fShaderFile.open(fragPath);
    std::stringstream vShaderStream, fShaderStream;
    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();		
    vShaderFile.close();
    fShaderFile.close();

    vertexCode = vShaderStream.str();
    fragmentCode = fShaderStream.str();

    if(geometryPath != nullptr) {
      gShaderFile.open(geometryPath);
      std::stringstream gShaderStream;
      gShaderStream << gShaderFile.rdbuf();
      gShaderFile.close();
      geometryCode = gShaderStream.str();
    }
  } catch (std::ifstream::failure& e) {
    printf("\n\e[0;31;40m SHADER FILE NOT READ \e[0m");
  }
  

  const char* vShaderCode = vertexCode.c_str();
  const char * fShaderCode = fragmentCode.c_str();
  unsigned int vertex, fragment, geometry;

  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vShaderCode, NULL);
  glCompileShader(vertex);
  checkCompileErrors(vertex, "VERTEX");

  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fShaderCode, NULL);
  glCompileShader(fragment);
  checkCompileErrors(fragment, "FRAGMENT");

  if(geometryPath != nullptr) {
    const char * gShaderCode = geometryCode.c_str();
    geometry = glCreateShader(GL_GEOMETRY_SHADER);
    glShaderSource(geometry, 1, &gShaderCode, NULL);
    glCompileShader(geometry);
    checkCompileErrors(geometry, "GEOMETRY");
  }
  ID = glCreateProgram();
  glAttachShader(ID, vertex);
  glAttachShader(ID, fragment);
  if(geometryPath != nullptr)
      glAttachShader(ID, geometry);
  glLinkProgram(ID);
  checkCompileErrors(ID, "PROGRAM");
  // delete the shaders as they're linked into our program now and no longer necessery
  glDeleteShader(vertex);
  glDeleteShader(fragment);
  if(geometryPath != nullptr) glDeleteShader(geometry);
  printf("\n  \e[96;40m  Shader(%d) Compiled \e[0m\n", ID);
}

void Shader::use() { 
  glUseProgram(ID); 
}
void Shader::setBool(const std::string &name, bool value) const {         
   glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
}
void Shader::setInt(const std::string &name, int value) const { 
  glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
}
void Shader::setFloat(const std::string &name, float value) const { 
  glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
}
void Shader::setVec2(const std::string &name, const glm::vec2 &value) const { 
  glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
}
void Shader::setVec2(const std::string &name, float x, float y) const { 
  glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y); 
}
void Shader::setVec3(const std::string &name, const glm::vec3 &value) const { 
  glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
}
void Shader::setVec3(const std::string &name, float x, float y, float z) const { 
  glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z); 
}
void Shader::setVec4(const std::string &name, const glm::vec4 &value) const { 
  glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
}
void Shader::setVec4(const std::string &name, float x, float y, float z, float w) { 
  glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w); 
}
void Shader::setMat2(const std::string &name, const glm::mat2 &mat) const {
  glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
void Shader::setMat3(const std::string &name, const glm::mat3 &mat) const {
  glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
void Shader::setMat4(const std::string &name, const glm::mat4 &mat) const {
  glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::checkCompileErrors(GLuint shader, std::string type) {
  GLint success;
  GLchar infoLog[1024];
  if(type != "PROGRAM") {
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success) {
      glGetShaderInfoLog(shader, 1024, NULL, infoLog);
      std::cout << "\n\e[0;31;40m SHADER COMPILING ERROR: " << type << "\n" << infoLog << "\e[0m" << std::endl;
    }
  } else {
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if(!success) {
      glGetProgramInfoLog(shader, 1024, NULL, infoLog);
      std::cout << "\n\e[0;31;40m LINKING PROGRAM ERROR: " << type << "\n" << infoLog << "\e[0m" << std::endl;
    }
  }
}