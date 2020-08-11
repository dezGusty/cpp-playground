#pragma once

// header for vector
#include <vector>
// header for utility
#include <utility>
// SFML headers
#include "SFML/Graphics.hpp"

class SfmlApp
{
private:
	sf::RenderWindow window_;
	std::vector<sf::Vertex> cell_vertices_;
	std::pair<unsigned int, unsigned int> cell_size_;
	std::pair<unsigned int, unsigned int> world_size_;

	sf::Color living_cell_color_;
	sf::Color dead_cell_color_;
	sf::Text gui_text_;
	sf::Font font_;

public:
	/**
		Constructor.
		can provide some initialization / sizes to use.
		These could be moved to a separate configuration object at some point.
	*/
	SfmlApp(
		std::pair<unsigned int, unsigned int> window_size, 
		std::pair<unsigned int, unsigned int> cell_size
	);

	~SfmlApp();

	void init();
	void run();
	void render();

	void addVertexQuad(unsigned cell_x, unsigned cell_y, unsigned width, unsigned height);
	void setCellColor(unsigned cell_x, unsigned cell_y, sf::Color color);
	void updateWorld();
};