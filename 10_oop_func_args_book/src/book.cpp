// Includes

// Own header
#include "book.h"

// C system headers

// C++ system headers
#include <chrono>
#include <iostream>
#include <sstream>
#include <thread>

// other libs

// other headers in this project
// none

size_t Book::object_counter = 0;

Book::Book()
	: name(name)
	, authors(authors)
	, serial_number(0)
{
	std::cout << "[ctor] Creating a BLANK book..." << std::endl;
	std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(1000));
	std::cout << "[ctor] Book created (" << ++object_counter << ")" << std::endl;
}

Book::Book(const std::string& name, const std::string& authors, int sn)
	: name(name)
	, authors(authors)
	, serial_number(sn)
{
	// Construct the book.

	// Note: you could use
	// using namespace std::chrono_literals;
	// std::this_thread::sleep_for(2s);
	// OR
	// std::chrono::duration<int, std::milli> duration(400);
	// std::this_thread::sleep_for(duration);

	std::cout << "[ctor] Downloading content for [" << name << "]" << std::endl;

	std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(400));

	std::cout << "[ctor] Printing pages and cover... [" << name << "]" << std::endl;
	std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(800));
	std::cout << "[ctor] Book created. Counter: " << ++object_counter << "." << std::endl;
}

Book::~Book()
{
	std::cout << "[dtor] Burning book [" << this->toString() << "]" << std::endl;
	std::cout << "[dtor] Raising incinerator temperature to 451deg F (233 deg C) (autoignition temperature of paper.)" << std::endl;
	std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(500));
	std::cout << "[dtor] Incinerated book. Counter: " << --object_counter << std::endl;
}

Book::Book(const Book& rhs)
{
	std::cout << "[cpy] Using COPY machine to duplicate book [" << rhs.toString() << "]" << std::endl;
	std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(1000));

	this->authors = rhs.authors;
	this->name = rhs.name;
	this->serial_number = rhs.serial_number;
	std::cout << "[cpy] Book copied. Counter:" << ++object_counter << std::endl;
}

Book::Book(Book&& rhs) noexcept :
	authors(std::move(rhs.authors)),					// explicit move of a member of class type
	name(std::move(rhs.name)),							// explicit move of a member of class type
	serial_number(std::exchange(rhs.serial_number, 0))	// explicit move of a member of non-class type
{
	std::cout << "[move] MOVEd insides of book [" << this->toString() << "] to a different object. Old book is now blank. Counter:" << ++object_counter << std::endl;
}

Book& Book::operator=(const Book& rhs)
{
	this->name = rhs.name;
	this->authors = rhs.authors;
	this->serial_number = rhs.serial_number;
	return *this;
}

std::string Book::toString() const
{
	std::stringstream result;
	result << ">> " << this->name;
	result << " (by " << this->authors << ")";
	result << " SN:" << this->serial_number << ".";
	return result.str();
}

void Book::setSerialNumber(int serial_num)
{
	this->serial_number = serial_num;
}

void Book::setAuthors(const std::string& authors)
{
	this->authors = authors;
}

void Book::setName(const std::string& name)
{
	this->name = name;
}

void Book::prettyPrintForShipping(const std::string& content, const std::string& address)
{
	std::cout << "Shipping book [" << content << "] to address: " << address << std::endl;
}