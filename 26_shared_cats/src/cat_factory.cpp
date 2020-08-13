#include "cat_factory.h"

#include <iostream>

#include "lion.h"
#include "kitty.h"

map<string, Feline* (*)(const string&)> CatFactory::registered_cats_;

void CatFactory::initialize()
{
	CatFactory::register_cat("lion", Lion::create);
	//CatFactory::register_cat("kitty", Kitty::create);
}

void CatFactory::register_cat(const string & felineType, Feline *(*fcName)(const string &))
{
  if (registered_cats_.find(felineType) != registered_cats_.end())
  {
    std::cout << "Already registered [" << felineType << "]" << std::endl;
    return;
  }

  registered_cats_[felineType] = fcName;
}

Feline * CatFactory::create(const string & felineType, const string & felineName)
{
  if (registered_cats_.find(felineType) != registered_cats_.end())
  {
    return registered_cats_[felineType](felineName);
  }

  return nullptr;
}


