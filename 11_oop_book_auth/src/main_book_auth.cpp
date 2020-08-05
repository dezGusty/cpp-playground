#include <iostream>

#include "book.h"
#include "author.h"
#include "alien_author.h"

int main()
{
	{
		Book book1("Ion");

		book1.addAuthor(new Author("Liviu Rebreanu"));
		book1.addAuthor(new Author("Livia Rebreanu"));
		book1.addAuthor(new Author("Ion Ion"));
		book1.addAuthor(new Author("Dan Dan"));
		book1.setReviewer(new Author("LLCoolJ"));
		book1.printToScreenV2();

		Book book2("Biblia, ed. noua");
		book2.printToScreenV2();

		Book bookX("Space travel 101");
		bookX.addAuthor(new AlienAuthor(AlienSkinType::SCALY, "nugthcuj"));
		bookX.setReviewer(new AlienAuthor(AlienSkinType::SCALY, "XK76"));
		bookX.printToScreenV2();


		Book book3 = book1;
		book3.setTitle("Ion, ed. Alien");
		//book3.addAuthor(new AlienAuthor(AlienSkinType::SLIMEY, "kerls"));
		book3.setReviewer(new AlienAuthor(AlienSkinType::SLIMEY, "kek"));
		book3.setReviewer(new AlienAuthor(AlienSkinType::SLIMEY, "kek2"));
		book3.setReviewer(new AlienAuthor(AlienSkinType::SLIMEY, "kek3"));

		book3.printToScreenV2();
		book1.printToScreenV2();
	}

	std::cout << "Shutdown... -----------------" << std::endl;
	std::cout << Author::obj_counter << std::endl;
    return 0;
}