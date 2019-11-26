#include "headers/game.h"
#include <SFML/OpenGL.hpp>
#include "SFML/Graphics.hpp"
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <math.h> 
#include <iostream> 
#include "draw.cpp"
#include "headers/utils.h"

void test(float);

void Game::initWindow() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    
  sf::ContextSettings settings; // = this->window->getSettings();
  settings.depthBits = 128;
  settings.stencilBits = 8;
  settings.antialiasingLevel = 4;
  settings.majorVersion = 3;
  settings.minorVersion = 0;

  std::cout << "depth bits:" << settings.depthBits << std::endl;
  std::cout << "stencil bits:" << settings.stencilBits << std::endl;
  std::cout << "antialiasing level:" << settings.antialiasingLevel << std::endl;
  std::cout << "version:" << settings.majorVersion << "." << settings.minorVersion << std::endl;
   
  this->window = new sf::RenderWindow(sf::VideoMode(3000, 1920, 32), "TheZeonTex");
  this->window->setVerticalSyncEnabled(true);
  this->window->setKeyRepeatEnabled(false);
  this->window->requestFocus();

  // CAMERA INIT
  const sf::Glsl::Vec2 window_res((float)this->window->getSize().x, (float)this->window->getSize().y);

  sf::RectangleShape rect;
  rect.setSize(window_res);
  rect.setPosition(0, 0);

  // @TODO: RESOLUTION SELECTION SCREEN REFACTOR REFACTOR
  const sf::Vector2i screen_center(3000/2, 1920/ 2);
  sf::Clock clock;
}


Game::Game() {
  this->initWindow();
}

Game::~Game() {
  delete this->window;
}

void Game::updateSFML() {
  while (this->window->pollEvent(this->sfEvent)) {
    switch (this->sfEvent.type) {
      case sf::Event::Closed:
        this->window->close();
        break;

      case sf::Event::Resized:
        glViewport(0, 0, this->sfEvent.size.width, this->sfEvent.size.height);
        break;

      case sf::Event::KeyPressed:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
          this->window->close();
          break;
        }
        break;
        
      default:
        break;
    }
  }
}

void Game::update() {
  this->updateSFML();
}

void Game::render() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0, 0, this->window->getSize().x, this->window->getSize().y);
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity(); 
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
    
  static float ang=0.0;
	ang+=0.0314f;

  glEnd();
  sf::Font font1;
  if (!font1.loadFromFile(Orbitron_Bold_ttf)) {
    return;
  }
  
  sf::Font font2;
  if (!font2.loadFromFile(Inconsolata_Bold_ttf)) {
    return;
  }

  sf::Text text("TK's Lorem Ipsum", font2, 100);
  sf::CircleShape shape(100.f);  
  shape.setFillColor(sf::Color::Blue);
  text.setFillColor(sf::Color::Cyan);

  glRotatef(0,1,ang*100,ang*3);
  Draw_Cuboid(0.10,0,0);
	int i=0; 
	for (i = 1; i <= 1444; i++) {
      glRotatef(ang*10.5,-1.3*ang,3*i,1.3*i);
      glTranslatef(.10, 0.14, -0.10);

      glScalef(0.7314, 0.8314, 1.0014);
		  Draw_Cuboid(0.44,0.44,0.44);
	  } 
  this->window->pushGLStates();
  this->window->draw(text);  glViewport(0, 0, this->window->getSize().x, this->window->getSize().y);
  this->window->popGLStates();
  this->window->setActive(true);
}

void Game::run() {
  while (this->window->isOpen()) {    
    this->update();
    this->render();
    this->window->display();
  }
}


void test(float ang) {
  glTranslatef(ang*0.0314,0,-0.0);//move everyting after this line by 40 units along y-axis
  Draw_Cuboid(0.20,0.20,0.10);
}
