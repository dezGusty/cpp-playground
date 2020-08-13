#pragma once

#include <map>
#include <string>

#include "feline.h"

using std::string;
using std::map;

//typedef Feline* (FelineCreateFc)(const string&);
#ifndef FelineCreateFc
#define FelineCreateFc Feline* (*)(const string&)
#endif 

class CatFactory
{
public:
  static void initialize();
  static map<string, Feline* (*)(const string&)> registered_cats_;
  static void register_cat(const string& felineType, Feline* (*fcName)(const string&));
  static Feline* create(const string& felineType, const string& felineName);
};