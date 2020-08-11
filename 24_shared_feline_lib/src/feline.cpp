#include "feline.h"
#include <iostream>
#include "constants.h"

Feline::~Feline()
{
#ifdef CTOR_DTOR_MSG
  std::cout << "Feline (unknwon) destroyed." << std::endl;
#endif //CTOR_DTOR_MSG
}
