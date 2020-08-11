
#include "SFML/Graphics.hpp"

#include "sfml_app.h"

#ifdef _WIN32
#include <windows.h>
#endif

void hide_console()
{
#ifdef _WIN32
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
#endif
}

int main()
{
	hide_console();

	// TODO: maybe load from a configuration file? INI file?
	std::pair<unsigned int, unsigned int> preferred_window_size;
	preferred_window_size.first = 1200;
	preferred_window_size.second = 600;

	std::pair<unsigned int, unsigned int> preferred_cell_size;
	preferred_cell_size.first = 5;
	preferred_cell_size.second = 5;


	SfmlApp app(preferred_window_size, preferred_cell_size);
	app.init();
	app.run();
}