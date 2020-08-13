//
// Includes
//

// 1. Own header for C/C++ file.
#include "feline.h"

// 2. C system headers, in alphabetical order.
// none

// 3. C++ system headers, in alphabetical order.
#include <iostream>
#include <string>

// 4. This library's headers, in alphabetical order.
#include "constants.h"

// 5. Other libraries' headers, in alphabetical order.
// none

Feline::Feline(const std::string& species)
	: species_(species)
{
}

Feline::~Feline()
{
#ifdef CTOR_DTOR_MSG
	std::cout << "Feline (unknwon) destroyed." << std::endl;
#endif //CTOR_DTOR_MSG
}

std::string getFelineLibVersion()
{
	return "1.0";
}
