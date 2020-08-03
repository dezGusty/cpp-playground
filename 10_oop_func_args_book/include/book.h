#pragma once

// Includes

// C system headers

// C++ system headers
#include <string>

// other libs

class Book
{
private:
	std::string name;
	std::string authors;
	int serial_number;
	size_t internal_id;
	static size_t object_counter;

public:
	Book();
	Book(const std::string& name, const std::string& authors, int sn);
	~Book();
	Book(const Book& rhs);
	Book(Book&& rhs) noexcept /*= default*/;

	void setSerialNumber(int serial_num);
	void setAuthors(const std::string& authors);
	void setName(const std::string& name);

	std::string toString() const;
};
