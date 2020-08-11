//
// Includes
//

// 1. Own header for C/C++ file.
#include "lion.h"

// 2. C system headers, in alphabetical order.
// none

// 3. C++ system headers, in alphabetical order.
#include <iostream>
#include <string>

// 4. This library's headers, in alphabetical order.
#include "constants.h"

// 5. Other libraries' headers, in alphabetical order.
// none

Lion::Lion(const std::string & name)
	: name_(name)
{
#ifdef CTOR_DTOR_MSG
	std::cout << "Lion " << name_ << " created." << std::endl;
#endif //CTOR_DTOR_MSG
}

Feline* Lion::create(const std::string & name)
{
	return new Lion(name);
}

Lion::~Lion()
{
#ifdef CTOR_DTOR_MSG
	std::cout << "Lion " << name_ << " destroyed." << std::endl;
#endif //CTOR_DTOR_MSG
}

void Lion::speak()
{
	std::cout << name_ << " says: ";
	std::cout << "Roar";
	std::cout << "!" << std::endl;
}
