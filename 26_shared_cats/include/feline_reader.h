#pragma once

#include <string>
#include <vector>

#include "feline.h"

std::vector<Feline*> loadFromIniFile(const std::string& fileName);
