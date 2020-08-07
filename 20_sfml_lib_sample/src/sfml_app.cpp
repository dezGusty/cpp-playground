#include "sfml_app.h"

#include <iostream>
#include <thread>

SfmlApp::SfmlApp(
	std::pair<unsigned int, unsigned int> window_size,
	std::pair<unsigned int, unsigned int> cell_size
)
	: window_({ window_size.first, window_size.second }, "My window")
	, cell_size_(cell_size)
{
}

SfmlApp::~SfmlApp()
{
}

const sf::RenderWindow& SfmlApp::getWindow() const
{
	return this->window_;
}

std::string getMessageForActiveStatus(bool active)
{
	if (active)
	{
		return "Simulation is ACTIVE. Press <SPACE> to toggle the simulation.";
	}
	
	return "Simulation is PAUSED. Press <SPACE> to toggle the simulation.";
}

void SfmlApp::init()
{
	this->living_cell_color_ = sf::Color(40, 160, 20);
	this->dead_cell_color_ = sf::Color(25, 23, 21);

	if (font_.loadFromFile("../../data/OpenSans-Regular.ttf"))
	{
		gui_text_.setFont(font_);
		gui_text_.setString("Press <SPACE> to toggle the simulation");
		gui_text_.move(10, 2);
		gui_text_.setCharacterSize(16);
		gui_text_.setOutlineColor(sf::Color::White);
	}
	else
	{
		// error...cannot render GUI
	}

	// Note: you can also override the window size after it is initialized.
	// This could be useful to allow changing the resolution and the world size after the initialization
	// but is not really a priority for this exercise.
	//this->window.setSize(sf::Vector2u(1200, 600));

	// Initialize the vertices
	size_t max_width = static_cast<size_t>(window_.getView().getSize().x);
	size_t max_height = static_cast<size_t>(window_.getView().getSize().y);

	world_size_.first = max_height / cell_size_.first - 1;
	world_size_.second = max_height / cell_size_.second - 1;

	for (size_t cell_y = 0; cell_y < max_height / cell_size_.first - 1; cell_y++)
	{
		for (size_t cell_x = 0; cell_x < max_width / cell_size_.second - 1; cell_x++)
		{
			this->addVertexQuad(cell_x, cell_y, cell_size_.first, cell_size_.second);
		}
	}
}

void SfmlApp::run()
{
	unsigned time_elapsed_since_update = 0;
	bool simulation_active(true);
	// TODO: it would be nice to make this configurable in the future.
	unsigned duration_in_millis_between_updates = 1000;

	// run the program as long as the window is open
	while (window_.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window_.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
			{
				window_.close();
			}

			// quick close via the ESC key.
			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					window_.close();
					return;
				}
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					// Toggle simulation
					simulation_active = !simulation_active;
					gui_text_.setString(getMessageForActiveStatus(simulation_active));
				}
			}
		}

		if (time_elapsed_since_update > duration_in_millis_between_updates)
		{
			updateWorld();
			time_elapsed_since_update -= duration_in_millis_between_updates;
		}

		// clear the window with black color
		window_.clear(sf::Color::Black);

		render();

		// end the current frame
		window_.display();

		// don't consume too many cpu cycles
		std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(10));
		if (simulation_active)
		{
			time_elapsed_since_update += 10;
		}
	}
}

void SfmlApp::setCellColor(unsigned cell_x, unsigned cell_y, sf::Color color)
{
	auto index = (cell_y * this->world_size_.first + cell_x) * 4;
	if (index >= cell_vertices_.size())
	{
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		cell_vertices_[index + i].color = color;
	}
}

void SfmlApp::addVertexQuad(unsigned cell_x, unsigned cell_y, unsigned width, unsigned height)
{
	sf::Vertex topLeft;
	sf::Vertex topRight;
	sf::Vertex bottomLeft;
	sf::Vertex bottomRight;

	float pixelX = static_cast<float>(cell_x * width);
	float pixelY = static_cast<float>(cell_y * height);

	topLeft.position = { pixelX,               pixelY };
	topRight.position = { pixelX + width,    pixelY };
	bottomLeft.position = { pixelX,               pixelY + height };
	bottomRight.position = { pixelX + width,    pixelY + height };

	topLeft.color = dead_cell_color_;
	topRight.color = dead_cell_color_;
	bottomLeft.color = dead_cell_color_;
	bottomRight.color = dead_cell_color_;

	cell_vertices_.push_back(topLeft);
	cell_vertices_.push_back(bottomLeft);
	cell_vertices_.push_back(bottomRight);
	cell_vertices_.push_back(topRight);
}

#if 0
// Note: this is an early sample of trying to render using shapes. It is much slower than simply
// updating vertices.
void slow_render(sf::RenderWindow& window, unsigned rectWidth, unsigned rectHeight)
{
	// draw everything here...
	sf::RectangleShape rect(sf::Vector2f((float)rectWidth, (float)rectHeight));

	size_t max_width = static_cast<size_t>(window.getView().getSize().x);
	size_t max_height = static_cast<size_t>(window.getView().getSize().y);

	for (size_t cell_y = 0; cell_y < max_height / rectHeight - 1; cell_y++)
	{
		for (size_t cell_x = 0; cell_x < max_width / rectWidth - 1; cell_x++)
		{
			rect.setFillColor(sf::Color(80, 200, 40));

			float pos_x = cell_x * rectWidth;
			float pos_y = cell_y * rectHeight;
			if (cell_x % 2 == 0)
			{
				if (cell_y % 2 == 0)
				{
					rect.setFillColor(sf::Color(140, 100, 30));
				}
				else
				{
					rect.setFillColor(sf::Color(180, 120, 40));
				}
			}
			else if (cell_y % 2 == 0)
			{
				rect.setFillColor(sf::Color(60, 160, 20));
			}

			rect.setPosition(sf::Vector2f(pos_x, pos_y));
			window.draw(rect);
}
	}
}
#endif

void SfmlApp::render()
{
	// draw everything here...
	window_.draw(cell_vertices_.data(), cell_vertices_.size(), sf::Quads);

	// Add any GUI info.
	window_.draw(gui_text_);
}

void SfmlApp::updateWorld()
{
	// TODO: feel free to add function arguments as deemed necessary.

	setCellColor(rand() % world_size_.first, rand() % world_size_.second, living_cell_color_);
}