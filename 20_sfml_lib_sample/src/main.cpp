
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
	std::pair<unsigned int, unsigned int> preferred_size;
	preferred_size.first = 1200;
	preferred_size.second = 600;

	SfmlApp app(preferred_size);
	app.init();
	app.run();
}