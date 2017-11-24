//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : StringUtils.h                                                 //
//  Project   : CoreGame                                                      //
//  Date      : May 26, 2016                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2016, 2017                                       //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// std
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdarg>
// CoreGame
#include "CoreGame_Utils.h"

NS_COREGAME_BEGIN
namespace StringUtils {

//----------------------------------------------------------------------------//
// To String                                                                  //
//----------------------------------------------------------------------------//
template <typename T>
std::string to_string(const T &val)
{
    std::stringstream ss;
    ss << val;
    return ss.str();
}

//----------------------------------------------------------------------------//
// Format                                                                     //
//----------------------------------------------------------------------------//
std::string format(const char *fmt, ...);
std::string vformat(const char *fmt, std::va_list list);

} //namespace StringUtils

NS_COREGAME_END
