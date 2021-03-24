#include <SFML/Graphics.hpp>

// Ridge Line Rush code-base
// basic window template in SFML
// Team Members:
//              Johnny Clapham
//              Evelyn Showalter
//              John Svoboda
//              Moses Alexander

int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Ridge Rush");

  // start main loop
  while(App.isOpen())
  {
    // process events
    sf::Event Event;
    while(App.pollEvent(Event))
    {
      // Exit
      if(Event.type == sf::Event::Closed)
        App.close();
    }

    // clear screen and fill with blue
    App.clear(sf::Color::Blue);

    // display
    App.display();
  }

  // Done.
  return 0;
}
