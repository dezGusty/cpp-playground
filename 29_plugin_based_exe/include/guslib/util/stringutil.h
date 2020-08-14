#ifndef GUS_LIB_STRINGUTIL_H
#define GUS_LIB_STRINGUTIL_H

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
//   String utility
//

//
// Includes
//

//
// Platform specific definitions and overall build options for the library.
//
#include <guslib/guslibbuildopts.h>

//
// C++ system headers.
//

// Using std::string
#include <string>

// Allow the use of std::vector for splitting.
#include <vector>

namespace guslib
{
  enum class LetterCase
  {
    SentenceCase,  // Sentencecase
    LowerCase,    // lowercase
    UpperCase,    // ALL_CAPS
    CamelCase,    // camelCase
    UpperCamelCase,  // CamelCase
    NumLetterCases
  };

  namespace stringutil
  {
    /**
      Split a string into several other strings. A single char separator needs to be provided.
      @param source The source string.
      @param delimiter
      @return A vector containing the separated strings.
      If the source is an empty string, the result shall be an empty vector.
      If the source contains no separator item, the result is a vector with a single item.
      If the source contains only a separator item, the result is a vector with 2 empty entries.
      Example:
      @code
      std::string myList ("string1|string2|string3");
      std::vector <std::string> result = guslib::stringutil::SplitByChar (myList, '|');
      @endcode
    */
    GUSLIB_EXPORT_SYMBOL std::vector <std::string> SplitByChar(const std::string& source, const char delimiter);

    // Prototype for conversion functions
    GUSLIB_EXPORT_SYMBOL std::wstring StringToWString(const std::string& s);
    GUSLIB_EXPORT_SYMBOL std::string WStringToString(const std::wstring& s);

    GUSLIB_EXPORT_SYMBOL bool StringToBool(const std::string& s);
    GUSLIB_EXPORT_SYMBOL std::string BoolToString(bool value, LetterCase format = LetterCase::SentenceCase);

    GUSLIB_EXPORT_SYMBOL int StringToInt(const std::string & s);
    GUSLIB_EXPORT_SYMBOL std::string IntToString(int value);

    /**
      Transforms an integer to a hex representation, as a string.
    */
    GUSLIB_EXPORT_SYMBOL std::string UnsignedToHexString(unsigned long number);

    GUSLIB_EXPORT_SYMBOL long long StringToLongLong(const std::string & s);
    GUSLIB_EXPORT_SYMBOL std::string LongLongToString(long long value);

    GUSLIB_EXPORT_SYMBOL unsigned long long StringToUnsignedLongLong(const std::string & s);
    GUSLIB_EXPORT_SYMBOL std::string UnsignedLongLongToString(unsigned long long value);

    GUSLIB_EXPORT_SYMBOL double StringToDouble(const std::string & s);
    GUSLIB_EXPORT_SYMBOL std::string DoubleToString(double value);

    GUSLIB_EXPORT_SYMBOL std::string GetExtensionFromFileName(const std::string &fileName);

    GUSLIB_EXPORT_SYMBOL std::string RemoveOuterQuotes(
      const std::string& source_content,
      bool only_remove_if_both_present = true);

    GUSLIB_EXPORT_SYMBOL std::string TrimString(const std::string& content);
  }
}

#endif  // GUS_LIB_STRINGUTIL_H
