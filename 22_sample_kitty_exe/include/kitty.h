#pragma once

#include <iostream>
#include <string>

#include "feline.h"

class DomesticCat : 
	public Feline
{
private:
	std::string name_;
	std::string species_;
public:
	DomesticCat(const std::string& name = "", const std::string& species="");
	virtual ~DomesticCat();

	friend std::ostream& operator<<(std::ostream& os, const DomesticCat& rhs);

	//operator std::string() const;
	//operator int() const;
	virtual std::string get_description();

	virtual void make_sound();
};
