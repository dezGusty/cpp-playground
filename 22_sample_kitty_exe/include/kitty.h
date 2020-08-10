#pragma once

#include <iostream>
#include <string>

#include "feline.h"
#include "abstract_feline.h"

class Kitty : 
	//public AbstractFeline,
	public Feline
{
private:
	std::string name_;
	std::string species_;
public:
	Kitty(const std::string& name = "", const std::string& species="");
	virtual ~Kitty();

	//friend std::ostream& operator<<(std::ostream& os, const Kitty& rhs);

	operator std::string() const;
	//virtual std::string get_description() = 0;
};
