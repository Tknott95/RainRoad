#include "../headers/node.h"

void Node::init() {
  this->spawnDelay = 0.0001f;
  this->maxNodes = 3333;

  if (!_texture.loadFromFile("./utils/sprite.png")) {
    cout << "\n ERROR LOADING ENEMY TEXTURE \n" << endl;
  }
}

void Node::spawn() {
  // printf("\n SPAWNING ENEMY \n");
  // this->_node.setPosition(50.f, 50.f);
  this->_node.setRotation(rand() % 3);
  this->_node.setSize(sf::Vector2f(rand() % 33, rand() % 133));
  this->_node.setFillColor(sf::Color(rand() % 144, rand() % 144, rand() % 255, rand() % 255));
  this->_node.setOutlineColor(sf::Color::White);
  this->_node.setOutlineThickness(1.8f);

  this->_node.setPosition(
    /* @REFACTOR grab screen size instead once the dynamic screen size is setup */
    static_cast<float>(rand() % static_cast<int>(1280, 1280)),
    static_cast<float>(rand() % static_cast<int>(900/2, 900/2))
  );
  this->nodes.push_back(this->_node);
  this->clock.restart();
}

void Node::update() {
  this->elapsedTime = clock.getElapsedTime();
  
  // int cur = 0;
  // for(auto &e : this->nodes) { /* change to old school loop */
  //   cur++;
  //   e.move(0.14f, .48f + rand() % 3);
  //   //sf::Vector2f pos = e.getPosition();
  //   cout << "x pos:" << e.getPosition().x << "  y pos:" << e.getPosition().y << endl;
  //   e.setRotation(e.getRotation() + 0.1);

  //   if(e.getPosition().y > 333) {
  //     printf("\n  DELETE OBJ \n");
  //     // this->nodes.erase(e); /* best way I know with vector looping via. auto to grab index as of meow */    
  //   }
  //  // cout << e.getGlobalBounds() << endl;
  //   // e.setSize(sf::Vector2f(13, rand() % 33));
  //   /* if enemy leaves screen area DEL IT */
  // }


  if(this->nodes.size() < this->maxNodes && this->elapsedTime.asSeconds() > this->spawnDelay) {
    this->spawn();   
  }

  for (size_t i = 0; i < this->nodes.size(); i++) {
     this->nodes[i].move(0-.14f, .08f + rand() % 4);
     this->nodes[i].setRotation(this->nodes[i].getRotation() + 0.001f);

     if(this->nodes[i].getPosition().y >= 720 |this->nodes[i].getPosition().x >= 1280 ) {
       this->nodes.erase(this->nodes.begin() + i);
       cout << "x pos:" << this->nodes[i].getPosition().x << "  y pos:" << this->nodes[i].getPosition().y << endl;
       /* if debugging     cout << this->nodes.size() << endl; */
     }
  }




}

void Node::run() {
  this->update();
}
