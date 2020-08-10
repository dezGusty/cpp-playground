#include <iostream>

#include <abstract_feline.h>
#include <feline.h>
#include <kitty.h>

void useStaticObjects()
{
	// try to create a feline
	Feline feline1;

	//AbstractFeline abs_feline;
}

AbstractFeline* createFelinePointer()
{
	return nullptr;
}

void tryCreateKitty()
{
	Kitty kitty("Puffy", "Norwegian Forest Cat");
	//std::cout << "A wild cat appears! \"" << kitty << "\"" << std::endl;
	std::cout << "A wild cat appears! \"" 
		<< static_cast<std::string>(kitty) << "\""<< std::endl;

}

auto  main() -> int
{
	std::cout << "Sample kitty" << std::endl;

	useStaticObjects();
	tryCreateKitty();
	return 0;
}