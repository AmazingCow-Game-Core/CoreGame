//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : CoreGame_OnlyInDebug.h                                        //
//  Project   : CoreGame                                                      //
//  Date      : May 30, 2016                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2016, 2017                                       //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

//------------------------------------------------------------------------------
// Not COREGAME_RELEASE - Debug mode.
#if !defined(COREGAME_RELEASE)
    #define COREGAME_ONLY_IN_DEBUG(_code_) { \
        _code_;                              \
    }

//------------------------------------------------------------------------------
// In COREGAME_RELEASE - Release mode.
#else // !defined(COREGAME_RELEASE) - Release Mode.
    #define COREGAME_ONLY_IN_DEBUG(_code_) {}
#endif // !defined(COREGAME_RELEASE)
