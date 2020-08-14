#pragma once

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
//   This header will change between different releases of guslib. Including the header will result in a recompile
//   when a new guslib version is released.

//
// This file provides definitions used in determining the platform on which the CET VCS shall run.
//

//
// Define the possible platform types
//

#define GUSLIB_PLATFORM_TYPE_WINDOWS 1
#define GUSLIB_PLATFORM_TYPE_LINUX 2
#define GUSLIB_PLATFORM_TYPE_APPLE 3
#define GUSLIB_PLATFORM_TYPE_APPLE_IOS 4
#define GUSLIB_PLATFORM_TYPE_ANDROID 5

//
// Define the possible platforms sub-types.
//

#define GUSLIB_PLATFORM_WIN32 1
#define GUSLIB_PLATFORM_WIN64 2
#define GUSLIB_PLATFORM_WINRT 3

//
// Define the active platform, based on the preprocessor settings
//

#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32)
#  define GUSLIB_PLATFORM_TYPE GUSLIB_PLATFORM_TYPE_WINDOWS
#  define GUSLIB_PLATFORM GUSLIB_PLATFORM_WIN32
#elif defined(__WIN64__) || defined(_WIN64) || defined(WIN64) || defined(x64)
#  define GUSLIB_PLATFORM_TYPE GUSLIB_PLATFORM_TYPE_WINDOWS
#  define GUSLIB_PLATFORM GUSLIB_PLATFORM_WIN64
#elif defined(__linux__) || defined(__linux)
#  define GUSLIB_PLATFORM_TYPE GUSLIB_PLATFORM_TYPE_LINUX
#endif
