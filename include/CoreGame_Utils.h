//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : CoreGame_Utils.h                                              //
//  Project   : CoreGame                                                      //
//  Date      : May 03, 2016                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2016, 2017                                       //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

//------------------------------------------------------------------------------
// All classes of this core is placed inside this namespace.
//   We use MACROS so is easier to change if needed.
//   Is (in our opinion) more explicit.
//   And finally the editors will not reformat the code.
#define NS_COREGAME_BEGIN namespace CoreGame {
#define NS_COREGAME_END   }
#define USING_NS_COREGAME using namespace CoreGame

//------------------------------------------------------------------------------
// The core version number.
#define COW_COREGAME_VERSION_MAJOR    "0"
#define COW_COREGAME_VERSION_MINOR    "0"
#define COW_COREGAME_VERSION_REVISION "13"

#define COW_COREGAME_VERSION       \
    COW_COREGAME_VERSION_MAJOR "." \
    COW_COREGAME_VERSION_MINOR "." \
    COW_COREGAME_VERSION_REVISION
