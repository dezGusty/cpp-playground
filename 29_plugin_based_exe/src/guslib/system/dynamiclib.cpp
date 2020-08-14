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

// Own header
#include "guslib/system/dynamiclib.h"

//
// C++ system headers
//
#include <string>

//
// This libraries' headers
//
#include "guslib/util/stringutil.h"

#include "guslib/common/simpleexception.h"

namespace guslib
{
  //
  // ----------------------------- Dynamic Lib item internals ---------------------------------
  //

  class DynamicLib::Impl
  {
  public:
    std::string name_;

    Impl(const std::string& name)
      : name_(name)
    {
    }
  };

  //
  // ----------------------------- Dynamic Lib implementation ---------------------------------
  //

  DynamicLib::DynamicLib(const std::string& name)
    : impl_(new DynamicLib::Impl(name))
  {
    instance_ = NULL;
  }

  DynamicLib::DynamicLib(const DynamicLib& rhs)
    : impl_(new DynamicLib::Impl(*rhs.impl_))
  {
    instance_ = NULL;
  }

  DynamicLib::~DynamicLib()
  {
    delete impl_;
  }

  const std::string& DynamicLib::getName(void) const
  {
    return impl_->name_;
  }

  //-----------------------------------------------------------------------
  void DynamicLib::load()
  {
    // Log library load

    std::string name = impl_->name_;
#if GUSLIB_PLATFORM_TYPE == GUSLIB_PLATFORM_TYPE_LINUX
    // dlopen() does not add .so to the filename, like windows does for .dll
    if (name.find(".so") == std::string::npos)
    {
      name += ".so.";
    }
#elif GUSLIB_PLATFORM_TYPE == GUSLIB_PLATFORM_TYPE_APPLE
    // dlopen() does not add .dylib to the filename, like windows does for .dll
    if (name.substr(name.find_last_of(".") + 1) != "dylib")
      name += ".dylib";
#elif GUSLIB_PLATFORM_TYPE == GUSLIB_PLATFORM_TYPE_WINDOWS
    // Although LoadLibraryEx will add .dll itself when you only specify the library name,
    // if you include a relative path then it does not. So, add it to be sure.
    if (name.substr(name.find_last_of(".") + 1) != "dll")
    {
      name += ".dll";
    }
#endif

#if GUSLIB_PLATFORM_TYPE == GUSLIB_PLATFORM_TYPE_WINDOWS
	std::wstring lib_name_w(guslib::stringutil::StringToWString(name));
	LPCWSTR lib_name = lib_name_w.c_str();
	//instance_ = (DYNAMICLIB_HANDLE)DYNAMICLIB_LOAD(guslib::stringutil::StringToWString(name).c_str());
	instance_ = (DYNAMICLIB_HANDLE)DYNAMICLIB_LOAD(lib_name);
#else
    instance_ = (DYNAMICLIB_HANDLE)DYNAMICLIB_LOAD(name.c_str());
#endif

#if GUSLIB_PLATFORM_TYPE == GUSLIB_PLATFORM_TYPE_APPLE
    if (!instance_)
    {
      // Try again as a framework
      instance_ = (DYNAMICLIB_HANDLE)FRAMEWORK_LOAD(impl_->name_);
    }
#endif

    if (!instance_)
    {
      throw SimpleException("Could not load a library");
    }
  }

  //-----------------------------------------------------------------------
  void DynamicLib::unload()
  {
    // Log library unload
    if (DYNAMICLIB_UNLOAD(instance_))
    {
      throw SimpleException("Could not unload a library");
    }
  }

  //-----------------------------------------------------------------------
  void* DynamicLib::getSymbol(const std::string& strName) const throw()
  {
    return (void*)DYNAMICLIB_GETSYM(instance_, strName.c_str());
  }
}