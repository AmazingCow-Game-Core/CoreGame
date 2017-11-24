//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : StringUtils.cpp                                               //
//  Project   : CoreGame                                                      //
//  Date      : May 26, 2016                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2016, 2017                                       //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// Header
#include "../include/StringUtils.h"

// Usings
USING_NS_COREGAME;


//----------------------------------------------------------------------------//
// Format                                                                     //
//----------------------------------------------------------------------------//
std::string StringUtils::format(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    //Forward the '...' to vformat
    auto ret = StringUtils::vformat(fmt, args);

    va_end(args);
    return ret;
}

std::string StringUtils::vformat(const char *fmt, std::va_list list)
{
    constexpr int kBufferSize = 1024;
    char buffer[kBufferSize]  = {'\0'};

    // Build the buffer with the variadic args list //
    vsnprintf(buffer, kBufferSize, fmt, list);

    return buffer;
}
