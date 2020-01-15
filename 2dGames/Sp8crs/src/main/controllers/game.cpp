#include "../headers/game.h"

void Game::init() {
  this->_videoMode.width = screenWidth;
  this->_videoMode.height = screenHeight;
  this->_gameMode = running;
  this->_gameStruct.currScore = 0.f;
  this->_gameStruct.currLvl = 1;

  while(this->_isFirstRun) {
    this->_isFirstRun = false;
    this->_window = new sf::RenderWindow(this->_videoMode, "Tks Flatland", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
  }
  this->_window->setFramerateLimit(88);

  this->_clock.restart();
  this->_enemyClock.restart();
  this->_trueClock.restart();
  this->_timeElapsed = this->_clock.getElapsedTime();
  this->_enemyTimeElapsed = this->_enemyClock.getElapsedTime();
  this->_trueElapsedTime = this->_trueClock.getElapsedTime();

  if (!this->_bgMusic.openFromFile("utils/audio/bg/DOS-88-Automatav2.ogg")) {
    std::cout << "ERROR: Could not load game - space_music.wav music file." << "\n";
  }
  if (!this->_audio00.openFromFile("utils/audio/laser03.ogg")) {
    std::cout << "ERROR: Could not load game - laser03.ogg audio file." << "\n";
  }

  if(!this->_audio01.openFromFile("utils/audio/doomed_music.wav")) {
    std::cout << "ERROR: Could not load game - doomed_music.wav audio file." << "\n";
  }

  this->_bgMusic.setPosition(0, 1, 8);
  this->_bgMusic.setVolume(22);
  this->_bgMusic.setLoop(true);
  this->_audio00.setPosition(0, 1, 4);
  this->_audio00.setVolume(25);
  this->_audio01.setPosition(0, 1, 2);
  this->_audio01.setVolume(15);
  this->_bgMusic.play();

  this->_overlay = new Overlay();
  this->_player = new Player();
  this->_enemy = new Enemy();
  this->_enemy->spawner(this->getCurrLvl());
  this->_bullet = new Bullet();
  this->_overlay->Init(this->screenWidth, this->screenHeight, this->getCurrLvl());
  this->_bullet->init(this->_player->getPos(), this->_player->_sprite.getGlobalBounds().width/2);
}

const int Game::getCurrLvl() {
   return this->_gameStruct.currLvl;
}

const bool Game::isGameOver() {
  if(_player->curHealth <= 0.f) {
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
  if(this->getCurrLvl() == 1) {
    bgTexture.loadFromFile("./utils/img/bg/bg00_bluemap.png");
  } else if(this->getCurrLvl() == 2) {
    bgTexture.loadFromFile("./utils/img/bg/bg00_bluemap_02.png");
  } else if(this->getCurrLvl() == 3) {
    bgTexture.loadFromFile("./utils/img/bg/bg00_bluemap_03.png");
  } else {
    bgTexture.loadFromFile("./utils/img/bg/bg00_bluemap_04.png");
  }
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
  if(DEBUG) {
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
          cout << "\n CLOSING WINDOW \n" << endl;
          this->_window->close();
          break;
        }
        break;
      case sf::Event::MouseButtonPressed:
        if(this->_event.MouseLeft) {
          if(DEBUG) cout << "\n MouseButton PRESSED (" << this->_mousePos.x << ", " << this->_mousePos.y << ") \n" << endl;
          if(this->isGameOver() && this->_overlay->isMousePressedAndContains(this->_mousePos, 01)) {
            cout << "\n CLICKED \n" << endl;
            cout << "\n CLICKED \n" << endl;
            cout << "\n CLICKED \n" << endl;
            cout << "\n CLICKED \n" << endl;
            cout << "\n CLICKED \n" << endl;
            cout << "\n CLICKED \n" << endl;
            cout << "\n CLICKED \n" << endl;
            cout << "\n CLICKED \n" << endl;
            cout << "\n CLICKED \n" << endl;
            this->restartGame = true;
            break;
          }

          if(this->isLevelFinished() && this->_overlay->isMousePressedAndContains(this->_mousePos, 04)) {
            this->_gameStruct.currLvl++;
            if(DEBUG) cout << "\n        CURRENT LVL(" << this->getCurrLvl() << ")  \n" << endl;

            this->_gameStruct.levelFinished = false;
            this->setBackground();
            this->_enemy->spawner(this->getCurrLvl());
            break;
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
      if(DEBUG) cout << "\n   ROTATION(" << this->_player->_sprite.getRotation() << ") \n" << endl;
      this->_player->_sprite.setRotation(this->_player->_sprite.getRotation() + 0.1f); /* needs clamp and lerp to orig on keyUP @TODO */
    }
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    if(this->_player->getPos().x > 0) {
      this->_player->move(-this->playerSpeed, 0.0);
    }
    if(playerRotation < rightClamp + 1 || playerRotation > leftClamp) {
      if(DEBUG) cout << "\n   ROTATION(" << this->_player->_sprite.getRotation() << ") \n" << endl;
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
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    if(DEBUG) cout << "\n Space PRESSED \n" << endl;
    this->_audio00.play();
    this->firing = true;
  }
}

void Game::fixedUpdate() {
  this->eventPolling();
  this->setMousePos();
  this->_overlay->Update(this->isGameOver(), this->_mousePos, this->_gameStruct.levelFinished, this->_gameStruct.currLvl);

  if(!isGameOver()) {
    for(int k=0; k < this->_enemy->_enemies.size(); k++) {
      if(this->_enemy->_enemies[k].type == kamikaze) {
        this->_enemy->moveToPlayer(k, this->_player->getPos(), 1.84f);
      } else if(this->_enemy->_enemies[k].type == sheriff) {
        this->_enemy->lookAtPlayer(k, this->_player->getPos());
      }

      if(collision.checkCollision(this->_player->_sprite.getGlobalBounds(), this->_enemy->_enemies[k].enemy.getGlobalBounds())){
        cout << "COLLIDED" << endl;
        if(this->_enemy->_enemies[k].type == kamikaze) {
          this->_enemy->delEnemy(k);
          this->_player->takeDmg(33.3);
        };
      }
    }

    for(int _i=0; _i < this->_enemy->_enemies.size(); _i++) {
      this->_bullet->move(3.3f, enemy);

      if(this->_enemy->_enemies[_i].health <= 0.f) {
        this->_enemy->delEnemy(_i);
        this->_player->score += 33.3f;
      }

      float angleToPlayer = this->_enemy->getAngleToPlayer(_i, this->_player->getPos());
      const float randomNumber = (rand() / static_cast <float> (RAND_MAX/(10.8f-0.8f))); /* (HI#-LO#)) */

      if(this->_enemyTimeElapsed.asSeconds() > randomNumber /* was 1.8f */
        && this->_enemy->_enemies[_i].type == sheriff) {
        /* @TODO make enemy firing sound */
        this->_bullet->fire(this->_enemy->getPosById(_i), this->_enemy->_enemies[_i].enemy.getGlobalBounds().width/2, angleToPlayer, enemy);
        this->_enemyClock.restart();
      }
    }

    for(int _j=0;_j < this->_bullet->enemyBullets.size();_j++) {
      if(collision.checkCollision(this->_player->_sprite.getGlobalBounds(), this->_bullet->enemyBullets[_j].bullet.getGlobalBounds())) {
        this->_player->takeDmg(10.f);
        this->_bullet->erase(_j, enemy);
      }

      if(this->_bullet->enemyBullets[_j].bullet.getPosition().x > screenWidth || this->_bullet->enemyBullets[_j].bullet.getPosition().y > screenHeight) {
        this->_bullet->erase(_j, enemy);
      }
    }

    for(int k=0;k < this->_bullet->playerBullets.size(); k++) {
      if(DEBUG) {
        cout << "\n  bullPosY(" << this->_bullet->playerBullets[k].bullet.getPosition().y << ")  \n" << endl;
        cout << "\n  bulletsVecSize(" << this->_bullet->playerBullets.size() << ") \n" << endl;
      }

      for(int j=0; j < this->_enemy->_enemies.size(); j++) {
        if(collision.checkCollision(this->_enemy->_enemies[j].enemy.getGlobalBounds(), this->_bullet->playerBullets[k].bullet.getGlobalBounds())) {
          cout << "\n ENEMY HIT BY BULLET \n" << endl;
          this->_enemy->takeDmg(j, 33.3);
          this->_bullet->erase(k, player);
          this->_player->score += 5.5f;
        }
      }

      if(this->_bullet->playerBullets[k].bullet.getPosition().y <= 100) {
        this->_bullet->erase(k, player);
      }
    } 
  }
}

void Game::update() {
  this->_timeElapsed = this->_clock.getElapsedTime(); /* @TODO del clocks in init */
  this->_trueElapsedTime = this->_trueClock.getElapsedTime();
  this->_enemyTimeElapsed = this->_enemyClock.getElapsedTime();
  this->_gameStruct.currScore = this->_player->score;
  this->_player->update();
  this->_enemy->update(this->getCurrLvl());
  if(DEBUG) cout << "\n   _timeElapsed: | " << this->_timeElapsed.asSeconds() << " |" << endl;

  if(this->_enemy->_enemies.size() <= 0) {
    this->_gameStruct.levelFinished = true;
  }

  int _counter = 0;
  _counter++;
  if(_counter > 2000) { _counter = 0; };
  if(this->_timeElapsed.asSeconds() > this->firingDelay) {
    this->_bgCloudsSprite.move(.01f, -0.00001f);
  } else if (_counter % 3 == 0) {
    this->_bgCloudsSprite.move(-.01f, 0.00001f);
  }

  if(DEBUG) cout << " \n   playerPos(" << this->_player->getPos().x << ", " << this->_player->_sprite.getPosition().y << ") \n" << endl;
  if(firing  && this->_timeElapsed.asSeconds() > this->firingDelay) {
    this->_bullet->fire(this->_player->getPos(), this->_player->_sprite.getGlobalBounds().width/2, 0, player);
    firing = false;
    this->_clock.restart();
  }

  this->_bullet->move(3.3f, player);
  if(DEBUG) cout << this->_player->_sprite.getGlobalBounds().width << " - boundsWidth \n" << this->_player->_sprite.getGlobalBounds().height << " - boundsHeight \n" << endl;
}

const bool Game::isLevelFinished() {
  return this->_gameStruct.levelFinished;
}

void Game::render() {
  this->_window->clear(sf::Color::Black);
  this->setBackground();
  this->_overlay->Render(*this->_window,this->introFinished, this->isLevelFinished(), this->isGameOver());

  if(this->introFinished && !isGameOver() && !isLevelFinished()) { // @TODO this made player del at window screen yet won't respawn after
    this->_bullet->render(*this->_window);
    this->_player->render(*this->_window);
    this->_enemy->render(*this->_window);
  } else {
    if(this->_trueElapsedTime.asSeconds() > 2.0f) this->introFinished = true;
    if(this->_gameStruct.levelFinished) this->introFinished = true;
  }

  if(this->isGameOver()) {
    _clock.restart();
    this->_bgMusic.stop();
    this->_audio01.play();

    if(restartGame) {
      this->_isFirstRun = false;
      delete this->_player;
      delete this->_enemy;
      delete this->_bullet;
      init();
      restartGame = false;
    }
  }
  /* DRAW HERE */

  this->_window->display();
}
