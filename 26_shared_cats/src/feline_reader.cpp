//
// Includes
//

// 1. Own header for C/C++ file.
#include "feline_reader.h"

// 2. C system headers, in alphabetical order.
// none

// 3. C++ system headers, in alphabetical order.
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// 4. This library's headers, in alphabetical order.
#include "feline_factory.h"
#include "domestic_cat.h"

// 5. Other libraries' headers, in alphabetical order.
#include "lion.h"
#include "SimpleIni.h"

Feline* createFelinePointer(const std::string& feline_type, const std::string& name, const std::string& option)
{
	if (feline_type == "lion")
	{
		return Lion::create(name, option);
	}
	else if (feline_type == "domestic_cat")
	{
		return DomesticCat::create(name, option);
	}
	else if (feline_type == "lynx")
	{
		// return new Lynx(...);
	}


	return nullptr;
}

std::vector<Feline*> loadFromIniFile(const std::string& fileName)
{
	std::vector<Feline*> felines;

	CSimpleIniA ini;
	ini.SetUnicode();
	ini.LoadFile(fileName.c_str());
	const char* numFelinesStr = ini.GetValue("general", "num_cats", "0");
	int numFelines = atoi(numFelinesStr);

	std::string container_category("felines");

	for (int i = 1; i <= numFelines; ++i)
	{
		std::stringstream key_name;
		key_name << "feline";
		key_name << i;
		key_name << ".type";
		std::string type_key_name = key_name.str();
		std::string feline_type(ini.GetValue("felines", type_key_name.c_str(), ""));

		key_name.str("");
		key_name << "feline";
		key_name << i;
		key_name << ".name";
		std::string name_key_name = key_name.str();
		std::string feline_name(ini.GetValue("felines", name_key_name.c_str(), ""));

		key_name.str("");
		key_name << "feline";
		key_name << i;
		key_name << ".option";
		std::string option_key_name = key_name.str();
		std::string feline_option(ini.GetValue("felines", option_key_name.c_str(), ""));

		// Create a cat with a given type and name.
		Feline* feline_to_create = nullptr;
		std::cout << "*name: " << feline_name << std::endl;
		std::cout << "*type: " << feline_type << std::endl;
		std::cout << "*option: " << feline_option << std::endl;
		
		//feline_to_create = createFelinePointer(feline_type, feline_name, feline_option);

		// TODO: use factory?
		feline_to_create = FelineFactory::create(feline_type, feline_name, feline_option);

		if (nullptr != feline_to_create)
		{
			felines.emplace_back(feline_to_create);
		}
		else
		{
			// No feline?
			std::cout << "Could not create a Feline for type [" << feline_type << "]" << std::endl;
		}
	}

	return felines;
}