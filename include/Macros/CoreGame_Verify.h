//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : CoreGame_Verify.h                                             //
//  Project   : CoreGame                                                      //
//  Date      : Jun 22, 2016                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2016, 2017                                       //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// CoreGame
#include "CoreGame_Assert.h"

//----------------------------------------------------------------------------//
// NOTES:                                                                     //
//  COW_VERIFY macro was heavily insipred on the amazing course by            //
//  Kenny Kerr - @kennykerr - PluralSight Modern C++ Libraries.               //
//----------------------------------------------------------------------------//

//------------------------------------------------------------------------------
// COREGAME_RELEASE - Release mode.
#if defined(COREGAME_RELEASE)
    #define COREGAME_VERIFY(_expr_) ((_expr_))

//------------------------------------------------------------------------------
// !COREGAME_RELEASE - Debug mode.
#else
    //--------------------------------------------------------------------------
    ///@brief
    ///    Assert like macro that will behave like the assert in
    ///    non COREGAME_RELEASE builds, but unlike the assert it
    ///    WILL continue doing the check in COREGAME_RELEASE builds. \n
    ///    This is util in cases that we want an assert in debug, but
    ///    want that the expression being kept in the release builds.
    ///@param expr
    ///     The expression that will evaluated and will trigger the
    ///     assert if false in debug build. \n
    ///     Notice that it will be kept regardless if the build mode,
    ///     but will only trigger the assert in non COREGAME_RELEASE builds.
    #define COREGAME_VERIFY(_expr_)                    \
        COREGAME_ASSERT_ARGS(                          \
            (_expr_),                                  \
            "COREGAME_VERIFY Failed - expression(%s)", \
            #_expr_                                    \
        )
#endif // defined(COREGAME_RELEASE)
