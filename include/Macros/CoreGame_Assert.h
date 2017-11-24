//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : CoreGame_Assert.h                                             //
//  Project   : CoreGame                                                      //
//  Date      : May 12, 2016                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2016, 2017                                       //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

//------------------------------------------------------------------------------
// COREGAME_RELEASE - Release mode.
#if defined(COREGAME_RELEASE)
    #define COREGAME_ASSERT(_cond_, _msg_)           do {} while(0)
    #define COREGAME_ASSERT_ARGS(_cond_, _msg_, ...) do {} while(0)

//------------------------------------------------------------------------------
// !COREGAME_RELEASE - Debug mode.
#else // defined(COREGAME_RELEASE) == false

    //--------------------------------------------------------------------------
    ///@brief
    ///    This function is only declared for !COREGAME_RELEASE,
    ///    this is what COREGAME_ASSERT and COREGAME_ASSERT_ARGS
    ///    will call.
    ///@warning DO NOT CALL IT DIRECTLY.
    ///@see COREGAME_ASSERT, COREGAME_ASSERT_ARGS
    void _coregame_assert_print_args(const char   *expr,
                                     const char   *file,
                                     unsigned int line,
                                     const char   *func,
                                     const char   *msg,
                                     ...);

    //--------------------------------------------------------------------------
    ///@brief
    ///     A more informative assert than the standard assert.
    ///@param
    ///     cond - The condition that will be asserted.
    ///@param
    ///     msg - The message the will be printed along the other info.
    ///@see
    ///     COREGAME_ASSERT_ARGS, COREGAME_VERIFY
    #define COREGAME_ASSERT(_cond_, _msg_)               \
                ((_cond_))                               \
                 ? (void) 0                              \
                 : _coregame_assert_print_args(#_cond_,  \
                                               __FILE__, \
                                               __LINE__, \
                                               __func__, \
                                               (_msg_));

    //--------------------------------------------------------------------------
    ///@brief
    ///    A more informative assert than the standard assert.
    ///@param
    ///    cond - The condition that will be asserted.
    ///@param
    ///    msg - The message the will be printed along the other info. \n
    ///          This can be used like a printf(3) format string.
    ///@param
    ///    ... - variadic arguments list that will be used to build the final
    ///          message. \n
    ///          This is used like the printf(3) var args list.
    ///@see
    ///    COREGAME_ASSERT, COREGAME_VERIFY
    #define COREGAME_ASSERT_ARGS(_cond_, _msg_, ...)         \
                ((_cond_))                                   \
                 ? (void) 0                                  \
                 : _coregame_assert_print_args(#_cond_,      \
                                               __FILE__,     \
                                               __LINE__,     \
                                               __func__,     \
                                               (_msg_),      \
                                               ##__VA_ARGS__)


#endif // defined(COREGAME_RELEASE)
