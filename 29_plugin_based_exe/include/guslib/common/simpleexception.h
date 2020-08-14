#ifndef GUSLIB_COMMON_SIMPLEEXCEPTION_H
#define GUSLIB_COMMON_SIMPLEEXCEPTION_H

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
// Platform specific definitions and overall build options for the library.
//
#include <guslib/guslibbuildopts.h>

//
// C++ system includes
//
#include <exception>


namespace guslib
{
  ///
  /// An exception class.
  ///
  class GUSLIB_EXPORT_SYMBOL SimpleException
    : public std::exception
  {
  private:

  public:
    /**
      Constructor. Must pass a message to use.
    */
    explicit SimpleException(const char* text);

    /**
      Copy constructor.
    */
    SimpleException(const SimpleException& rhs);

    /**
      Destructor. Not designed to do anything special. Guarantees a no-throw.
    */
    virtual ~SimpleException() throw();

    /**
      Adapt the exception to a string. Guarantees a no-throw.
    */
    const char* what() const throw();

  private:
    // Internal class to store the implementation.
    class Impl;

    // Pointer to implementation (pImpl).
    Impl* impl_;
  };
}

#endif  // GUSLIB_COMMON_SIMPLEEXCEPTION_H
