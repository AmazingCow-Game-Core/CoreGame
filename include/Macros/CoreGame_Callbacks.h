//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : CoreGame_Callbacks.h                                          //
//  Project   : CoreGame                                                      //
//  Date      : May 19, 2016                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2016, 2017                                       //
//                                                                            //
//  Description :                                                             //
//    Borrowed from Cocos2d-x v3.10 :D                                        //
//      Amazing Engine you definitely should check it.                        //
//      www.cocos2d-x.org/                                                    //
////////////////////////////////////////////////////////////////////////////////

#pragma once

// std
#include <functional>

//----------------------------------------------------------------------------//
// Callback                                                                   //
//----------------------------------------------------------------------------//
#define COREGAME_CALLBACK_0(__selector__,__target__, ...) \
      std::bind(&__selector__,__target__,                 \
                ##__VA_ARGS__)

//----------------------------------------------------------------------------//
//Callback with 1 arg.                                                        //
//----------------------------------------------------------------------------//
#define COREGAME_CALLBACK_1(__selector__,__target__, ...) \
      std::bind(&__selector__,__target__,                 \
                std::placeholders::_1,                    \
                ##__VA_ARGS__)

//----------------------------------------------------------------------------//
//Callback with 2 args.                                                       //
//----------------------------------------------------------------------------//
#define COREGAME_CALLBACK_2(__selector__,__target__, ...) \
      std::bind(&__selector__,__target__,                 \
                std::placeholders::_1,                    \
                std::placeholders::_2,                    \
                ##__VA_ARGS__)

//----------------------------------------------------------------------------//
//Callback with 3 args.                                                       //
//----------------------------------------------------------------------------//
#define COREGAME_CALLBACK_3(__selector__,__target__, ...) \
      std::bind(&__selector__,__target__,                 \
                std::placeholders::_1,                    \
                std::placeholders::_2,                    \
                std::placeholders::_3,                    \
                ##__VA_ARGS__)
