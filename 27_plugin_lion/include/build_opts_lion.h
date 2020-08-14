#pragma once

#if defined(_MSC_VER)
# ifdef LION_DLL
#  define LION_IMPEXP __declspec(dllexport)
# else
#  define LION_IMPEXP __declspec(dllimport)
# endif //LION_DLL
#elif defined(_GCC)
# ifdef LION_DLL
#  define LION_IMPEXP __attribute__((visibility("default")))
# else
#  define LION_IMPEXP 
# endif //LION_DLL
#else
#  define LION_IMPEXP
#endif
