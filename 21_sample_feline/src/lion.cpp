#include "lion.h"

#include <iostream>
#include <string>

Lion::Lion()
{

}

Lion::~Lion()
{

}

std::string Lion::get_description()
{
	return "(lion)";
}

void Lion::make_sound()
{
	std::cout << "Roar" << std::endl;
}