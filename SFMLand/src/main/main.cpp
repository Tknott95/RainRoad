#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;

int main() {
  cout << "\n App Initialized... \n" << endl;

  sf::RenderWindow window(sf::VideoMode(1280, 720), "Tks Flatland", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
  sf::Event event;

  while(window.isOpen()) {
    while(window.pollEvent(event)) {
      switch(event.type) {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::KeyPressed:
          if(event.key.code == sf::Keyboard::Escape){
            cout << "CLOSING WINDOW" << endl;
            window.close();
            break;
          }
          if (event.key.code == sf::Keyboard::Space){
            cout << "Space PRESSED" << endl;
            break;
          }
          break;
      }
    }

  window.clear(sf::Color::Blue);
  window.display();

  }
 
  return 0;
}
