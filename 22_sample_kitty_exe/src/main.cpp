#include <iostream>

#include <abstract_feline.h>
#include <feline.h>
#include <kitty.h>

AbstractFeline* createFelinePointer()
{
	return new Kitty();
}

void useStaticObjects()
{
	// try to create a feline
	Feline feline1;
	AbstractFeline* feline2 = createFelinePointer();
	std::cout << feline1.get_description() << std::endl;
	std::cout << feline2->get_description() << std::endl;
	delete feline2;
}

void tryCreateKitty()
{
	Kitty kitty("Puffy", "Norwegian Forest Cat");
	//std::cout << "A wild cat appears! \"" << kitty << "\"" << std::endl;
	/*std::cout << "A wild cat appears! \""
		<< static_cast<std::string>(kitty) << "\""<< std::endl;
*/
//std::string text =  kitty;
//int kitty_value = kitty;
//double kitty_float_value = kitty;
	std::cout << kitty << std::endl;
}

auto  main() -> int
{
	std::cout << "-=== Sample kitty ===-" << std::endl;

	useStaticObjects();
	//tryCreateKitty();
	return 0;
}