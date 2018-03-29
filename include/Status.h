//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Status.h                                                      //
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

// std
#include <ostream>
// CoreGame
#include "CoreGame_Utils.h"

NS_COREGAME_BEGIN


///-----------------------------------------------------------------------------
/// @brief Defines the possible states of Game.
enum class Status
{
    Victory, ///< Game is over     - Player won.
    Defeat,  ///< Game is over     - Player lose.
    Continue ///< Game is not over - Keep playing.
};


///-----------------------------------------------------------------------------
/// @brief Check if game is over.
/// @return True if status != Status::Continue, false otherwise.
/// @see Status.
constexpr inline bool
IsGameOver(Status status) noexcept
{
    return status != Status::Continue;
}

///-----------------------------------------------------------------------------
/// @brief Output the name of status. (ex: Status::Victory)
/// @see Status.
std::ostream& operator <<(std::ostream &os, Status status) noexcept;

NS_COREGAME_END
