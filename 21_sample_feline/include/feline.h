#pragma once

#include <string>

class Feline
{
public:
	Feline();
	virtual ~Feline();

	virtual std::string get_description();
};

