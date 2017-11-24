//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Log.h                                                         //
//  Project   : CoreGame                                                      //
//  Date      : May 24, 2016                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2016, 2017                                       //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// std
#include <cstdarg>
#include <string>
#include <fstream>
// CoreGame
#include "CoreGame_Utils.h"
#include "CoreGame_Macros.h"

//COWTODO: Add documentation.
//COWTODO: Discover a way to add* and remove* methods accepts
//         any number of args like addOutput(stdout, stderr, file);

NS_COREGAME_BEGIN

class Log
{
    //------------------------------------------------------------------------//
    // Enums / Constants / Typedefs                                           //
    //------------------------------------------------------------------------//
public:
    enum class Type
    {
        Fatal   = 1 << 0,
        Error   = 1 << 1,
        Warning = 1 << 2,
        Verbose = 1 << 3,
        Debug1  = 1 << 4,
        Debug2  = 1 << 5,
        Debug3  = 1 << 5,
        Debug4  = 1 << 6,
    };

    enum class Output
    {
        kStdout = 1 << 0,
        kStderr = 1 << 1,
        kFile   = 1 << 2,
    };

    //------------------------------------------------------------------------//
    // Static Methods                                                         //
    //------------------------------------------------------------------------//
public:
    static Log& GetDefaultLogger();


    //------------------------------------------------------------------------//
    // CTOR / DTOR                                                            //
    //------------------------------------------------------------------------//
public:
    Log();
    ~Log();


    //------------------------------------------------------------------------//
    // Public Methods                                                         //
    //------------------------------------------------------------------------//
public:
    void addLogType(Type type);
    void removeLogType(Type type);
    bool isLogTypeActive(Type type) const;

    void addLogOutput(Output output);
    void removeLogOutput(Output output);
    bool isLogOutputActive(Output output) const;

    void setLogFileFilename(const std::string &filename, bool append);

    void log(Type type, const std::string &str);
    void log(Type type, const char *fmt, ...);


    //------------------------------------------------------------------------//
    // Private Methods                                                        //
    //------------------------------------------------------------------------//
private:
    void closeFileStream();
    void logAt(Type type, std::ostream &os, const std::string &buffer);


    //------------------------------------------------------------------------//
    // iVars                                                                  //
    //------------------------------------------------------------------------//
private:
    int m_type;
    int m_output;

    std::string  m_filename;
    std::fstream m_filestream;
};

NS_COREGAME_END


//----------------------------------------------------------------------------//
// Macros                                                                     //
//----------------------------------------------------------------------------//
#ifdef COREGAME_RELEASE
    #define COREGAME_DLOG(_type_, _fmt_, ...) do {} while(0)
#else
    #define COREGAME_DLOG(_type_, _fmt_, ...)               \
        CoreGame::Log::GetDefaultLogger().log(_type_,       \
                                              _fmt_,        \
                                              ##__VA_ARGS__)

#endif //COREGAME_RELEASE
