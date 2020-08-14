#ifndef GUSLIB_SYSTEM_DYNAMICLIBMANAGER_H_
#define GUSLIB_SYSTEM_DYNAMICLIBMANAGER_H_

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
// C++ system headers
//
#include <string>
#include <map>

//
// This library's headers
//
#include "guslib/common/singleton.hpp"
#include "guslib/system/dynamiclib.h"

namespace guslib
{
  /**
    Utility class to function as a single entry point for handling dynamically loaded libraries.
    Follows the design present in the OGRE3D library.
  */
  class GUSLIB_EXPORT_SYMBOL DynamicLibManagerUtil
  {
  private:
    class Impl;
    Impl* impl_;

  protected:
    typedef std::map<std::string, DynamicLib*> DynamicLibList;

  public:
    /**
      Constructor.
    */
    DynamicLibManagerUtil();

    /**
      Copy constructor is disabled.
    */
    DynamicLibManagerUtil(const DynamicLibManagerUtil&) = delete;

    /**
      Destructor.
    */
    virtual ~DynamicLibManagerUtil();

    /**
      Load a library.
    */
    DynamicLib* load(const std::string& filename);

    /**
      Unload a library.
    */
    void unload(DynamicLib* lib);
  };

  // Re-type the utility class into something with a nicer name.
  typedef guslib::Singleton<DynamicLibManagerUtil> DynamicLibManager;
}

#endif
