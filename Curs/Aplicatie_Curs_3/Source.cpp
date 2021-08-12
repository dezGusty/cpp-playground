#include "Header.h"

void simplePointer();
// need to define a method before first use
// Error C3861 https://docs.microsoft.com/en-us/cpp/error-messages/compiler-errors-2/compiler-error-c3861?f1url=%3FappId%3DDev15IDEF1%26l%3DEN-US%26k%3Dk(C3861)%26rd%3Dtrue&view=msvc-160
void arrayPointer();

void memoryManagementWithNewDelete();

void memMgmtArray();

void memLeak();

int main()
{
  int index = 0;

  std::cout << "Memory management examples" << std::endl;
  std::cout << "simple pointer method call" << std::endl;
  simplePointer();
  index++;
  std::cout << "array pointer method call" << std::endl;
  arrayPointer();
  index++;
  std::cout << "using new and delete operators" << std::endl;
  memoryManagementWithNewDelete();
  index++;
  std::cout << "using array and new[]/delete[]" << std::endl;
  memMgmtArray();
  index++;

  std::cout << "memory leak exemplified" << std::endl;
  memLeak();

  return 0;
}


void simplePointer()
{
  int myValue = 13;

  int *pMyPointer = nullptr;  // fix uninitialized memory error

  // Can't access uninitialized memory used by pMyPointer!
  // https://docs.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warning-level-1-and-level-4-c4700?f1url=%3FappId%3DDev15IDEF1%26l%3DEN-US%26k%3Dk(C4700)%26rd%3Dtrue&view=msvc-160
  std::cout << "before instantiation: " << pMyPointer << std::endl;

  pMyPointer = &myValue;

  std::cout << "pointer: " << pMyPointer << std::endl;
  std::cout << "value of pointer: " << *pMyPointer << std::endl;
}


void arrayPointer()
{
  int pMyArray[] = {1, 2, 3, 4, 5};
  int *pArray = pMyArray;

  const char *msg = "Hello";
  std::cout << "First element from array: " << *msg << " \n" 
    << "entire array content:" << msg << " \n" 
    << "first element from array, index access: " << msg[0] << "\n" 
    << "reference to array, show entire content following given index: " << &msg[3] << std::endl;
}


void memoryManagementWithNewDelete()
{
  int *pValue = new int;      // define and initialize pointer 
  
  *pValue = 13;               // assign a value to pointer, use *

  std::cout << pValue << " " << &pValue << " " << *pValue << std::endl;

  delete pValue;              // free resources
  pValue = nullptr;
}

void memMgmtArray()
{
  int size = 13;
  int *myArray = new int[size];   // allocate an integer array with given size, 13

  for (int i = 0; i< size; ++i)
  {
    myArray[i] = i;
    std::cout << myArray[i] << " ";
  }

  delete[] myArray;
  myArray = nullptr;
}


void memLeak()
{

  while(1)    // generates an infinite loop, condition remains true indefinetly.
  {
      int size = 999999;
      int *myArray = new int[size];   // allocate an integer array with given size, 13
      
        for (int i = 0; i< size; ++i)
        {
          myArray[i] = i;
        }
      
      delete myArray;   // deletes only first element from array, instead of freeing the entire memory, generates a memory leak!!!
      myArray = nullptr;
  }

}