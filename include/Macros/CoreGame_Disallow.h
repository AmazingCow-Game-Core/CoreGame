//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : CoreGame_Disallow.h                                           //
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

//----------------------------------------------------------------------------//
// CTOR                                                                       //
//----------------------------------------------------------------------------//
#define COREGAME_DISALLOW_CTOR(_type_) \
      _type_() = delete;


//----------------------------------------------------------------------------//
// COPY / COPY ASSING                                                         //
//----------------------------------------------------------------------------//
#define COREGAME_DISALLOW_COPY(_type_) \
      _type_(const _type_&) = delete;

#define COREGAME_DISALLOW_COPY_ASSIGN(_type_)\
      _type_& operator=(const _type_&) = delete;


//----------------------------------------------------------------------------//
// MOVE / MOVE ASSIGN                                                         //
//----------------------------------------------------------------------------//
#define COREGAME_DISALLOW_MOVE(_type_)  \
      _type_(_type_&&) = delete;

#define COREGAME_DISALLOW_MOVE_ASSIGN(_type_) \
      _type_& operator=(_type_&&) = delete;


//----------------------------------------------------------------------------//
// Everything                                                                 //
//----------------------------------------------------------------------------//
#define COREGAME_DISALLOW_CTOR_COPY_MOVE_ASSIGNS(_type_) \
            COREGAME_DISALLOW_CTOR(_type_)               \
            COREGAME_DISALLOW_COPY(_type_)               \
            COREGAME_DISALLOW_COPY_ASSIGN(_type_)        \
            COREGAME_DISALLOW_MOVE(_type_)               \
            COREGAME_DISALLOW_MOVE_ASSIGN(_type_)


#define COREGAME_DISALLOW_COPY_MOVE_ASSIGNS(_type_)    \
            /* Mo copy */                              \
            _type_(const _type_&) = delete;            \
            /* No assign */                            \
            _type_& operator=(const _type_&) = delete; \
            /* No move */                              \
            _type_(_type_&&) = delete;                 \
            /* No move-assign */                       \
            _type_& operator=(_type_&&) = delete;
