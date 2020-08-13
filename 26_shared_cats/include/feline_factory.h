#pragma once

#include <map>
#include <string>

#include "feline.h"

using std::string;
using std::map;

//typedef Feline* (FelineCreateFcPtr)(const string&);

#ifndef FelineCreateFcPtr
#define FelineCreateFcPtr Feline* (*)(const string&, const string &)
#endif 

class FelineFactory
{
public:
  static void initialize();
  static map<string, FelineCreateFcPtr> registered_cats_;
  static void register_cat(const string& felineType, Feline* (*fcName)(const string&, const string &));
  static Feline* create(const string& felineType, const string& felineName, const string &option);
};