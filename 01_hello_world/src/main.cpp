
#include <iostream>

int printMessageFor(const char* name)
{
	std::cout << "Hello from [" << name << "]" << std::endl;
}

void printMessage()
{
	printMessageFor("YOUR_NAME_HERE");
}

void main() {
  
  printMessage();
}
