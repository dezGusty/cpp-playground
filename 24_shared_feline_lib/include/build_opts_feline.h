#pragma once

#if defined(_MSC_VER)
# ifdef FELINE_DLL
#  define FELINES_IMPEXP __declspec(dllexport)
# else
#  define FELINES_IMPEXP __declspec(dllimport)
# endif //FELINE_DLL
#elif defined(_GCC)
# ifdef FELINE_DLL
#  define FELINES_IMPEXP __attribute__((visibility("default")))
# else
#  define FELINES_IMPEXP 
# endif //FELINE_DLL
#else
#  define FELINES_IMPEXP
#endif

// Note: alternatively [[gnu::dllexport]]