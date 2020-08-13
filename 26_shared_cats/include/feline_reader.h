#pragma once

#include <string>
#include <vector>

#include "feline.h"

std::vector<Feline*> loadFromIniFile(const std::string& fileName);
Feline* createFelinePointer(const std::string& feline_type, const std::string& name, const std::string& option);

