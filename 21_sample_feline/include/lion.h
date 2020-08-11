#pragma once

#include <string>

#include "feline.h"

class Lion: public Feline
{
public:
	Lion();
	virtual ~Lion();

	virtual std::string get_description();
	virtual void make_sound();
};

