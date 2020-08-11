#include <iostream>
#include <vector>

#include "lion.h"
#include "feline.h"

Feline* createFelinePointer(std::string feline_type, std::string name)
{
	if (feline_type == "lion")
	{
		return new Lion(name);
	}
	

	return nullptr;
}

auto  main() -> int
{
	std::cout << "-=== Shared cats ===-" << std::endl;

	std::vector<Feline*> felines;
	// read from file
	// for each ...
	//

	felines.emplace_back(createFelinePointer("lion", "Magunda"));
	//felines.emplace_back(createFelinePointer("kitty", "hello"));

	// print to screen
	for (Feline* feline : felines)
	{
		feline->speak();
	}

	// clean-up
	for (Feline* feline : felines)
	{
		delete feline;
	}

	return 0;
}