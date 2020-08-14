//
// Includes
//

// 1. Own header for C/C++ file.
#include "lynx.h"

// 2. C system headers, in alphabetical order.
// none

// 3. C++ system headers, in alphabetical order.
#include <iostream>
#include <string>

// 4. This library's headers, in alphabetical order.
// none

// 5. Other libraries' headers, in alphabetical order.
// none

Lynx::Lynx(const std::string & name, const std::string& subspecies)
	: Feline("lynx")
	, name_(name)
	, subspecies_(subspecies)
{
}

Feline* Lynx::create(const std::string & name, const std::string& subspecies)
{
	return new Lynx(name, subspecies);
}

Lynx::~Lynx()
{
}

void Lynx::speak()
{
	std::cout << name_ << " says: ";
	std::cout << "Grrr";
	std::cout << "!" << std::endl;
}

Feline* createFeline(const std::string& name, const std::string& subspecies)
{
	return Lynx::create(name, subspecies);
}