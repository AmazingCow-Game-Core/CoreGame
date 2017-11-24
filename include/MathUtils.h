//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : MathUtils.h                                                   //
//  Project   : CoreGame                                                      //
//  Date      : Mar 09, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// CoreGame
#include "CoreGame_Utils.h"

NS_COREGAME_BEGIN

namespace MathUtils
{
    template <typename T>
    T clamp(T min, T max, T curr)
    {
        if(curr < min) return min;
        if(curr > max) return max;

        return curr;
    }
};

NS_COREGAME_END
