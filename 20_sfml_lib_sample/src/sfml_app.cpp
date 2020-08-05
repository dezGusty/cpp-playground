#include "sfml_app.h"

#include <thread>

SfmlApp::SfmlApp(std::pair<unsigned int, unsigned int> window_size)
	: window({ window_size.first, window_size.second }, "My window")
{
}

SfmlApp::~SfmlApp()
{
}

const sf::RenderWindow& SfmlApp::getWindow() const
{
	return this->window;
}

void SfmlApp::init()
{
	this->window.setSize(sf::Vector2u(1200, 600));
}

void SfmlApp::run()
{
	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		render();

		// end the current frame
		window.display();

		// don't consume too many cpu cycles
		std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(10));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}
}

void SfmlApp::render()
{
	// draw everything here...
	sf::RectangleShape rect(sf::Vector2f(20.0, 20.0));
	rect.setFillColor(sf::Color(80, 200, 40));
	float x = 20.0;
	float y = 40.0;
	rect.setPosition(sf::Vector2f(x, y));
	
	window.draw(rect);
	
	rect.setPosition(sf::Vector2f(80.0, 120.0));
	window.draw(rect);

	rect.setPosition(sf::Vector2f(180.0, 20.0));
	window.draw(rect);

}