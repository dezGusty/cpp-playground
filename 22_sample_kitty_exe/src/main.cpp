#include <iostream>
#include <vector>

#include "abstract_feline.h"
#include "feline.h"
#include "lion.h"
#include "kitty.h"

Feline* createFelinePointer(std::string feline_type, std::string name)
{
	if (feline_type == "lion")
	{
		return new Lion();
	}
	else if (feline_type == "kitty")
	{
		return new Kitty(name);
	}
	else if (feline_type == "feline")
	{
		return new Feline();
	}

	return nullptr;
}

auto  main() -> int
{
	std::cout << "-=== Sample kitty ===-" << std::endl;

	std::vector<Feline*> felines;
	// read from file
	// for each ...
	//

	felines.emplace_back(createFelinePointer("lion", "jerry"));
	felines.emplace_back(createFelinePointer("kitty", "hello"));
	felines.emplace_back(createFelinePointer("feline", "undefined"));

	// print to screen
	for each(Feline* feline in felines)
	{
		feline->make_sound();
	}

	// clean-up
	for each(Feline* feline in felines)
	{
		delete feline;
	}

	return 0;
}