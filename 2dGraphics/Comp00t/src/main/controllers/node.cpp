#include "../headers/node.h"

void Node::init() {
  
}

void Node::spawn(float posx, float posy) {
  this->_node.setRadius(4);
  this->_node.setFillColor(sf::Color(100, 100, 100, 205));
  this->_node.setOutlineColor(sf::Color(0, 0, 255, 80));
  this->_node.setOutlineThickness(0.8f);

  if(&posx == NULL || &posy == NULL) {
    this->_node.setPosition(posx, posy);
  } else { 
    this->_node.setPosition(
      /* @REFACTOR grab screen size instead once the dynamic screen size is setup */
      static_cast<float>(rand() % static_cast<int>(1920, 1280)),
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
    cout << "\n _v(" << _v << ") \n" << endl;
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

    //this->vertices[_v] = sf::Vertex(sf::Vector2f(this->_nodes[_v].getPosition().x, this->_nodes[_v].getPosition().y), sf::Color(rand() % 144, rand() % 144, 0, 180), sf::Vector2f(this->_nodes[_v].getPosition().x, this->_nodes[_v].getPosition().y));
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
    if(_v % 3 == 0 ) {
      this->_nodes[_v].setPosition(this->_nodes[_v].getPosition().x + (rand() % 2), this->_nodes[_v].getPosition().y + (rand() % 2));
    } else if(_v % 2 == 0 ) {
      this->_nodes[_v].setPosition(this->_nodes[_v].getPosition().x - (rand() % 1), this->_nodes[_v].getPosition().y  - (rand() % 1));
    } else if (_v % 2 == 0 && _v % 4 == 0 ) {
      this->_nodes[_v].setPosition(this->_nodes[_v].getPosition().x - (rand() % 4), this->_nodes[_v].getPosition().y  - (rand() % 3));
    } else if (_v % 3 == 0 && _v % 9 == 0 ) {
      this->_nodes[_v].setPosition(this->_nodes[_v].getPosition().x, this->_nodes[_v].getPosition().y  + (rand() % 7));
    } else {
      this->_nodes[_v].setPosition(this->_nodes[_v].getPosition().x - (rand() % -2), this->_nodes[_v].getPosition().y + (rand() % -2));
    }
    
    this->vertices[_v] = sf::Vertex(sf::Vector2f(this->_nodes[_v].getPosition().x, this->_nodes[_v].getPosition().y), sf::Color(rand() % 204, rand() % 224, rand() % 235, 230), sf::Vector2f(this->_nodes[_v].getPosition().x, this->_nodes[_v].getPosition().y));
  }
}

void Node::render(sf::RenderTarget& target) {
  for(auto &e : this->_nodes) {
    target.draw(e);
    cout << "  (" << e.getPosition().x << ", " << e.getPosition().y << ") " << endl;
  };
 
  target.draw(vertices, this->totalNodes, sf::LinesStrip); // sf::LineStrip or sf::Triangles, etc
}