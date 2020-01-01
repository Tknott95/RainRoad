#include "../headers/node.h"

void Node::init() {
  
}

void Node::spawn(float posx, float posy) {
  this->_node.setRadius(5);
  this->_node.setFillColor(sf::Color(180, 180, 255, 205));
  this->_node.setOutlineColor(sf::Color(144, 0, 0, 180));
  this->_node.setOutlineThickness(2.8f);

  if(posx != NULL || posy != NULL) {
    this->_node.setPosition(posx, posy);
  } else { 
    this->_node.setPosition(
      /* @REFACTOR grab screen size instead once the dynamic screen size is setup */
      static_cast<float>(rand() % static_cast<int>(1280, 1280)),
      static_cast<float>(rand() % static_cast<int>(900, 900))
    );
  }

  this->_nodes.push_back(this->_node);
}

Node::Node() {
  this->init();

  float vCount = 0.f;
  //this->lines(sf::LineStrip, this->totalNodes);
  for(int _v=0; _v < this->totalNodes; _v++) {
    cout << '\n _v(' << _v << ') \n' << endl;
    // this->lines[_v].color = sf::Color::Red;
    // this->lines[_v].position = this->_nodes[_v].getPosition();

    if(_v > 10) {
      vCount = 0;
      vCount += vCount;
    } else if(_v > 14) {
      vCount = 13;
      vCount += vCount/2;
    } else if(_v > 20) {
      vCount = 13;
      vCount += vCount/3;
    } else {
      vCount += 50.f;
    }
    this->spawn(vCount, vCount);

    this->vertices[_v] = sf::Vertex(sf::Vector2f(this->_nodes[_v].getPosition().x, this->_nodes[_v].getPosition().y), sf::Color::Red, sf::Vector2f(this->_nodes[_v].getPosition().x, this->_nodes[_v].getPosition().y));
  }
  // this->spawn(0.5, 0.5);
  // this->spawn(50.5, 50.5);
  // this->spawn(100.5, 100.5);
  // this->spawn(150.5, 150.5);
  // this->spawn(200.5, 200.5);
  // this->spawn(250.5, 250.5);
}

Node::~Node() {

}

void Node::update() {
  for(int _v=0; _v < this->totalNodes; _v++) {
    this->_nodes[_v].setPosition(this->_nodes[_v].getPosition().x + .001f, this->_nodes[_v].getPosition().y + .0001f);
    this->vertices[_v] = sf::Vertex(sf::Vector2f(this->_nodes[_v].getPosition().x, this->_nodes[_v].getPosition().y), sf::Color::Red, sf::Vector2f(this->_nodes[_v].getPosition().x, this->_nodes[_v].getPosition().y));
  }

  // for(int _v=0; _v < this->totalNodes; _v++) {
  //   this->vertices[_v] = sf::Vertex(sf::Vector2f(this->_nodes[_v].getPosition().x, this->_nodes[_v].getPosition().y), sf::Color::Red, sf::Vector2f(this->_nodes[_v].getPosition().x, this->_nodes[_v].getPosition().y));
  // } 
  
}

void Node::render(sf::RenderTarget& target) {
  for(auto &e : this->_nodes) {
    target.draw(e);
    cout << e.getPosition().x << endl;
  };
 
  // this->vertices[0] = sf::Vertex(sf::Vector2f(  0,   0), sf::Color::Red, sf::Vector2f( 0,  0));
  // this->vertices[1] = sf::Vertex(sf::Vector2f(  0, 100), sf::Color::Red, sf::Vector2f( 0, 10));
  // this->vertices[2] = sf::Vertex(sf::Vector2f(100, 100), sf::Color::Red, sf::Vector2f(10, 10));
  // this->vertices[3] = sf::Vertex(sf::Vector2f(100,   0), sf::Color::Red, sf::Vector2f(10,  0));

  target.draw(vertices, this->totalNodes, sf::LinesStrip); // sf::LineStrip
  // target.draw(this->lines);
  // target.draw(this->_nodes[0]);
  // target.draw(this->_nodes[1]);
  // target.draw(this->_nodes[2]);
}