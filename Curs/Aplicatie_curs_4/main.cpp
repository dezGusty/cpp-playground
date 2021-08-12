#include "ClassHeader.h"

int main()
{
	// simple way to declare a class and instantiate it's data.
	Student andrei;
	Student mihai("Mihai", 10);
	// andrei.mNota = 10;				// simple call, where these two variables are public
	// andrei.mNumeStudent = "Andrei";

	// extended, private members are set through get/set methods
	andrei.setNota(10);
	andrei.setNume("Andrei");

	andrei.Display();

	// see copy constructor in action;
	andrei = mihai;
	andrei.Display();

	Student catalin = mihai;
	catalin.Display();

	return 0;
}

