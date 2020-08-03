// Includes

// Own header

// C system headers

// C++ system headers
#include <iostream>
#include <vector>

// other libs

// other headers in this project
#include "book.h"

void shipBookToAddressA(Book book, const std::string& address)
{
	Book::prettyPrintForShipping(book.toString(), address);
}

void shipBookToAddressB(const Book& book, const std::string& address)
{
	book.prettyPrintForShipping(book.toString(), address);
	book.prettyPrintForShipping("bonus-card", address);
}

void shipBookToAddressC(const Book* book, const std::string& address)
{
	book->prettyPrintForShipping(book->toString(), address);
}

void tempFunction()
{
	std::vector<Book*> books;

	books.push_back(new Book("Fahrenheit 451", "Ray Bradbury", 1001));
	{
		books.push_back(new Book("Catch-22", "Joseph Heller", 1003));
		if (true)
		{
			books.push_back(new Book("The Psychopath Test ", "Jon Ronson", 1004));
		}
	}

	for (Book* temp : books)
	{
		delete temp;
	}
}

void dynamicArrays()
{
	Book** books =  new Book*[3];
	books[0] = new Book("Fahrenheit 451", "Ray Bradbury", 1001);
	{
		books[1] = new Book("Catch-22", "Joseph Heller", 1003);
		if (true)
		{
			books[2] = new Book("The Psychopath Test ", "Jon Ronson", 1004);
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		delete books[i];
	}

	delete[] books;
}

void dynamicArrays2()
{
	Book* books = new Book[3];
	books[0] = Book("Fahrenheit 451", "Ray Bradbury", 1001);
	{
		books[1] = Book("Catch-22", "Joseph Heller", 1003);
		if (true)
		{
			books[2] = Book("The Psychopath Test ", "Jon Ronson", 1004);
		}
	}

	delete[] books;
}

int main(int argc, char* argv[])
{
	// Create a book
	Book myBook("Fahrenheit 451", "Ray Bradbury", 1001);
	//Book book2("Europe: A History", "Norman Davies", 1002);

	std::cout << "--------------------" << std::endl;
	shipBookToAddressA(myBook, "Bv, AFI, birou A");
	std::cout << "--------------------" << std::endl;
	shipBookToAddressB(myBook, "Bv, AFI, birou B");
	std::cout << "--------------------" << std::endl;
	shipBookToAddressC(&myBook, "Bv, AFI, birou C");
	std::cout << "--------------------" << std::endl;
	shipBookToAddressA(Book("Europe: A History", "Norman Davies", 1002), "Bv, AFI, birou X");
	std::cout << "--------------------" << std::endl;
	shipBookToAddressB(Book("Catch-22", "Joseph Heller", 1003), "Bv, AFI, birou Y");
	std::cout << "--------------------" << std::endl;

	Book bk2 = myBook;
	shipBookToAddressB(bk2, "Suceava, Spitalul Sf Ion, la intrare");

	std::cout << "--------------------" << std::endl;
	Book* bookPtr1 = new Book("The Psychopath Test ", "Jon Ronson", 1004);
	shipBookToAddressA(*bookPtr1, "Mamaia, la butoaie");
	std::cout << "--------------------" << std::endl;


	Book bk3 = std::move(myBook);
	shipBookToAddressB(bk3, "Suceava, Spitalul Sf Ion, la intrare");

	std::cout << "--------------------" << std::endl;

	Book bk4 = std::move(*bookPtr1);
	// Want to copy and burn an empty book?
	// Just ship the *bookPtr1, which we just emptied.
	//shipBookToAddressB(bk4, "Bucuresti, Cotroceni, intrarea vizitatori");
	shipBookToAddressB(bk4, "Bucuresti, Cotroceni, intrarea vizitatori");
	std::cout << "--------------------" << std::endl;

	std::cout << "Book store closing down... :(" << std::endl;

	// leave no memmory leaks
	delete bookPtr1;
	return 0;
}