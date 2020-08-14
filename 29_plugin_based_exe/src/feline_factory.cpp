#include "feline_factory.h"

#include <iostream>

#include "lion.h"
#include "domestic_cat.h"

map<string, FelineCreateFcPtr> FelineFactory::registered_cats_;

void FelineFactory::initialize()
{
}

void FelineFactory::register_cat(const string & felineType, FelineCreateFcPtr fcName)
{
	if (registered_cats_.find(felineType) != registered_cats_.end())
	{
		std::cout << "Already registered [" << felineType << "]" << std::endl;
		return;
	}

	registered_cats_[felineType] = fcName;
}

//void FelineFactory::register_cat(const string & felineType, Feline *(*fcName)(const string &, const string &))
//{
//	if (registered_cats_.find(felineType) != registered_cats_.end())
//	{
//		std::cout << "Already registered [" << felineType << "]" << std::endl;
//		return;
//	}
//
//	registered_cats_[felineType] = fcName;
//}

Feline * FelineFactory::create(const string & felineType, const string & felineName, const std::string& option)
{
  if (registered_cats_.find(felineType) != registered_cats_.end())
  {
    return registered_cats_[felineType](felineName, option);
  }

  return nullptr;
}


