#include "book.h"

#include <iostream>

Book::Book()
	: title ("")
{

}

Book::Book(const std::string& title)
	: title(title)
{

}

Book::Book(const Book& rhs)
	: title(rhs.title),
	authors(rhs.authors)
{
	
}

Book::~Book()
{
	for (auto it = this->authors.begin(); it != this->authors.end(); ++it)
	{
		delete *it;
	}

	authors.clear();
}

void Book::setTitle(const std::string& title)
{
	this->title = title;
}

void Book::setAuthors(const std::vector<Author*>& authors)
{
	this->authors = authors;
}

void Book::addAuthor(Author* author)
{
	this->authors.emplace_back(author);
}

void Book::printToScreen()
{
	std::cout << this->title << " (by ";
	for (auto it = this->authors.begin(); it != this->authors.end(); ++it)
	{
		if (it != this->authors.begin())
		{
			std::cout << ", ";
		}
		//std::cout << it->toString();
		std::cout << (*it)->toString();
	}
	std::cout << ")" << std::endl;
}

void Book::printToScreenV2()
{
	std::cout << this->title;
	if (this->authors.size() > 0)
	{
		std::cout << " (by ";
		std::cout << (*this->authors.begin())->toString();

		for (auto it = ++this->authors.begin(); it != this->authors.end(); ++it)
		{
			std::cout << ", " << (*it)->toString();
		}
		std::cout << ")";
	}

	std::cout << std::endl;

	
}
