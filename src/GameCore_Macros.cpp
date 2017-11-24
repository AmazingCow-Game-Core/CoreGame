//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : GameCore_Macros.cpp                                           //
//  Project   : CoreGame                                                      //
//  Date      : May 03, 2016                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2016, 2017                                       //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// This source is meant to compiled only in DEBUG builds (!COREGAME_RELEASE) //
#ifndef COREGAME_RELEASE

// Header
#include "../include/CoreGame_Macros.h"
// std
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
// CoreGame
#include "../include/StringUtils.h"

// Usings
USING_NS_COREGAME;

//----------------------------------------------------------------------------//
// Function Definitions                                                       //
//----------------------------------------------------------------------------//
void _coregame_assert_print_args(const char   *expr,
                                 const char   *file,
                                 unsigned int line,
                                 const char   *func,
                                 const char   *msg,
                                 ...)
{
    va_list args;
    va_start(args, msg);

    //Forward the '...' to vformat
    auto buffer = StringUtils::vformat(msg, args);

    va_end(args);

    // Print the message and abort //
    fprintf(stderr,
"GameCore Assert: assertion failed on: \n \
  file       : %s \n \
  line       : %d \n \
  function   : %s \n \
  expression : %s \n \
  message    : %s \n",
        file, line, func, expr, buffer.c_str());

    abort();
}

#endif // COREGAME_RELEASE //
