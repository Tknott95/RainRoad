#include "../headers/game.h"

void Game::init() {
  this->_videoMode.width = screenWidth;
  this->_videoMode.height = screenHeight;

  this->_window = new sf::RenderWindow(this->_videoMode, "Tks Flatland", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
  this->_window->setFramerateLimit(88);
  this->_clock.restart();

  this->_player = new Player();
  this->_enemy = new Enemy();
}

Game::Game() {
  this->init();
}

Game::~Game() {
  delete this->_window;
  delete this->_player;
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
          this->firing = true;
          break;
        }
        break;
    }
  }
  
  float playerRotation = this->_player->_sprite.getRotation();
  int rightClamp = 2; /* 0->1 */
  int leftClamp = 357; /* 358<-360 */
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    if(this->_player->_sprite.getPosition().x < this->screenWidth - 110) {
      this->_player->move(this->playerSpeed, 0.0);
    }
    
    // cout << "\n   ROTATION(" << this->_player->_sprite.getRotation() << ") \n" << endl;
    if(playerRotation > leftClamp - 1 || playerRotation < rightClamp) {
      // cout << "\n   ROTATION(" << this->_player->_sprite.getRotation() << ") \n" << endl;
      this->_player->_sprite.setRotation(this->_player->_sprite.getRotation() + 0.1f); /* needs clamp and lerp to orig on keyUP @TODO */
    }
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    if(this->_player->_sprite.getPosition().x > 0) {
      this->_player->move(-this->playerSpeed, 0.0);
    }
    if(playerRotation < rightClamp + 1 || playerRotation > leftClamp) {
      // cout << "\n   ROTATION(" << this->_player->_sprite.getRotation() << ") \n" << endl;
      this->_player->_sprite.setRotation(this->_player->_sprite.getRotation() - 0.1f); /* needs clamp and lerp to orig on keyUP @TODO */
    }
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
    if(this->_player->_sprite.getPosition().y < this->screenHeight - 100) {
      this->_player->move(0.0, this->playerSpeed);
    }
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    if(this->_player->_sprite.getPosition().y > 100) {
      this->_player->move(0.0, -this->playerSpeed);
    }
  }
}

void Game::fixedUpdate() {
  this->eventPolling();
  this->setMousePos();

  if(collision.checkCollision(this->_player->_sprite.getGlobalBounds(), this->_enemy->_sprite.getGlobalBounds())){
    cout << "COLLIDED" << endl;
    this->_player->takeDmg(0.93);
    if(this->_player->curHealth <= 0) {
      cout << "\n  PLAYER DEAD \n" << endl;
    }
  }
}

void Game::update() {
  this->_timeElapsed = this->_clock.getElapsedTime();
  this->_player->update();
  cout << "\n    _timeElapsed: | " << this->_timeElapsed.asSeconds() << " |" << endl;
  this->_player->shoot();
  if(firing) {
    this->_player->shoot();
  }

  this->_enemy->moveToPlayer(this->_player->getPos(), 0.7f);

  float boundsWidth = this->_player->_sprite.getGlobalBounds().width;
  float boundsHeight = this->_player->_sprite.getGlobalBounds().height;
  cout << boundsWidth << " - boundsWidth \n" << boundsHeight << " - boundsHeight \n" << endl;
}

void Game::render() {
  this->_window->clear(sf::Color::Black);
  this->setBackground();
  
  /* DRAW HERE */
  this->_player->render(*this->_window);
  this->_enemy->render(*this->_window);
  /* DRAW HERE */

  this->_window->display();
}
