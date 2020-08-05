#include <string>
#include <vector>

#include "author.h"

class Book
{
private:
	std::string title;
	std::vector<Author*> authors;
	
	Author* reviewer;

public:
	Book();
	Book(const std::string& title);

	Book(const Book& rhs);
	~Book();

	void printToScreenV2();

	void setAuthors(const std::vector<Author*>& author);
	void addAuthor(Author* author);
	void setReviewer(Author* reviewer);
	void setTitle(const std::string& title);
};

