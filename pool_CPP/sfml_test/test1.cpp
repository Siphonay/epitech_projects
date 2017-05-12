#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

int			main(void)
{
  sf::RenderWindow	app(sf::VideoMode(800, 600, 32), "Hello SFML!",
			    sf::Style::Close | sf::Style::Titlebar);
  sf::ConvexShape	convex;

  app.setFramerateLimit(60);
  srand(time(NULL));
  convex.setPointCount(5);
  convex.setFillColor(sf::Color(198, 255, 0));
  convex.setOutlineThickness(7);
  convex.setOutlineColor(sf::Color(103, 58, 183));
  
  while (app.isOpen())
    {
      sf::Event		event;

      while (app.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    app.close();
	}
      app.clear();
      convex.setPoint(0, sf::Vector2f((rand() % 800 + 1), (rand() % 600 + 1)));
      convex.setPoint(1, sf::Vector2f((rand() % 800 + 1), (rand() % 600 + 1)));
      convex.setPoint(2, sf::Vector2f((rand() % 800 + 1), (rand() % 600 + 1)));
      convex.setPoint(3, sf::Vector2f((rand() % 800 + 1), (rand() % 600 + 1)));
      convex.setPoint(4, sf::Vector2f((rand() % 800 + 1), (rand() % 600 + 1)));
      app.draw(convex);
      app.display();
    }

  return (EXIT_SUCCESS);
}
