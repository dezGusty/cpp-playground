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
#include "guslib/system/dynamiclibmanager.h"

namespace guslib
{
  //
  // ----------------------------- Dynamic Lib manager internals ---------------------------------
  //

  class DynamicLibManagerUtil::Impl
  {
  public:
    DynamicLibList libList_;

    Impl()
    {
    }
  };

  //
  // ----------------------------- Dynamic Lib Manager ---------------------------------
  //

  DynamicLibManagerUtil::DynamicLibManagerUtil()
    : impl_(new DynamicLibManagerUtil::Impl())
  {
  }

  DynamicLibManagerUtil::~DynamicLibManagerUtil()
  {
    // Unload & delete resources in turn
    for (DynamicLibList::iterator it = impl_->libList_.begin(); it != impl_->libList_.end(); ++it)
    {
      it->second->unload();
      delete it->second;
    }

    // Empty the list
    impl_->libList_.clear();

    delete impl_;
  }

  DynamicLib* DynamicLibManagerUtil::load(const std::string& filename)
  {
    DynamicLibList::iterator i = impl_->libList_.find(filename);
    if (i != impl_->libList_.end())
    {
      return i->second;
    }
    else
    {
      DynamicLib* ptrToLib = new DynamicLib(filename);
      ptrToLib->load();
      impl_->libList_[filename] = ptrToLib;
      return ptrToLib;
    }
  }
  //-----------------------------------------------------------------------
  void DynamicLibManagerUtil::unload(DynamicLib* lib)
  {
    DynamicLibList::iterator i = impl_->libList_.find(lib->getName());
    if (i != impl_->libList_.end())
    {
      impl_->libList_.erase(i);
    }

    lib->unload();
    delete lib;
  }
}