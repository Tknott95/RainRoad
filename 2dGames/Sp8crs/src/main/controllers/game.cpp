#include "../headers/game.h"

void Game::init() {
  this->_videoMode.width = screenWidth;
  this->_videoMode.height = screenHeight;

  this->_window = new sf::RenderWindow(this->_videoMode, "Tks Flatland", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
  this->_window->setFramerateLimit(88);
  this->_clock.restart();

  if (!this->_font00.loadFromFile("utils/fonts/font00.ttf")) {
    std::cout << "ERROR: Could not load player font file." << "\n";
  }

  this->_text00.setFont(this->_font00);
  this->_text00.setString("GAME OVER");
  this->_text00.setCharacterSize(130);
  this->_text00.setPosition((screenWidth/2)*0.25, screenHeight/2 - 200);
  this->_text00.setFillColor(sf::Color(140, 40, 40, 210));

  this->_text01.setFont(this->_font00);
  this->_text01.setString("PLAY AGAIN?");
  this->_text01.setCharacterSize(100);
  this->_text01.setPosition((screenWidth/2)*0.40, screenHeight/2);
  this->_text01.setFillColor(sf::Color(100, 40, 40, 210));


  this->_player = new Player();
  this->_enemy = new Enemy();
  this->_bullet = new Bullet();
  this->_bullet->init(this->_player->getPos(), this->_player->_sprite.getGlobalBounds().width/2);
}

const bool Game::isGameOver() { /* @TODO render text and black overlay opacity .5 after "dead" */
  if(this->_player->curHealth <= 0.f) {
    return true;
  }
  return false;
}

Game::Game() {
  this->init();
}

Game::~Game() {
  delete this->_window;
  delete this->_player;
  delete this->_enemy;
  delete this->_bullet;
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
  if(this->DEBUG) {
    cout << "COORDS MOUSE POS: " << this->_mouseCoords.x << " " << this->_mouseCoords.y << "\n";
    cout << "MOUSE POS: " << this->_mousePos.x << " " << this->_mousePos.y << "\n";
  }
}

void Game::eventPolling() {
  while(this->_window->pollEvent(this->_event)) {
    switch(this->_event.type) {
      case sf::Event::Closed:
        this->_window->close();
        break;
      case sf::Event::KeyPressed:
        if(this->_event.key.code == sf::Keyboard::Escape){
          if(this->DEBUG) { cout << "\n CLOSING WINDOW \n" << endl; };
          this->_window->close();
          break;
        }
        if (this->_event.key.code == sf::Keyboard::Space){
          if(this->DEBUG) { cout << "\n Space PRESSED \n" << endl; };
          // this->_bullet->fire(this->_player->_sprite.getPosition());
          this->firing = true;
          break;
        }
        break;
      case sf::Event::MouseButtonPressed: /* @TODO refactor this as it is sloppy, maybe remove this case for one similar to while() statement */
        /* @TODO checkCollision with text01 for playAgain. Maybe inside external class for modularity to pull in. */
        if(this->_event.MouseLeft) {
          if(this->DEBUG) { cout << "\n MouseButton PRESSED (" << this->_mousePos.x << ", " << this->_mousePos.y << ") \n" << endl; };
          if(this->isGameOver() && this->_text01.getGlobalBounds().contains(this->_mousePos.x, this->_mousePos.y)) {
            this->_text01.setFillColor(sf::Color(40, 40, 140, 230));
          }
        }
        break;
    }
  }
  
  float playerRotation = this->_player->_sprite.getRotation();
  int rightClamp = 2; /* 0->1 */
  int leftClamp = 357; /* 358<-360 */
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    if(this->_player->getPos().x < this->screenWidth - 110) {
      this->_player->move(this->playerSpeed, 0.0);
    }
    
    // cout << "\n   ROTATION(" << this->_player->_sprite.getRotation() << ") \n" << endl;
    if(playerRotation > leftClamp - 1 || playerRotation < rightClamp) {
      if(this->DEBUG) { cout << "\n   ROTATION(" << this->_player->_sprite.getRotation() << ") \n" << endl; };
      this->_player->_sprite.setRotation(this->_player->_sprite.getRotation() + 0.1f); /* needs clamp and lerp to orig on keyUP @TODO */
    }
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    if(this->_player->getPos().x > 0) {
      this->_player->move(-this->playerSpeed, 0.0);
    }
    if(playerRotation < rightClamp + 1 || playerRotation > leftClamp) {
      if(this->DEBUG) { cout << "\n   ROTATION(" << this->_player->_sprite.getRotation() << ") \n" << endl; };
      this->_player->_sprite.setRotation(this->_player->_sprite.getRotation() - 0.1f); /* needs clamp and lerp to orig on keyUP @TODO */
    }
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
    if(this->_player->getPos().y < this->screenHeight - 100) {
      this->_player->move(0.0, this->playerSpeed);
    }
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    if(this->_player->getPos().y > 100) {
      this->_player->move(0.0, -this->playerSpeed);
        this->_bullet->move(.3f);
    }
  }
}

