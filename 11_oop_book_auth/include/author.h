#pragma once

#include <string>

class Author
{
public:
	static int obj_counter;

protected:
	std::string name;

public:
	Author(const std::string& name="anon");
	Author(const Author& rhs);
	virtual ~Author();
	virtual std::string toString() const;
};
