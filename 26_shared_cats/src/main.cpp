#include <iostream>
#include <vector>

#include "lion.h"
#include "feline.h"

#include "cat_factory.h"
#include "feline_reader.h"



void show_felines_in_collection(const std::vector<Feline*> &felines)
{
	for (Feline* feline : felines)
	{
		if (feline->get_species() == "lion")
		{
			// Can cast down
			Lion* lion_ptr = (Lion*)feline;
			if (lion_ptr)
			{

			}
			lion_ptr->speak();
			std::cout << "this lion is of the subspecies " << lion_ptr->get_subspecies() << std::endl;
		}
	}
}


auto  main() -> int
{
	std::cout << "-=== Shared cats ===-" << std::endl;

	std::vector<Feline*> felines;

	felines.emplace_back(createFelinePointer("lion", "Magunda"));
	felines.emplace_back(createFelinePointer("domestic_cat", "Tom"));

	//CatFactory::initialize();
	//felines = loadFromIniFile("../../data/26_shared_cats.ini");

	std::cout << std::endl << "-=== Silence! The cats are speaking ===-" << std::endl << std::endl;

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