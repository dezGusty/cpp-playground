#pragma once

#include <iostream>
#include <string>

#include "feline.h"

class DomesticCat : 
	public Feline
{
private:
	std::string name_;
	std::string subspecies_;
public:
	DomesticCat(const std::string& name = "", const std::string& subspecies="");
	virtual ~DomesticCat();

	friend std::ostream& operator<<(std::ostream& os, const DomesticCat& rhs);

	//operator std::string() const;
	//operator int() const;
	virtual std::string get_description();

	virtual void speak();

	static Feline* create(const std::string& name, const std::string& subspecies);
};
