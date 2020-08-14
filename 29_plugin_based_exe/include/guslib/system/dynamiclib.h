#ifndef GUSLIB_SYSTEM_DYNAMICLIB_H_
#define GUSLIB_SYSTEM_DYNAMICLIB_H_

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
//   Dynamic library support class, based on the design of plugins in the OGRE3D library

//
// Includes
//

//
// Platform specific definitions and overall build options for the library.
//
#include <guslib/guslibbuildopts.h>

//
// C system headers.
//

// Include OS specific headers.
#if GUSLIB_PLATFORM_TYPE == GUSLIB_PLATFORM_TYPE_WINDOWS
# include <guslib/system/systemwindowsfwd.h>
#elif GUSLIB_PLATFORM_TYPE == GUSLIB_PLATFORM_TYPE_LINUX
# include <dlfcn.h>
#endif  // GUSLIB_PLATFORM_TYPE

//
// C++ system headers.
//
#include <string>

//
// This library's headers
//
#include "guslib/guslib_platform.h"

// Define some macros for the functions used to load the DLLs on Windows, .so files on Linux, etc.
// This could probably be improved
#if GUSLIB_PLATFORM_TYPE == GUSLIB_PLATFORM_TYPE_WINDOWS
#    define DYNAMICLIB_HANDLE hInstance
#    define DYNAMICLIB_LOAD(a) LoadLibraryEx(a, NULL, 0)
#    define DYNAMICLIB_GETSYM(a, b) GetProcAddress(a, b)
#    define DYNAMICLIB_UNLOAD(a) !FreeLibrary(a)

struct HINSTANCE__;
typedef struct HINSTANCE__* hInstance;

#elif GUSLIB_PLATFORM_TYPE == GUSLIB_PLATFORM_TYPE_LINUX || GUSLIB_PLATFORM_TYPE == GUSLIB_PLATFORM_TYPE_ANDROID || GUSLIB_PLATFORM_TYPE == GUSLIB_PLATFORM_TYPE_NACL || GUSLIB_PLATFORM_TYPE == GUSLIB_PLATFORM_TYPE_FLASHCC
#    define DYNAMICLIB_HANDLE void*
#    define DYNAMICLIB_LOAD(a) dlopen(a, RTLD_LAZY | RTLD_GLOBAL)
#    define DYNAMICLIB_GETSYM(a, b) dlsym(a, b)
#    define DYNAMICLIB_UNLOAD(a) dlclose(a)

#elif GUSLIB_PLATFORM_TYPE == GUSLIB_PLATFORM_TYPE_APPLE || GUSLIB_PLATFORM_TYPE == GUSLIB_PLATFORM_TYPE_APPLE_IOS
#    define DYNAMICLIB_HANDLE void*
#    define DYNAMICLIB_LOAD(a) mac_loadDylib(a)
#    define FRAMEWORK_LOAD(a) mac_loadFramework(a)
#    define DYNAMICLIB_GETSYM(a, b) dlsym(a, b)
#    define DYNAMICLIB_UNLOAD(a) dlclose(a)

#endif

typedef void(*DLL_START_PLUGIN)(void);
typedef void(*DLL_STOP_PLUGIN)(void);

namespace guslib
{
  /**
    A class used to store a dynamically loaded library (E.g. .dll, .so).
    This is designed to be cross-platform and very similar to the OGRE3D model of handling dynamic libraries.
  */
  class GUSLIB_EXPORT_SYMBOL DynamicLib
  {
  private:
    class Impl;
    Impl* impl_;

  protected:
    /// Handle to the loaded library.
    DYNAMICLIB_HANDLE instance_;

  public:
    /**
      Constructor.
    */
    explicit DynamicLib(const std::string& name);

    /**
      Copy constructor. Would you really need this?
      Not sure yet. Could be removed in a future version.
    */
    DynamicLib(const DynamicLib& rhs);

    /**
      Destructor.
    */
    ~DynamicLib();

    /**
      Load the library
    */
    void load();

    /**
      Unload the library
    */
    void unload();

    /**
      Get the name of the library.
    */
    const std::string& getName(void) const;

	DYNAMICLIB_HANDLE getRaw() { return instance_; }

    /**
      Returns the address of the given symbol from the loaded library.
      @param strName The name of the symbol to search for
      @return If the function succeeds, the returned value is a handle to the symbol.
      @par If the function fails, the returned value is <b>NULL</b>.
    */
    void* getSymbol(const std::string& strName) const throw();
  };
}

#endif  // GUSLIB_SYSTEM_DYNAMICLIB_H_
