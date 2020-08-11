#include "kitty.h"

Kitty::Kitty(const std::string& name, const std::string& species)
	: name_(name)
	, species_(species)
{

}

Kitty::~Kitty()
{

}

std::string Kitty::get_description()
{
	return "kitty";
}

std::ostream& operator<<(std::ostream& os, const Kitty& kitty)
{
	os << kitty.name_ << " specimen of " << kitty.species_;
	return os;
}

void Kitty::make_sound()
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
