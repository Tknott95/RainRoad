#include "../headers/game.h"
#include "./draw.cpp"

void Game::init() {
  this->_gameMode = running;

  this->_contextSettings.depthBits = 24;
  this->_contextSettings.stencilBits = 8;
  this->_contextSettings.antialiasingLevel = 4;
  this->_contextSettings.majorVersion = 3;
  this->_contextSettings.minorVersion = 0;
  
  this->_window = new sf::RenderWindow(sf::VideoMode(this->screenWidth, this->screenHeight), "Cub3Z",  sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize, this->_contextSettings);
  this->_window->setVerticalSyncEnabled(true);

  this->_overlay = new Overlay();
}

Game::Game() {
  this->init();
}

Game::~Game() {
  delete this->_window;
  delete this->_overlay;
}

const bool Game::IsOpen() const {
  return this->_window->isOpen();
}

void Game::EventPolling() {
  while(this->_window->pollEvent(this->_event)) {
    switch(this->_event.type) {
      case sf::Event::Closed:
        this->_window->close();
        break;
      case sf::Event::KeyPressed:
        if(this->_event.key.code == sf::Keyboard::Escape){
          cout << "\n CLOSING WINDOW \n" << endl;
          this->_window->close();
          break;
        }
      break;
    }
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    cout << "movingLeft, bitch" << endl;
  } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    cout << "movingRight, bitch" << endl;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    cout << "movingUp, bitch" << endl;
  } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    cout << "movingDown, bitch" << endl;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    cout << "movingW, bitch" << endl;
  } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    cout << "movingS, bitch" << endl;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    cout << "movingA, bitch" << endl;
  } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    cout << "movingD, bitch" << endl;
  }
}

void Game::Update() {
  this->EventPolling();
  this->_overlay->Update();
}

void Game::Render() {
  this->_window->clear(sf::Color::Black);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0, 0, this->_window->getSize().x, this->_window->getSize().y);
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity();
  glRotatef(45, 0, 0, 0);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
  glEnable(GL_DEPTH_TEST);

  static float ang=0.0;
	ang+=0.0314f;

  // Draw_Cuboid(0.10,0,0);
	for (int i=0; i < 1444; i++) {
    glRotatef(ang*20.5,-7.3*ang,-7*i,7.3*i);
    glTranslatef(.10, 0.14, -0.10);
    glScalef(0.8314, 0.8314, 1.0014);
		Draw_Cuboid(0.44,0.44,0.44);
	} 
  this->_window->pushGLStates();
  glEnd();

  this->_overlay->Init(this->screenWidth, this->screenHeight);
  this->_overlay->Render(*this->_window);
  this->_window->popGLStates();  

  this->_window->setActive(true);
  this->_window->display();
}
