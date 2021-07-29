#pragma once

#include <string>

// declaration specifier
#ifdef ClassLib_EXPORT
	#define ClassLib_API __declspec(dllexport)
#else
	#define ClassLib_API __declspec(dllimport)
#endif


/*
First example, simple class
class Student
{
	public:
		int mNota;
		std::string mNumeStudent;

		bool Display();

};

*/

class ClassLib_API Student
{
	private:						// access specifiers to define the visibility level of different methods and variables
		int mNota;
		std::string mNumeStudent;
	
	public:
		bool setNota(const int& nota);
		bool setNume(std::string nume);
		const int getNota();
		bool Display();

		// same as default constructor;
		Student();
		Student(std::string nume, int nota);
		~Student();

		// copy constructor:
		Student(const Student &source);

		// overloading equal `=` operator
		Student& operator=(const Student &source)
		{
			this->setNota(source.mNota);
			
			this->mNumeStudent.clear();
			this->mNumeStudent = source.mNumeStudent;

			return *this;	// return existing object
		}
};