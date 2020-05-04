#include "../headers/draw.h"
#include "../headers/utils/skybox_data.h"

/*************************************************
 * 
 * @HOTBOX
 * @TODO bring in normal coords
 * @TODO bring in texture coords
 * @TODO bring in uv coords
 * @TODO bind texture coords & use them
 * 
 * @ICEBOX
 * @TODO add cullface after normals in
 * @TODO get adv objects working
 * @TODO do adv changes after gLit_Mesh proj is finished
 * 
 *************************************************/

void Draw::init() {
  std::vector<std::string> sbFaces = {
    "assets/skybox/right.jpg",
    "assets/skybox/left.jpg",
    "assets/skybox/top.jpg",
    "assets/skybox/bottom.jpg",
    "assets/skybox/front.jpg",
    "assets/skybox/back.jpg"
  };

  glEnable(GL_DEPTH_TEST);
  /***********
  * star.obj
  * oddShape.obj
  * col.obj
  * col_lg.obj
  *************/
  objData = objLoader.load("assets/objects/col_lg.obj"); 

  skyboxShader.compile("assets/shaders/skybox.vs", "assets/shaders/skybox.fs");
  objShader.compile("assets/shaders/obj.vs", "assets/shaders/obj.fs");

  /******** binding obj attribs ********/
  glGenVertexArrays(1, &objVAO);
  glGenBuffers(1, &objVBO);
  glGenBuffers(1, &objEBO);
  glBindVertexArray(objVAO);
  glBindBuffer(GL_ARRAY_BUFFER, objVBO); //  * sizeof(glm::vec3)
  glBufferData(GL_ARRAY_BUFFER, objData.vertices.size() * sizeof(vec3), &objData.vertices[0], GL_STATIC_DRAW);
  /*
    Naturally the sizeof operator can also be used on the struct for the appropriate size in bytes. This should be 32 bytes (8 floats * 4 bytes each).
  */
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(
    0, /* matches layout in hader */
    3, /* size */
    GL_FLOAT, /* type */
    GL_FALSE, /* isNormalized? */
    sizeof(vec3), /* stride, matches my data xyz|vec3*/
    (void*)0 /* array buffer offset */
  );
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, objEBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, objData.vertIndices.size() * sizeof(uint), &objData.vertIndices[0], GL_STATIC_DRAW);

  /******** binding skybox attribs *******/
  glGenVertexArrays(1, &skyboxVAO);
  glGenBuffers(1, &skyboxVBO);
  glBindVertexArray(skyboxVAO);
  /* @TODO need texture coordinates imported in */
  glActiveTexture(GL_TEXTURE1);
  glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); /* 5 */

  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0); /* 5 */

  sbTexID = texture.loadSkybox(sbFaces);
  objTexID = texture.load("assets/textures/box_weave.png");

  skyboxShader.use();
  skyboxShader.setInt("skybox", 0);
}

void Draw::update(Camera* camera, ivec2 screenSize) {
  /************* OBJ DRAWING START **********************/
  objShader.use();
  mat4 model = mat4(1.0f);
  mat4 transform = mat4(1.0f);
  mat4 projection = perspective(radians(camera->Zoom), (float)screenSize.x / (float)screenSize.y, 0.1f, 100.f);
  mat4 view = camera->GetViewMatrix();
  transform = translate(transform, glm::vec3(1.0f, 1.8f, -1.0f));

  objShader.setMat4("model", model);
  objShader.setMat4("view", view);
  objShader.setMat4("projection", projection);
  objShader.setMat4("transform", transform);

  glBindVertexArray(objVAO);
  /* @TODO need texture coordinates imported in */
  glActiveTexture(GL_TEXTURE1);
  glBindTexture(GL_TEXTURE1, objTexID);
  glDrawElements(GL_TRIANGLES, objData.vertIndices.size(), GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
  /************* OBJ DRAWING FINISHED **********************/

  /************* SKYBOX DRAWING START **********************/
  glDepthFunc(GL_LEQUAL);
  skyboxShader.use();
 
  view = mat4(mat3(camera->GetViewMatrix()));
  skyboxShader.setMat4("view", view);
  skyboxShader.setMat4("projection", projection);

  glBindVertexArray(skyboxVAO);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_CUBE_MAP, sbTexID);
  glDrawArrays(GL_TRIANGLES, 0, 36);
  glBindVertexArray(0);
  glDepthFunc(GL_LESS);
  /************* SKYBOX DRAWING FINISHED **********************/
}

void Draw::deallocate() {
  glDeleteVertexArrays(1, &skyboxVAO);
  glDeleteBuffers(1, &skyboxVBO);
}