void Game::fixedUpdate() {
  this->eventPolling();
  this->setMousePos();

  for(int k=0; k < this->_enemy->_enemies.size(); k++) {
    this->_enemy->moveToPlayer(k, this->_player->getPos(), 0.64f);

    if(collision.checkCollision(this->_player->_sprite.getGlobalBounds(), this->_enemy->_enemies[k].second.getGlobalBounds())){
      cout << "COLLIDED" << endl;
      this->_player->takeDmg(0.93);
      if(this->_player->curHealth <= 0) {
        cout << "\n  PLAYER DEAD \n" << endl;
      }
    }
  }


  /* AFTER GAME TEXT onHOVER() */
  /* @TODO refactor this hack of onHOVER() */
  if(this->isGameOver() && this->_text01.getGlobalBounds().contains(this->_mousePos.x, this->_mousePos.y)) {
    //while(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
    this->_text01.setFillColor(sf::Color(40, 40, 140, 180));
    //}
  } else {
    this->_text01.setFillColor(sf::Color(100, 40, 40, 210));
  }
  /* END AFTER GAME TEXT onHOVER() END */

  for(int k=0;k < this->_bullet->_bullets.size(); k++) {
    if(DEBUG == true) {
      cout << "\n  bullPosY(" << this->_bullet->_bullets[k].getPosition().y << ")  \n" << endl;
      cout << "\n  bulletsVecSize(" << this->_bullet->_bullets.size() << ") \n" << endl;
    }

    for(int j=0; j < this->_enemy->_enemies.size(); j++) {
      if(collision.checkCollision(this->_enemy->_enemies[j].second.getGlobalBounds(), this->_bullet->_bullets[k].getGlobalBounds())) {
       cout << "\n ENEMY HIT BY BULLET \n" << endl;
       this->_bullet->erase(k);
      }
    }

    if(this->_bullet->_bullets[k].getPosition().y <= 100) {
      this->_bullet->erase(k);
    }
  }
}

void Game::update() {
  this->_timeElapsed = this->_clock.getElapsedTime();
  this->_player->update();
  if(!this->DEBUG == true) {
    cout << "\n   _timeElapsed: | " << this->_timeElapsed.asSeconds() << " |" << endl;
  }

  if(!this->DEBUG) { cout << " \n   playerPos(" << this->_player->getPos().x << ", " << this->_player->_sprite.getPosition().y << ") \n" << endl; };
  if(firing  && this->_timeElapsed.asSeconds() > this->firingDelay) {
    this->_bullet->fire(this->_player->getPos(), this->_player->_sprite.getGlobalBounds().width/2);
    firing = false;
    this->_clock.restart();
  }

  this->_bullet->move(3.3f);

  float boundsWidth = this->_player->_sprite.getGlobalBounds().width;
  float boundsHeight = this->_player->_sprite.getGlobalBounds().height;
  if(this->DEBUG) { cout << boundsWidth << " - boundsWidth \n" << boundsHeight << " - boundsHeight \n" << endl; };
}

void Game::render() {
  this->_window->clear(sf::Color::Black);
  this->setBackground();
  
  /* DRAW HERE */
  this->_player->render(*this->_window);
  this->_enemy->render(*this->_window);
  this->_bullet->render(*this->_window);

  if(this->isGameOver()) {
    this->_window->clear(sf::Color::White);
    this->_window->draw(this->_text00);
    this->_window->draw(this->_text01);
  }
  /* DRAW HERE */

  this->_window->display();
}
