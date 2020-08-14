#pragma once

#if defined(_MSC_VER)
# ifdef LYNX_DLL
#  define LYNX_IMPEXP __declspec(dllexport)
# else
#  define LYNX_IMPEXP __declspec(dllimport)
# endif //LYNX_DLL
#elif defined(_GCC)
# ifdef LYNX_DLL
#  define LYNX_IMPEXP __attribute__((visibility("default")))
# else
#  define LYNX_IMPEXP 
# endif //LYNX_DLL
#else
#  define LYNX_IMPEXP
#endif
