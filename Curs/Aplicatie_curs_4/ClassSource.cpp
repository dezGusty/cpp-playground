
#include "ClassHeader.h"
#include <iostream>

// #include <stdio.h> // optional for input output operations

// in general, constructors and destructors are listed first, then follows other class methods implementation
// constructor is called when an object is instantiated;
Student::Student()
{
	mNota = 0;
	mNumeStudent.clear();
	mNumeStudent = "";
}

// destructor is called when object get's out of scope and can be cleared from memory.
Student::~Student()
{
	this->mNota = -1;
	this->mNumeStudent.clear();
}

// custom constructor, with parameters:
Student::Student(std::string nume, int nota) : mNota(nota), mNumeStudent(nume)			// using initializer list, ususally faster
{
	// usual initialization;
	mNota = nota;
	mNumeStudent = nume;
	
	// this call is also valid:
	this->setNota(nota);
}


// place to implement operator overload or different type of methods

// copy constructor
Student::Student(const Student &source)		// reference is used, because source is an object of type student, and we only need to know the address (see pointers) where it's hold in memory
{
	if(!this->setNota( source.mNota ) )
		this->setNota(0);
	this->mNumeStudent = source.mNumeStudent;
}



// implement general methods from the class

bool Student::Display()
{
	std::cout << "Student: " << mNumeStudent << " nota " << this->mNota << std::endl;

	return true;
}

bool Student::setNota(const int& nota)
{
	if (nota > 0 && nota <= 10)
	{
		this->mNota = nota;			// using `this` pointer to explicitly set internal variable value
		return true;
	}
	return false;
}

const int Student::getNota()
{
	return mNota;
}

bool Student::setNume(std::string nume)
{
	mNumeStudent = nume;
	return true;
}
