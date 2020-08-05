#include "book.h"

#include <iostream>

Book::Book()
	: title ("")
	, reviewer(nullptr)
{

}

Book::Book(const std::string& title)
	: title(title)
	, reviewer(nullptr)
{

}

Book::Book(const Book& rhs)
	: title(rhs.title)
{
	this->reviewer = new Author(*rhs.reviewer);
	for each (auto author in rhs.authors)
	{
		this->addAuthor(new Author(*author));
	}
}

Book::~Book()
{
	for (std::vector<Author*>::iterator it = this->authors.begin(); it != this->authors.end(); ++it)
	{
		delete *it;
	}

	authors.clear();

	if (this->reviewer)
	{
		delete this->reviewer;
		this->reviewer = nullptr;
	}
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

void Book::setReviewer(Author* reviewer)
{
	// ownership of reviewer.
	if (this->reviewer)
	{
		delete this->reviewer;
	}

	this->reviewer = reviewer;
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

	if (this->reviewer)
	{
		std::cout << std::endl;
		std::cout << "* special review added by: " << this->reviewer->toString();
	}
	std::cout << std::endl;

	
}
