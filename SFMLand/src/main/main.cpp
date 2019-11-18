#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;

int main() {
  cout << "\n App Initialized... \n" << endl;

  sf::Window window(sf::VideoMode(640, 480), "Tks Flatland", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
  sf::Event event;

  while(window.isOpen()) {
    while(window.pollEvent(event)) {
      switch(event.type) {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::KeyPressed:
          if(event.key.code == sf::Keyboard::Escape)
            window.close();
          break;
      }
    }
  }
 
  return 0;
}
