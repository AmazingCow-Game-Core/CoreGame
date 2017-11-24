//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Log.cpp                                                       //
//  Project   : CoreGame                                                      //
//  Date      : May 24, 2016                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2016, 2017                                       //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// Header
#include "../include/Log.h"
// std
#include <iostream>
// CoreGame
#include "../include/StringUtils.h"

// Usings
USING_NS_COREGAME;


//----------------------------------------------------------------------------//
// Operator Overloads for Log::Type                                           //
//----------------------------------------------------------------------------//
std::ostream& operator <<(std::ostream &os, Log::Type t)
{
    auto s = (t == Log::Type::Fatal)   ?  "Fatal"    :
             (t == Log::Type::Error)   ?  "Error"    :
             (t == Log::Type::Warning) ?  "Warning"  :
             (t == Log::Type::Verbose) ?  "Verbose"  :
             (t == Log::Type::Debug1)  ?  "Debug1"   :
             (t == Log::Type::Debug2)  ?  "Debug2"   :
             (t == Log::Type::Debug3)  ?  "Debug3"   :
             (t == Log::Type::Debug4)  ?  "Debug4"   :
                                          "DUMMY";

    os << s;
    return os;
}


//----------------------------------------------------------------------------//
// Static Methods                                                             //
//----------------------------------------------------------------------------//
Log& Log::GetDefaultLogger()
{
    static Log s_logger;
    return s_logger;
}


//----------------------------------------------------------------------------//
// CTOR / DTOR                                                                //
//----------------------------------------------------------------------------//
Log::Log()
{
    addLogType(Type::Fatal);
    addLogType(Type::Error);
    addLogType(Type::Warning);
    addLogType(Type::Verbose);
    addLogType(Type::Debug1);
    addLogType(Type::Debug2);
    addLogType(Type::Debug3);
    addLogType(Type::Debug4);

    addLogOutput(Output::kStdout);
}

Log::~Log()
{
    closeFileStream();
}


//----------------------------------------------------------------------------//
// Public Methods                                                             //
//----------------------------------------------------------------------------//
void Log::addLogType(Type type)
{
    m_type |= static_cast<int>(type);
}

void Log::removeLogType(Type type)
{
    m_type &= ~static_cast<int>(type);
}

bool Log::isLogTypeActive(Type type) const
{
    return m_type & static_cast<int>(type);
}


void Log::addLogOutput(Output output)
{
    m_output |= static_cast<int>(output);
}

void Log::removeLogOutput(Output output)
{
    m_output &= ~static_cast<int>(output);
}

bool Log::isLogOutputActive(Output output) const
{
    return m_output & static_cast<int>(output);
}


void Log::setLogFileFilename(const std::string &filename, bool append)
{
    closeFileStream();
    auto mode = (append)
                ? std::ios::out | std::ios::app
                : std::ios::out;

    m_filestream.open(filename, mode);
    COREGAME_ASSERT_ARGS(m_filestream.is_open() == true,
                         "Failed to open stream with filename (%s)",
                         filename.c_str());
}

void Log::log(Type type, const std::string &str)
{
    if(!isLogTypeActive(type))
        return;

    //Check for cout.
    if(isLogOutputActive(Output::kStdout))
        logAt(type, std::cout, str);

    //Check for cerr.
    if(isLogOutputActive(Output::kStderr))
        logAt(type, std::cerr, str);

    //Check for file and if file is open.
    if(isLogOutputActive(Output::kFile) && m_filestream.is_open())
        logAt(type, m_filestream, str);

}

void Log::log(Type type, const char *fmt, ...)
{
    if(!isLogTypeActive(type))
        return;

    //Build the string.
    va_list args;
    va_start(args, fmt);

    log(type, StringUtils::vformat(fmt, args));

    va_end(args);
}


//----------------------------------------------------------------------------//
// Private Methods                                                            //
//----------------------------------------------------------------------------//
void Log::closeFileStream()
{
    if(m_filestream.is_open())
    {
        m_filestream.flush();
        m_filestream.close();
    }
}


void Log::logAt(Type type, std::ostream &os, const std::string &msg)
{
    os << "[" << type << "] " << msg << std::endl << std::flush;
}
