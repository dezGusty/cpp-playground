#ifndef GUSLIB_UTIL_PLUGIN_H_
#define GUSLIB_UTIL_PLUGIN_H_

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
#include <vector>

namespace guslib
{
  /**
    The interface for a simple plugin.
  */
  class Plugin
  {
  public:
    /**
      Constructor. Empty.
    */
    Plugin()
    {
    }

    /**
      Destructor. Empty.
    */
    virtual ~Plugin()
    {
    }

    /**
      Get the name of the plugin. 
    */
    virtual const std::string& getName() const = 0;

    /**
      Perform the plugin initial installation sequence.
      This function should be called from the plugin manager after the file is loaded.
    */
    virtual void install() = 0;

    /**
      Perform the post-install initialization sequence.
      This function should be called from the plugin manager immediately after the install.
    */
    virtual void initialize() = 0;

    /**
      Prepare the shutdown of the plugin.
      This function should be called from the plugin manager immediately before the uninstall.
    */
    virtual void shutdown() = 0;

    /**
      Perform the plugin clean-up / uninstall sequence.
    */
    virtual void uninstall() = 0;
  };
}

#endif  // GUSLIB_UTIL_PLUGIN_H_
