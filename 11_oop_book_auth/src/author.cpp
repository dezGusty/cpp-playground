#include "author.h"

size_t Author::obj_counter = 0;

Author::Author(const std::string& name)
	: name(name)
{
	obj_counter++;
}

Author::~Author()
{
	obj_counter--;
}

std::string Author::toString() const
{
	return this->name;
}