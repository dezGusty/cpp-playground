//   This file is part of the guslib library, licensed under the terms of the MIT License.
//
//   The MIT License
//   Copyright (C) 2010-2016  Augustin Preda (thegusty999@gmail.com)
//
//   Permission is hereby granted, free of charge, to any person obtaining a copy
//   of this software and associated documentation files (the "Software"), to deal
//   in the Software without restriction, including without limitation the rights
//   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//   copies of the Software, and to permit persons to whom the Software is
//   furnished to do so, subject to the following conditions:
//
//   The above copyright notice and this permission notice shall be included in
//   all copies or substantial portions of the Software.
//
//   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//   THE SOFTWARE.

//
// Includes
//

//
// Own header.
//
#include "guslib/util/stringutil.h"

//
// C++ system headers
//

#include <algorithm>  // for copy
#include <sstream>
#include <string>
#include <vector>

namespace guslib
{
  namespace stringutil
  {
    /**
      Split a string into several other strings. A single char separator needs to be provided.
      @param source The source string. 
      @param delimiter
      @return A vector containing the separated strings. If the source is an empty string, the result shall be an empty vector.
      If the source contains no separator item, the result is a vector with a single item.
      If the source contains only a separator item, the result is a vector with 2 empty entries.
      Example:
      @code
      std::string myList ("string1|string2|string3");
      std::vector <std::string> result = guslib::stringutil::SplitByChar (myList, '|');
      @endcode
    */
    std::vector <std::string> SplitByChar(const std::string& source, const char delimiter)
    {
      std::vector <std::string> result;
      std::stringstream splitter{ source };
      std::string tempItem{ "" };

      // split the items and add them to the vector.
      while (std::getline(splitter, tempItem, delimiter))
      {
        result.push_back(tempItem);
      }

      // If we have an empty string, just return the existing content.
      if (source.length() <= 0)
      {
        return result;
      }

      // If the last char is the separator... add an empty entry.
      // An elegant way: dereference the reverse iterator. C++11 has support for back().

      const char lastChar = *source.rbegin();
      if (lastChar == delimiter)
      {
        result.push_back("");
      }

      return result;
    }

    std::wstring StringToWString(const std::string& s)
    {
      std::wstring temp(s.length(), L' ');
      std::copy(s.begin(), s.end(), temp.begin());
      return temp;
    }

    std::string WStringToString(const std::wstring& ws)
    {
      if (ws.length () == 0)
      {
        return std::string ();
      }

#if GUSLIB_PLATFORM_TYPE==GUSLIB_PLATFORM_TYPE_WINDOWS
      size_t bufferSize;

      // first call to wcstombs_s to get the target buffer size
      wcstombs_s(&bufferSize, NULL, 0, ws.c_str(), ws.size());

      char * buffer = new char[bufferSize];
      wcstombs_s(&bufferSize, buffer, bufferSize, ws.c_str(), _TRUNCATE);

      std::string temp(buffer);
      delete[] buffer;
      return temp;
#elif GUSLIB_PLATFORM_TYPE==GUSLIB_PLATFORM_TYPE_LINUX
      const std::string result(ws.begin(), ws.end());
      return result;
#endif
    }

    bool StringToBool(const std::string& s)
    {
      if (s.length() <= 0)
      {
        return false;
      }

      if (s[0] == 'T' || s[0] == 't' || s[0] == 'y' || s[0] == 'Y' || s[0] == '1')
      {
        return true;
      }

      return false;
    }


    std::string BoolToString(bool value, LetterCase format)
    {
      if (value)
      {
        switch (format)
        {
        case LetterCase::LowerCase:
          return "true";
        case LetterCase::UpperCase:
          return "TRUE";
        case LetterCase::SentenceCase:
        default:
          return "True";
        }
      }

      switch (format)
      {
      case LetterCase::LowerCase:
        return "false";
      case LetterCase::UpperCase:
        return "FALSE";
      default:
        break;
      }  // fall through

      return "False";
    }


    int StringToInt(const std::string & s)
    {
      int ret;
      std::istringstream(s) >> ret;
      return ret;
    }

    std::string IntToString(int value)
    {
      std::stringstream ss;
      ss << value;
      return ss.str();
    }

    long long StringToLongLong(const std::string & s)
    {
      long long ret;
      std::istringstream(s) >> ret;
      return ret;
    }

    std::string LongLongToString(long long value)
    {
      std::stringstream ss;
      ss << value;
      return ss.str();
    }

    unsigned long long StringToUnsignedLongLong(const std::string & s)
    {
      unsigned long long ret;
      std::istringstream(s) >> ret;
      return ret;
    }

    std::string UnsignedLongLongToString(unsigned long long value)
    {
      std::stringstream ss;
      ss << value;
      return ss.str();
    }

    double StringToDouble(const std::string & s)
    {
      double ret;
      std::istringstream(s) >> ret;
      return ret;
    }

    std::string DoubleToString(double value)
    {
      std::stringstream ss;
      ss << value;
      return ss.str();
    }

    std::string UnsignedToHexString(unsigned long number)
    {
      std::stringstream ss;
      ss << std::hex << number << std::dec;
      return ss.str();
    }

    std::string GetExtensionFromFileName(const std::string &fileName)
    {
      std::string result;
      size_t foundPos = fileName.find_last_of(".");
      if (foundPos != std::string::npos)
      {
        // Name is result.substr(0, foundPos);
        // Extension is...
        result = fileName.substr(foundPos + 1);
      }

      return result;
    }
    
    
    std::string RemoveOuterQuotes(const std::string& source_content, bool only_remove_if_both_present)
    {
      if (source_content.length() < 2)
      {
        return source_content;
      }

      // Get the first char and the last char by dereferencing the iterator.
      const char first_char = *source_content.begin();
      const char last_char = *source_content.rbegin();

      if (only_remove_if_both_present)
      {
        if (first_char != last_char
          || first_char != '\"')
        {
          return source_content;
        }
      }

      int start_pos = 0;
      size_t used_len = source_content.length();

      if (first_char == '\"')
      {
        start_pos++;
        used_len--;
      }

      if (last_char == '\"')
      {
        used_len--;
      }

      return source_content.substr(start_pos, used_len);
    }

    std::string TrimString(const std::string& content)
    {
      std::string local_copy{ content };
      size_t position = local_copy.find_last_not_of(" \t");
      if (std::string::npos != position)
      {
          local_copy = local_copy.substr(0, position + 1);
      }

      position = local_copy.find_first_not_of(" \t");
      if (std::string::npos != position)
      {
          local_copy = local_copy.substr(position);
      }

      return local_copy;
    }
  }
}
