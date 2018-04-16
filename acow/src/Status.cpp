//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Status.cpp                                                    //
//  Project   : CoreGame                                                      //
//  Date      : May 03, 2016                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2016, 2017                                       //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// Header
#include "../include/Status.h"

//----------------------------------------------------------------------------//
// Enums                                                                      //
//----------------------------------------------------------------------------//
std::ostream&
acow::game_goodies::operator <<(std::ostream &os, Status status) noexcept
{
    os << ((status == Status::Continue) ? "Status::Continue" :
           (status == Status::Defeat  ) ? "Status::Defeat"   :
                                          "Status::Victory");

    return os;    
}
