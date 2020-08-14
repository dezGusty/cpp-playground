#ifndef GUSLIB_UTIL_PLUGINMANAGER_H_
#define GUSLIB_UTIL_PLUGINMANAGER_H_

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
//   A simple plugin class.

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

#include <map>
#include <string>

//
// This library's headers.
//
#include "guslib/common/singleton.hpp"
#include "guslib/util/plugin.h"

namespace guslib
{
  /**
    Utility class to function as a single entry point for handling plugins.
    Follows the design present in the OGRE3D library.
  */
  class GUSLIB_EXPORT_SYMBOL PluginManagerUtil
  {
  private:
    class Impl;
    Impl* impl_;

  public:
    /**
      Constructor.
    */
    PluginManagerUtil();

    /**
      Copy constructor is disabled.
    */
    PluginManagerUtil(const PluginManagerUtil&) = delete;

    /**
      Destructor.
    */
    virtual ~PluginManagerUtil();

    /**
      Install a plugin. 
      Load it and perform post-load steps.
    */
    void install(Plugin* pluginPtr);

    /**
      Unload the plugin. Perform any steps required to cleanly release resources inside the plugin
      prior to the actual unload.
    */
    void uninstall(Plugin* pluginPtr);

    /**
      Manually load a plugin found in a DLL/DSO.
      The specified DLL is expected to implement a "dllStartPlugin"
      function which instantiates a Plugin subclass and calls PluginManagerUtil::install.
      It should also implement dllStopPlugin (see Root::unloadPlugin)
    */
    void loadPluginByName(const std::string& pluginName);

    /**
      Manually unload a Plugin found in a DLL / DSO.
      This method will call the "dllStopPlugin" function defined in the DLL, which in turn should call
      PluginManagerUtil::uninstall.
    */
    void unloadPluginByName(const std::string& pluginName);
  };

  // Re-type the utility class into something with a nicer name.
  typedef guslib::Singleton<PluginManagerUtil> PluginManager;
}

#endif  // GUSLIB_UTIL_PLUGINMANAGER_H_
