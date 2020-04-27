#version 440 core
out vec4 FragColor;

struct Material {
  sampler2D diffuse;
  sampler2D specular;
  sampler2D emission;
  float shininess;
}; 

struct Light {
  vec3 position;
  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
};

in vec3 FragPos;  
in vec3 Normal;  
in vec2 TexCoords;

uniform vec3 viewPos;
uniform float time;
uniform Material material;
uniform Light light;

void main() {
  vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));

  vec3 norm = normalize(Normal);
  vec3 lightDir = normalize(light.position - FragPos);
  float diff = max(dot(norm, lightDir), 0.0);
  vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));

  vec3 viewDir = normalize(viewPos - FragPos);
  vec3 reflectDir = reflect(-lightDir, norm);  
  float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
  vec3 specular = light.specular * spec * (vec3(texture(material.specular, TexCoords)));
  // vec3 emission = vec3(texture(material.emission, TexCoords)); /* for normal ommision overlay, yet we want this under the outside of cube */
  vec3 emission = vec3(0.0);

  /*rough check for blackbox inside spec texture */
  if (texture(material.specular, TexCoords).r == 0.0) {
    /*apply emission texture */
    emission = texture(material.emission, TexCoords).rgb;
    /*some extra fun stuff with "time uniform" */
    emission = texture(material.emission, TexCoords + vec2(0.0,time)).rgb;   /*moving */
    emission = emission * (sin(time) * 0.5 + 0.5) * 2.0;                     /*fading */
   }

  FragColor = vec4(ambient + diffuse + specular + emission, 1.0);
}