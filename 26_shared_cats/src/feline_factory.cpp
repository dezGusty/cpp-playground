#include "feline_factory.h"

#include <iostream>

#include "lion.h"
#include "domestic_cat.h"

map<string, Feline* (*)(const string&, const string &)> FelineFactory::registered_cats_;

void FelineFactory::initialize()
{
	FelineFactory::register_cat("lion", Lion::create);
	FelineFactory::register_cat("domestic_cat", DomesticCat::create);
	//FelineFactory::register_cat("lynx", Lynx::create);
}

void FelineFactory::register_cat(const string & felineType, Feline *(*fcName)(const string &, const string &))
{
  if (registered_cats_.find(felineType) != registered_cats_.end())
  {
    std::cout << "Already registered [" << felineType << "]" << std::endl;
    return;
  }

  registered_cats_[felineType] = fcName;
}

Feline * FelineFactory::create(const string & felineType, const string & felineName, const std::string& option)
{
  if (registered_cats_.find(felineType) != registered_cats_.end())
  {
    return registered_cats_[felineType](felineName, option);
  }

  return nullptr;
}


