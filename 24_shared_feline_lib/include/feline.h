#pragma once

//
// Includes
//

// 1. Platform specific definitions and overall build options for the library.
#include "build_opts_feline.h"

// 2. C system headers, in alphabetical order.
// none

// 3. C++ system headers, in alphabetical order.
#include <string>

// 4. This library's headers, in alphabetical order.
// none

// 5. Other libraries' headers, in alphabetical order.
// none

class FELINES_IMPEXP Feline
{
private:
	std::string species_;
public:
	Feline(const std::string& species);
	virtual ~Feline();

	// Actions for felines.
	// Assume we live in a world where cats speak.
	virtual void speak() = 0;

	virtual const std::string& get_species() const
	{
		return species_;
	}
};

std::string FELINES_IMPEXP getFelineLibVersion();
