#include "../headers/mesh.h"

Mesh::Mesh(bool _isSkybox, vec3 _pos, const char* _objPath, const char* _texturePath) : isSkybox(_isSkybox), pos(_pos) {
  if(!isSkybox) {
    shader.compile("assets/shaders/obj/obj.vs", "assets/shaders/obj/obj.fs");
    encodedObj = objLoader.load(_objPath);
  } else shader.compile("assets/shaders/skybox/skybox.vs", "assets/shaders/skybox/skybox.fs");

  printf("\n    \e[0;46;40mCompiling mesh:  \e[0;92;40m%s\e[0;46;40m\n     - at \e[0;92;40mpos(%.2f, %.2f, %.2f) \e[0m", _objPath, pos.x, pos.y, pos.z);

  /**** Init Mesh() ****/
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  if(!isSkybox) {
    glGenBuffers(1, &EBO);
    glGenBuffers(1, &UVBO);
  };

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  if(!isSkybox) glBufferData(GL_ARRAY_BUFFER, encodedObj.vertices.size() * sizeof(vec3), &encodedObj.vertices[0], GL_STATIC_DRAW);
  if(isSkybox) glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);

  glActiveTexture(GL_TEXTURE0);
  if(!isSkybox) glBindTexture(GL_TEXTURE_2D, textureID);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(
    0,3,
    GL_FLOAT, /* type */
    GL_TRUE, /* isNormalized? */
    sizeof(vec3), /* stride - matches my data xyz|vec3*/
    (void*)0 /* array buffer offset @TODO offset others proper via: 3, 6, etc. Offset of <n, n, n(i) ...>, spliced after n(i) in the tuple/arr */
  );
  glEnableVertexAttribArray(1);

  if(!isSkybox) {
    glBindBuffer(GL_ARRAY_BUFFER, UVBO);
    glBufferData(GL_ARRAY_BUFFER, encodedObj.uvs.size() * sizeof(vec2), &encodedObj.uvs[0], GL_STATIC_DRAW);
    
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vec2), (void*)0);
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, objLoader.vertIndices.size() * sizeof(uint), &objLoader.vertIndices[0], GL_STATIC_DRAW);
  };
  glBindVertexArray(0); /* may not need */
  
  if(!isSkybox) {
    this->textureID = texture.load(_texturePath, GL_REPEAT);

    shader.use();
    shader.setInt("myTexture", 0);
  } else {
    const string loc = "assets/skybox/";
    vector<string> skyboxFaces = {
      loc+"right.jpg", loc+"left.jpg",
      loc+"top.jpg",   loc+"bottom.jpg",
      loc+"front.jpg", loc+"back.jpg"
    };
    this->textureID = texture.loadSkybox(skyboxFaces);

    shader.use();
    shader.setInt("skybox", 0);
  };
};

Mesh::~Mesh() {
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
  glDeleteBuffers(1, &UVBO);

  glDeleteVertexArrays(1, &VAO);
};


void Mesh::draw(Camera* camera, ivec2 screenSize) {
  if(isSkybox) glDepthFunc(GL_LEQUAL);
  // if(!isSkybox) glDepthFunc(GL_DEPTH_BUFFER_BIT);

  shader.use();

  sP.view = camera->GetViewMatrix();
  if(!isSkybox) {
    sP.model = mat4(1.0f);
    sP.transform = mat4(1.0f);
    sP.transform = translate(sP.transform, this->pos);

    sP.projection = perspective(radians(camera->getZoom()), (float)screenSize.x / (float)screenSize.y, 0.1f, 300.f); /* @NOTE was 100 -> is view distance, essentially */
    sP.view = camera->GetViewMatrix();
  } else {
    sP.projection = perspective(radians(camera->getZoom()), (float)screenSize.x / (float)screenSize.y, 0.1f, 300.f); /* @NOTE was 100 -> is view distance, essentially */
    sP.view = mat4(mat3(camera->GetViewMatrix()));
  };

  shader.setMat4("view", sP.view);
  shader.setMat4("projection", sP.projection);

  if(!isSkybox) {
    shader.setMat4("model", sP.model);
    shader.setMat4("transform", sP.transform);
  };

  glBindVertexArray(VAO);
  glActiveTexture(GL_TEXTURE0);

  if(!isSkybox) {
    glBindTexture(GL_TEXTURE_2D, textureID);
    glDrawElements(GL_TRIANGLES, sizeof(objLoader.vertIndices) * sizeof(vec3), GL_UNSIGNED_INT, 0);
  } else {
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glDepthFunc(GL_LESS);
  };
  glBindVertexArray(0);
};
