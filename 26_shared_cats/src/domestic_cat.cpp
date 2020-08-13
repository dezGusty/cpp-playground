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

DomesticCat::DomesticCat(const std::string& name, const std::string& species)
	: Feline("domestic_cat")
	, name_(name)
	, species_(species)
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
	os << kitty.name_ << " specimen of " << kitty.species_;
	return os;
}

void DomesticCat::speak()
{
	std::cout << "Miau" << std::endl;
}


//Kitty::operator std::string() const
//{
//	std::string result(this->name_);
//	result.append(" (");
//	result.append(this->species_);
//	result.append(")");
//	return result;
//}

//Kitty::operator int() const
//{
//	return this->name_.length();
//}
