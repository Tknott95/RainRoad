#include "../headers/game.h"


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

// void Draw_Cuboid(float width,float height,float depth){
// 	static GLfloat points[][3]={
//    {1.0f,1.0f,1.0f},
// 		{1.0f,1.0f,0.0f},
// 		{0.0f,1.0f,0.0f},
// 		{0.0f,1.0f,1.0f},
// 		{1.0f,0.0f,1.0f},
// 		{1.0f,0.0f,0.0f},
// 		{0.0f,0.0f,0.0f},
// 		{0.0f,0.0f,1.0f}
//   };

// 	GLfloat normal[3];
// 	glPushMatrix();	
// 	glScalef(width,height,depth);
// 	glTranslatef(-0.5,-0.5,-0.5);
// 	glBegin(GL_QUADS);
	
//   //top
// 	//NormalVector(points[0],points[1],points[2],normal);
// 	glNormal3fv(normal);
// 	glColor3d(1.0,1.0,1.0);
// 	glVertex3fv(points[0]); glVertex3fv(points[1]); glVertex3fv(points[2]); glVertex3fv(points[3]);
		
// 	//front
// 	//NormalVector(points[0],points[3],points[7],normal);
// 	glNormal3fv(normal);
// 	glColor3d(1.0,0.0,1.0);
// 	glVertex3fv(points[0]); glVertex3fv(points[3]); glVertex3fv(points[7]); glVertex3fv(points[4]);

// 	//back
// 	//NormalVector(points[1],points[5],points[6],normal);
// 	glNormal3fv(normal);
// 	glColor3d(1.0,1.0,0.0);
// 	glVertex3fv(points[1]); glVertex3fv(points[5]); glVertex3fv(points[6]); glVertex3fv(points[2]);

// 	//left
// 	//NormalVector(points[3],points[2],points[6],normal);
// 	glNormal3fv(normal);
// 	glColor3d(0.0,1.0,0.0);
// 	glVertex3fv(points[3]); glVertex3fv(points[2]); glVertex3fv(points[6]); glVertex3fv(points[7]);

// 	//right
// 	//NormalVector(points[1],points[0],points[4],normal);
// 	glNormal3fv(normal);
// 	glColor3d(0.0,0.0,1.0);
// 	glVertex3fv(points[1]); glVertex3fv(points[0]); glVertex3fv(points[4]); glVertex3fv(points[5]);

// 	//bottom
// 	//NormalVector(points[4],points[7],points[6],normal);
// 	glNormal3fv(normal);
// 	glColor3d(1.0,0.0,0.0);
// 	glVertex3fv(points[4]); glVertex3fv(points[7]); glVertex3fv(points[6]); glVertex3fv(points[5]);

// 	glEnd();
// 	glPopMatrix();
// }

void Game::Render() {
  this->_window->clear(sf::Color::Black);

  // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // glViewport(0, 0, this->_window->getSize().x, this->_window->getSize().y);
  // glMatrixMode(GL_PROJECTION); 
  // glLoadIdentity(); 
	// glMatrixMode(GL_MODELVIEW); 
	// glLoadIdentity();

  // static float ang=0.0;
	// ang+=0.0314f;

  // Draw_Cuboid(0.10,0,0);
	// for (int i=0; i < 4; i++) {
  //   glRotatef(ang*10.5,-1.3*ang,3*i,1.3*i);
  //   glTranslatef(.10, 0.14, -0.10);
  //   glScalef(0.7314, 0.8314, 1.0014);
	// 	Draw_Cuboid(0.44,0.44,0.14);
	// } 
  // this->_window->pushGLStates();
  // this->_window->popGLStates();  
  // glEnd();

  this->_overlay->Init(this->screenWidth, this->screenHeight);
  this->_overlay->Render(*this->_window);

  this->_window->setActive(true);
  this->_window->display();
}
