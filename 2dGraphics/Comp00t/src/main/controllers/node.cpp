#include "../headers/node.h"

void Node::init() {
  
}

void Node::spawn(float posx, float posy) {
  this->_node.setRadius(10);
  this->_node.setFillColor(sf::Color(180, 180, 255, 205));
  this->_node.setOutlineColor(sf::Color(144, 0, 0, 180));
  this->_node.setOutlineThickness(2.8f);

  if(posx != NULL || posy != NULL) {
    this->_node.setPosition(posx, posy);
  } else { 
    this->_node.setPosition(
      /* @REFACTOR grab screen size instead once the dynamic screen size is setup */
      static_cast<float>(rand() % static_cast<int>(1280, 1280)),
      static_cast<float>(rand() % static_cast<int>(900/2, 900/2))
    );
  }

  this->_nodes.push_back(this->_node);
}

Node::Node() {
  this->init();
  this->spawn(0.5, 0.5);
  this->spawn(50.5, 50.5);
  this->spawn(100.5, 100.5);
  this->spawn(150.5, 150.5);
  this->spawn(200.5, 200.5);
  this->spawn(250.5, 250.5);
}

Node::~Node() {

}

void Node::update() {

}

void Node::render(sf::RenderTarget& target) {
  for(auto &e : this->_nodes) {
    target.draw(e);
    cout << e.getPosition().x << endl;
  };
  // target.draw(this->_nodes[0]);
  // target.draw(this->_nodes[1]);
  // target.draw(this->_nodes[2]);
}