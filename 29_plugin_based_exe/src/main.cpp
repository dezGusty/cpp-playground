//
// Includes
//

// 1. Own header for C/C++ file.
//none

// 2. C system headers, in alphabetical order.
// none

// 3. C++ system headers, in alphabetical order.
#include <iostream>
#include <sstream>
#include <vector>

// 4. This library's headers, in alphabetical order.
#include "feline_factory.h"
#include "feline_reader.h"
#include "guslib/system/dynamiclibmanager.h"
#include "guslib/common/simpleexception.h"

// 5. Other libraries' headers, in alphabetical order.
#include <lion.h>
#include <feline.h>
#include <SimpleIni.h>

// Parse the file name, make the following assumption
// file name: *_plugin_lion.extension => key name: lion
// E.g. 27_plugin_lion.dll => lion
// E.g. 28_plugin_lynx.so => lynx
std::string getFelineNameFromPluginFileName(const std::string& ini_file_name)
{
	const std::string kPLUGIN_KEYWORD("_plugin_");

	// find the plugin keyword
	size_t plugin_pos = ini_file_name.find(kPLUGIN_KEYWORD);
	if (plugin_pos != std::string::npos)
	{
		std::string second_part = ini_file_name.substr(plugin_pos + kPLUGIN_KEYWORD.length());

		// also get rid of the extension
		plugin_pos = second_part.find(".");
		if (plugin_pos != std::string::npos)
		{
			return second_part.substr(0, plugin_pos);
		}

		return second_part;
	}
	return ini_file_name;
}

void loadPluginsFromIniFile(const std::string& ini_file_name)
{
	CSimpleIniA ini;
	ini.SetUnicode();
	ini.LoadFile(ini_file_name.c_str());
	const char* numPluginsStr = ini.GetValue("plugins", "num_plugins", "0");
	int num_plugins = atoi(numPluginsStr);
	for (int i = 1; i <= num_plugins; ++i)
	{
		// build the plugin name E.g. plugin.1
		std::stringstream plugin_key_name;
		plugin_key_name << "plugin.";
		plugin_key_name << i;
		std::string plugin_file_name = ini.GetValue(
			"plugins",
			plugin_key_name.str().c_str(),
			"");

		try
		{
			guslib::DynamicLib* lib_ptr =
				guslib::DynamicLibManager::getPtr()->load(plugin_file_name);
			std::cout << "Loaded library: " << lib_ptr->getName() << std::endl;

			// Load a function pointer
			FelineCreateFcPtr fc_ptr = (FelineCreateFcPtr)(lib_ptr->getSymbol("createFeline"));
			if (nullptr == fc_ptr)
			{
				std::cout << "! could not locate the function createFeline" << std::endl;
			}
			else
			{
				// Get the name to use for this feline
				std::string feline_name_to_use_in_factory(getFelineNameFromPluginFileName(lib_ptr->getName()));
				// Register the function pointer to create this feline.
				FelineFactory::register_cat(
					feline_name_to_use_in_factory,
					fc_ptr);
			}
		}
		catch (std::exception& ex)
		{
			std::cout << "exception " << ex.what() << std::endl;
		}
	}
}

auto  main() -> int
{
	std::cout << "-=== Shared cats ===-" << std::endl;

	std::string plugins_config_file_name("../../data/29_plugin_based_cats.ini");

	std::cout << "Will try to load plugins from file: " << plugins_config_file_name << std::endl;
	loadPluginsFromIniFile(plugins_config_file_name);

	std::vector<Feline*> felines;

	//FelineFactory::initialize();
	std::vector<Feline*> more_felines = loadFromIniFile("../../data/29_plugin_based_cats.ini");

	// Copy all entries from [more_felines] to the end of [felines]
	felines.insert(std::end(felines), std::begin(more_felines), std::end(more_felines));

	//std::cout << std::endl << "-=== Silence! The cats are speaking ===-" << std::endl << std::endl;
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