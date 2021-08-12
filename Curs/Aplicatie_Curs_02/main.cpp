#include "HeaderCurs2.h"

using namespace std;

// define method protoype
// void call_if();

int main()
{

 // call_if();

  //call_cascaded_if(5);
  //call_cascaded_if(20);
  //call_cascaded_if(10);

  //Color myColor = Color::yellow;    // define a local variable of type `Color` with value yellow
  //call_switch(myColor);

  //call_while(5);

  int result = -1;

  //if(call_for(10, result))
  //  std::cout << "for loop result: " << result;
  //else
  //  std::cout << "error runing for loop";

  // call_for_updated(20, result);
  // std::cout << "updated for loop result: " << result;

  //call_arrays();

  Books myBook = { 5, "De veghe in lanul de secara", "autor" };
  Books myOtherBook;
  myOtherBook.book_id = 2;
  
  // TODO Fix syntax error, unable to assign character array to char[]
  //char title[50] = "Ion Creanga"
  //myOtherBook.author = title;
  //myOtherBook.title = "Capra cu trei iezi";


  call_struct(myBook);

  return 0;
}

