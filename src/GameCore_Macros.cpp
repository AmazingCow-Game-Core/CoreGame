// This source is meant to compiled only in DEBUG builds (!NDEBUG) //
#ifndef NDEBUG

//Header
#include "../include/CoreGame_Macros.h"
//std
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

//Usings
using namespace std;


// Function Definitions //
void _coregame_assert_print_args(const char   *expr,
                                const char   *file,
                                unsigned int line,
                                const char   *func,
                                const char   *msg,
                                ...)
{
    constexpr int kBufferSize = 1024;
    char buffer[kBufferSize]  = {'\0'};

    // Build the buffer with the variadic args list //
    va_list ap;
    va_start(ap, msg);
    vsnprintf(buffer, kBufferSize , msg, ap);
    va_end(ap);

    // Print the message and abort //
    fprintf(stderr,
"GameCore Assert: assertion failed on: \n \
  file       : %s \n \
  line       : %d \n \
  function   : %s \n \
  expression : %s \n \
  message    : %s \n",
        file, line, func, expr, buffer);

    abort();
}

#endif // NDEBUG //
