//
// Includes
//

// 1. Own header for C/C++ file.
#include "domestic_cat.h"

// 2. C system headers, in alphabetical order.
// none

// 3. C++ system headers, in alphabetical order.
#include <iostream>
#include <string>

// 4. This library's headers, in alphabetical order.
// none

// 5. Other libraries' headers, in alphabetical order.
// none

DomesticCat::DomesticCat(const std::string& name, const std::string& subspecies)
	: Feline("domestic_cat")
	, name_(name)
	, subspecies_(subspecies)
{

}

DomesticCat::~DomesticCat()
{

}

std::string DomesticCat::get_description()
{
	return "kitty";
}

std::ostream& operator<<(std::ostream& os, const DomesticCat& kitty)
{
	os << kitty.name_ << " specimen of " << kitty.subspecies_;
	return os;
}

void DomesticCat::speak()
{
	std::cout << this->name_ << " says: Miau!" << std::endl;
}

Feline* DomesticCat::create(const std::string& name, const std::string& subspecies)
{
	return new DomesticCat(name, subspecies);
}
