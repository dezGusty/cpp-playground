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
public:
	static size_t object_counter;

public:
	Book();
	Book(const std::string& name, const std::string& authors, int sn);
	~Book();

	// Copy Constructor
	Book(const Book& rhs);

	// Move Constructor.
	Book(Book&& rhs) noexcept /*= default*/;

	Book& operator=(const Book& rhs);

	void setSerialNumber(int serial_num);
	void setAuthors(const std::string& authors);
	void setName(const std::string& name);

	static void prettyPrintForShipping(const std::string& content, const std::string& address);

	std::string toString() const;
};
