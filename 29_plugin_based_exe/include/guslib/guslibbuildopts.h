#ifndef GUSLIB_GUSLIBBUILDOPTS_H
#define GUSLIB_GUSLIBBUILDOPTS_H

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
//   Build options.
//
//   IMPORTANT: This file is auto-generated from guslibbuildopts.h.in
//


//
// Includes
//

//
// This project's headers
//

// Add platform specific definitions.
#include "guslib/guslib_platform.h"
// Version info
#include "guslib/guslib_version.hpp"

//
// Macro definitions for import / export.
//
// Note: this would normally be stored in a separate library (Eg. guslib), 
// but this version is modified for simplicity to reside in an executable.
#define GUSLIB_EXPORT_SYMBOL
#define GUSLIB_EXPIMP_TEMPLATE 

/*
#if defined(_MSC_VER)
# ifdef GUSLIB_EXP
#  define GUSLIB_EXPORT_SYMBOL __declspec (dllexport)
#  define GUSLIB_EXPIMP_TEMPLATE
# else
#  define GUSLIB_EXPORT_SYMBOL __declspec (dllimport)
#  define GUSLIB_EXPIMP_TEMPLATE extern
# endif  //  GUSLIB_EXP
#elif defined(_GCC)
# ifdef GUSLIB_EXP
#  define GUSLIB_EXPORT_SYMBOL __attribute__((visibility("default")))
#  define GUSLIB_EXPIMP_TEMPLATE
# else
#  define GUSLIB_EXPORT_SYMBOL 
#  define GUSLIB_EXPIMP_TEMPLATE extern
# endif  //  GUSLIB_EXP
#else
#  define GUSLIB_EXPORT_SYMBOL 
#  define GUSLIB_EXPIMP_TEMPLATE 
#endif
*/

/**
  Define the multithread support.

  GUSLIB_THREAD_SUPPORT = 0
    No support for threading.
  GUSLIB_THREAD_SUPPORT = 1
    Support for threading.
*/

#ifndef GUSLIB_THREAD_SUPPORT
#define GUSLIB_THREAD_SUPPORT 0
#endif

// Some options you may set for the project:
// GUSLIB_FLAG_SINGLETONINST: specify whether the singleton can declare and set to NULL the instances of the defined classes.

#ifndef GUSLIB_FLAG_SINGLETONINST
#define GUSLIB_FLAG_SINGLETONINST 1
#endif

// Other flags:
//
// GUSLIB_USE_BOOST_RANDOM

#ifndef GUSLIB_USE_BOOST_RANDOM
#define GUSLIB_USE_BOOST_RANDOM 0
#endif


#endif  // GUSLIB_GUSLIBBUILDOPTS_H
