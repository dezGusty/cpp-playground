#pragma once

//
// Includes
//

// 1. Platform specific definitions and overall build options for the library.
#include "build_opts_lynx.h"

// 2. C system headers, in alphabetical order.
// none

// 3. C++ system headers, in alphabetical order.
#include <string>

// 4. This library's headers, in alphabetical order.
#include "feline.h"

// 5. Other libraries' headers, in alphabetical order.
// none

class LYNX_IMPEXP Lynx : public Feline
{
private:
	std::string name_;
	std::string subspecies_;

public:
	Lynx(const std::string& name, const std::string& subspecies);
	virtual ~Lynx();
	virtual void speak();

	virtual const std::string& get_subspecies() const
	{
		return subspecies_;
	}
	virtual void set_subspecies(const std::string& subspecies) 
	{
		subspecies_ = subspecies;
	}

	static Feline* create(const std::string& name, const std::string& subspecies);
};

// Due to name mangling, export a simple C interface for the creation function.
extern "C"
{
	LYNX_IMPEXP Feline* createFeline(const std::string& name, const std::string& subspecies);
}