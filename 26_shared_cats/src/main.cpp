#include <iostream>
#include <vector>

#include "lion.h"
#include "feline.h"

#include "feline_factory.h"
#include "feline_reader.h"



void show_lions_subspecies_in_collection(const std::vector<Feline*> &felines)
{
	for (Feline* feline : felines)
	{
		//if (feline->get_species() == "lion")
		{
			// Can cast down
			Lion* lion_ptr = dynamic_cast<Lion*>(feline);
			if (lion_ptr)
			{
				std::cout << "this lion is of the subspecies [" << lion_ptr->get_subspecies() << "]"<< std::endl;
			}
		}
	}
}

void addHardcodedFelines(std::vector<Feline*>& felines)
{
	felines.emplace_back(createFelinePointer("lion", "Magunda", "P. l. persica"));
	felines.emplace_back(createFelinePointer("domestic_cat", "Haralambie", "Tabby cat"));
	felines.emplace_back(createFelinePointer("lion", "Scar", "P. l. leo"));
	felines.emplace_back(createFelinePointer("domestic_cat", "Bubbles", "arctic cat"));
}

auto  main() -> int
{
	std::cout << "-=== Shared cats ===-" << std::endl;

	std::vector<Feline*> felines;
	addHardcodedFelines(felines);

	FelineFactory::initialize();
	std::vector<Feline*> more_felines = loadFromIniFile("../../data/26_shared_cats.ini");
	
	// Copy all entries from [more_felines] to the end of [felines]
	felines.insert(std::end(felines), std::begin(more_felines), std::end(more_felines));
	show_lions_subspecies_in_collection(felines);

	std::cout << std::endl << "-=== Silence! The cats are speaking ===-" << std::endl << std::endl;
	for (Feline* feline : felines)
	{
		feline->speak();
	}

	// Clean-up
	for (Feline* feline : felines)
	{
		delete feline;
	}

	return 0;
}