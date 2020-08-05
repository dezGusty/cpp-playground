#pragma once

#include <string>

class Author
{
public:
	static size_t obj_counter;

protected:
	std::string name;

public:
	Author(const std::string& name="anon");
	virtual ~Author();
	virtual std::string toString() const;
};
