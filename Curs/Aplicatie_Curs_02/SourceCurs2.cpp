#include "HeaderCurs2.h"

using namespace std;

// Flow control if command
void call_if()
{
  int a = 10;   // local variable, to this method

  if (a == 10)
    cout << "a = " << a << endl;
  else
    cout << "a is not 10";
}

void call_cascaded_if(int param)    // check the input value to some predefined values in code.
{
    //if(param == 10)    cout << "Value is 10";     // not recommended as a style, can cause serious issues
    //if(param == 10)    cout << "Value is 10";
    //if(param == 10)    cout << "Value is 10";
    //if(param == 10)    cout << "Value is 10";

  if(param == 10)
  {
    cout << "Value is 10" << endl;
  }
  else if (param == 20)
  {
    cout << "Value is 20" << endl;
  }
  else
  {
    cout << "Other value: " << param;
    cout << "integer value" << endl;
  }
  // ..

}


void call_switch(Color param)
{
    // need to define an enum
  switch(param)
  {
  default: 
    cout << "not a verified color from this switch" << std::endl;
  case red: 
    cout << "red " << red << endl;
    break;
  case yellow: 
    cout << "yellow " << yellow << endl;
    break;
  case blue: 
    cout << "blue " << blue << endl;
    break;
  }
    
}

void call_while(int param)
{
  int index = 0;
  std::cout << "While command: " << endl;
  while (index <= param)
  {
    std::cout << index << " ";
    index++;      // post increment, involves a copy of the variable
  }
  std::cout << endl;
  
  std::cout << "Do while command: " << endl;
  index = 0;
  do
  {
      std::cout << index << " ";
      ++index;    // pre increment, faster

  } while (index <= param);
}

bool call_for(const int input, int& out_sum)
{
  out_sum = 0;
  
  // input = 5;    // can't change const variables

  std::cout << "For loop: " << std::endl;
  for(int i = 0; i <= input; ++i )
  {
    std::cout << i << " ";
    out_sum += i;
  }

  return true;    // we could change the method type to int and directly return the `sum` value
}

bool call_for_updated(const int input, int& out_sum)
{
  out_sum = 0;

  std::cout << "For loop: " << std::endl;
  for(int i = 0; i <= input; ++i )
  {
    if( i % 2)
      out_sum += i;
    else 
      continue;
    std::cout << i << " ";
  }

  return true;
}


bool call_arrays()
{
  char myString[10] = {'h', 'e', 'l', 'l', 'o'};   // fixed size
  char myStringTwo[] = {'h', 'e', 'l', 'l', 'o', '\0'};  // undefined size, resized to fit to initializer list
  char myStringThird[] = "hello world"; 

  cout << myString << "  " << myStringTwo << myStringThird;

  //  strcat_s strlen strcpy // to use with these three arrays

  return true;
}

bool call_struct(Books input)
{
  cout << "Index:  " << input.book_id << endl;
  cout << "Author: " << input.author << endl;
  cout << "Title:  " << input.title << endl;

  return true;
}