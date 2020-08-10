#pragma once

#include <string>

class AbstractFeline
{
public:
	AbstractFeline();
	virtual ~AbstractFeline();

	virtual std::string get_description() = 0;
};

