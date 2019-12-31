#include "../headers/node.h"

void Node::init() {
  
}

void Node::spawn() {
  this->_node.setRadius(rand() % 33);
  this->_node.setFillColor(sf::Color(rand() % 144, rand() % 144, rand() % 255, rand() % 255));
  this->_node.setOutlineColor(sf::Color::White);
  this->_node.setOutlineThickness(1.8f);

  this->_node.setPosition(
    /* @REFACTOR grab screen size instead once the dynamic screen size is setup */
    static_cast<float>(rand() % static_cast<int>(1280, 1280)),
    static_cast<float>(rand() % static_cast<int>(900/2, 900/2))
  );
  this->_nodes.push_back(this->_node);
}

Node::Node() {
  this->init();
  this->spawn();
}

Node::~Node() {

}

void Node::update() {

}

void Node::render(sf::RenderTarget& target) {
  target.draw(this->_nodes[0]);
}