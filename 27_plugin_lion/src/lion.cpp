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
// none

// 5. Other libraries' headers, in alphabetical order.
// none

Lion::Lion(const std::string & name, const std::string& subspecies)
	: Feline("lion")
	, name_(name)
	, subspecies_(subspecies)
{
#ifdef CTOR_DTOR_MSG
	std::cout << "Lion " << name_ << " created." << std::endl;
#endif //CTOR_DTOR_MSG
}

Feline* Lion::create(const std::string & name, const std::string& subspecies)
{
	return new Lion(name, subspecies);
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

Feline* createFeline(const std::string& name, const std::string& subspecies)
{
	return Lion::create(name, subspecies);
}

Feline* createFelineExt(const char* name, const char* subspecies)
{
	return Lion::create(name, subspecies);
}