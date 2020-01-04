#include "../headers/game.h"

void Game::init() {
  this->_videoMode.width = screenWidth;
  this->_videoMode.height = screenHeight;

  while(this->_isFirstRun) {
    this->_isFirstRun = false;
    this->_window = new sf::RenderWindow(this->_videoMode, "Tks Flatland", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
  }
  this->_window->setFramerateLimit(55);

  this->_clock.restart();
  this->_timeElapsed = this->_clock.getElapsedTime();

  if (!this->_bgMusic.openFromFile("utils/audio/space_music.wav")) {
    std::cout << "ERROR: Could not load game - space_music.wav music file." << "\n";
  }
  if (!this->_audio00.openFromFile("utils/audio/laser03.ogg")) {
    std::cout << "ERROR: Could not load game - laser03.ogg audio file." << "\n";
  }

  if(!this->_audio01.openFromFile("utils/audio/doomed_music.wav")) {
    std::cout << "ERROR: Could not load game - doomed_music.wav audio file." << "\n";
  }

  if (!this->_font00.loadFromFile("utils/fonts/font00.ttf")) {
    std::cout << "ERROR: Could not load game - font00.ttf file." << "\n";
  }

  this->_bgMusic.setPosition(0, 1, 10); // change its 3D position
  //this->_bgMusic.setPitch(2);
  this->_bgMusic.setVolume(12);
  this->_bgMusic.setLoop(true);
  this->_audio00.setPosition(0, 1, 4);
  this->_audio00.setVolume(15);
  this->_audio01.setPosition(0, 1, 2);
  this->_audio01.setVolume(20);
 
  this->_bgMusic.play();

  this->_text02.setFont(this->_font00);
  this->_text02.setString("LEVEL 1"); /* @TODO make this dynamic w/ beginning timer from 3 -> 0 */
  this->_text02.setCharacterSize(180);
  this->_text02.setPosition((screenWidth/2)*0.40, screenHeight/2 - 200);
  this->_text02.setFillColor(sf::Color(178,250,245,100));
  this->_text02.setOutlineColor(sf::Color::Black);
  this->_text02.setOutlineThickness(2.f);

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
  sf::Texture cloudTexture;
  bgTexture.loadFromFile("./utils/img/bg/bg00_bluemap.png");
  cloudTexture.loadFromFile("./utils/img/bg/bg01_clouds.png");
  sf::Vector2u size = bgTexture.getSize();
  this->_bgSprite.setTexture(bgTexture);
  this->_bgCloudsSprite.setTexture(cloudTexture);
  this->_window->draw(this->_bgSprite);
  this->_window->draw(this->_bgCloudsSprite);
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
          this->_audio00.play();
          break;
        }
        break;
      case sf::Event::MouseButtonPressed: /* @TODO refactor this as it is sloppy, maybe remove this case for one similar to while() statement */
        /* @TODO checkCollision with text01 for playAgain. Maybe inside external class for modularity to pull in. */
        if(this->_event.MouseLeft) {
          if(this->DEBUG) { cout << "\n MouseButton PRESSED (" << this->_mousePos.x << ", " << this->_mousePos.y << ") \n" << endl; };
          if(this->isGameOver() && this->_text01.getGlobalBounds().contains(this->_mousePos.x, this->_mousePos.y)) {
            this->_text01.setFillColor(sf::Color(40, 40, 140, 230));
            this->restartGame = true;
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
    this->_enemy->moveToPlayer(k, this->_player->getPos(), 1.44f);

    if(collision.checkCollision(this->_player->_sprite.getGlobalBounds(), this->_enemy->_enemies[k].enemy.getGlobalBounds())){
      cout << "COLLIDED" << endl;
      this->_player->takeDmg(0.93);
    }
  }


  /* AFTER GAME TEXT onHOVER() */
  /* @TODO refactor this hack of onHOVER() */
  if(this->isGameOver() && this->_text01.getGlobalBounds().contains(this->_mousePos.x, this->_mousePos.y)) {
    this->_text01.setFillColor(sf::Color(40, 40, 140, 180));
    this->_audio01.play();
  } else {
    this->_text01.setFillColor(sf::Color(100, 40, 40, 210));
  }
  /* END AFTER GAME TEXT onHOVER() END */

  for(int _i=0; _i < this->_enemy->_enemies.size(); _i++) {
    if(this->_enemy->_enemies[_i].health <= 0.f) {
      this->_enemy->delEnemy(_i);
      this->_player->score += 33.3f;

    }
  }

  for(int k=0;k < this->_bullet->_bullets.size(); k++) {
    if(DEBUG == true) {
      cout << "\n  bullPosY(" << this->_bullet->_bullets[k].getPosition().y << ")  \n" << endl;
      cout << "\n  bulletsVecSize(" << this->_bullet->_bullets.size() << ") \n" << endl;
    }

    for(int j=0; j < this->_enemy->_enemies.size(); j++) {
      if(collision.checkCollision(this->_enemy->_enemies[j].enemy.getGlobalBounds(), this->_bullet->_bullets[k].getGlobalBounds())) {
       cout << "\n ENEMY HIT BY BULLET \n" << endl;
       this->_enemy->takeDmg(j, 33.3);
       this->_bullet->erase(k);
       this->_player->score += 5.5f;
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
  this->_enemy->update();
  if(!this->DEBUG == true) {
    cout << "\n   _timeElapsed: | " << this->_timeElapsed.asSeconds() << " |" << endl;
  }

  int _counter = 0;
  _counter++; 
  if(this->_timeElapsed.asSeconds() > this->firingDelay) {
    this->_bgCloudsSprite.move(.001f, -0.0000001f);
  } else if (_counter % 3 == 0) {
    this->_bgCloudsSprite.move(-.001f, 0.0000001f);
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

  if(introFinished) {
    /* DRAW HERE */
    this->_player->render(*this->_window);
    this->_enemy->render(*this->_window);
    this->_bullet->render(*this->_window);
  } else {
    /* for 3 secs */
    this->_window->draw(this->_text02);
  }
  

  if(this->isGameOver()) {
    this->_clock.restart();
    this->_bgMusic.stop();

    this->_window->clear(sf::Color::White);
    this->_window->draw(this->_text00);
    this->_window->draw(this->_text01);

    if(restartGame) {
      delete this->_player;
      delete this->_enemy;
      delete this->_bullet;
      this->init();
       // @TODO REFACTOR
      this->_window->clear(sf::Color::Black);
      this->setBackground();
      this->_player->render(*this->_window);
      this->_enemy->render(*this->_window);
      this->_bullet->render(*this->_window);
      restartGame = false;
      // @TODO REFACTOR
    }
  }
  /* DRAW HERE */

  this->_window->display();
}
