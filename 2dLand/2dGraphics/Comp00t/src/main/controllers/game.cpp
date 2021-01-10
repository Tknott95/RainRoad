#include "../headers/game.h"

void Game::init() {
  this->_videoMode.width = screenWidth;
  this->_videoMode.height = screenHeight;

  this->_window = new sf::RenderWindow(this->_videoMode, "Tks Flatland", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
  this->_window->setFramerateLimit(88);

  this->_view.reset(sf::FloatRect(0, 0, screenWidth, screenHeight));
  this->_view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));  // last two 1/2 <-> or 1/2 ^
  this->_window->setView(this->_view);

  this->_clock.restart();

}

Game::Game() {
  this->init();
}

Game::~Game() {
  delete this->_window;

}

const bool Game::isOpen() const {
  return this->_window->isOpen();
}

void Game::setBackground() {
  sf::Texture bgTexture;
  bgTexture.loadFromFile("./utils/img/background.jpg");
  sf::Vector2u size = bgTexture.getSize();
  this->_bgSprite.setTexture(bgTexture);
  this->_window->draw(this->_bgSprite);
}

void Game::setMousePos() {
  this->_mousePos = sf::Mouse::getPosition(*this->_window);
  this->_mouseCoords = this->_window->mapPixelToCoords(this->_mousePos);
  /* call *this->_window inside getPosition() for relative pos to _window */
  cout << "COORDS MOUSE POS: " << this->_mouseCoords.x << " " << this->_mouseCoords.y << "\n";
  cout << "MOUSE POS: " << this->_mousePos.x << " " << this->_mousePos.y << "\n";
}

void Game::eventPolling() {
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
        if (this->_event.key.code == sf::Keyboard::Space){
          cout << "Space PRESSED" << endl;
          break;
        }
        break;
    }

     
  }
  

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    this->_view.move(5.f, 0.f);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    this->_view.move(-5.f, 0.f);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
    this->_view.move(0.f, 5.f);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    this->_view.move(0.f, -5.f);
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
    cout << "\n  zooming in \n" << endl;
    this->_view.zoom(0.75f);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
    cout << "\n  zooming out \n" << endl;
    this->_view.zoom(1.25f);
  }
  this->_window->setView(this->_view);
}

void Game::fixedUpdate() {
  this->eventPolling();
  this->setMousePos();
}

void Game::update() {
  this->_timeElapsed = this->_clock.getElapsedTime();
  cout << "\n    _timeElapsed: | " << this->_timeElapsed.asSeconds() << " |" << endl;
  this->_graphicNode.update();

}

void Game::render() {
  this->_window->clear(sf::Color::Black);
  this->setBackground();
  
  /* DRAW HERE */
  this->_graphicNode.render(*this->_window);
  /* DRAW HERE */

  this->_window->display();
}
