#pragma once

#include "SFML/Graphics.hpp"

class SfmlApp
{
private:
	sf::RenderWindow window;

public:
	SfmlApp(std::pair<unsigned int, unsigned int> window_size);
	~SfmlApp();

	const sf::RenderWindow& getWindow() const;
	void init();
	void run();
	void render();
};