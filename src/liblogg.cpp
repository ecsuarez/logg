/**
 ** This file is part of the liblogg project.
 ** Copyright 2021 Ern <ern8642@gmail.com>.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU Lesser General Public License as
 ** published by the Free Software Foundation, either version 3 of the
 ** License, or (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU Lesser General Public License for more details.
 **
 ** You should have received a copy of the GNU Lesser General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#include "liblogg.hpp"

#include <iostream>
#include <fstream>
#include <ctime>

logg::logger::logger()
{
    // set logs default to stderr
    m_logs = LogSendto::STDERR;
    set_default_filename("liblogg_default");

}

logg::logger::logger(LogSendto send)
{
    // Check for log sender and configure
    if(send == LogSendto::FILE) {
        m_logs = LogSendto::FILE;
    } else if (send == LogSendto::STDERR) {
        m_logs = LogSendto::STDERR;
    }

}

logg::logger::~logger()
{
    // Remove temporary app log
    std::remove(m_default_filename.c_str());
}

void logg::logger::set_default_filename(std::string new_name)
{
    // Clear last name
    m_default_filename.clear();

    /* Set a new filename.
     * generate a random number, use system clock
     * and save in /tmp
     */

    // Default dir
    std::string dir = "/tmp";
    char n[50];
    std::sprintf(n, "%s/.%s_log_%i.log", dir.c_str(), new_name.c_str(), (int) std::time(NULL));
    // Insert
    m_default_filename.insert(0, n);
}

void logg::logger::save_log(std::string log)
{
    std::ofstream out;
    try {
        // Try open default file
        // open in app mode to store all logs
        out.open(m_default_filename, std::ios::app);
        // Set \n to end line
        out << log << "\n";
        // close
        out.close();
    }  catch (std::ios::failure &e) {}

}

void logg::logger::log(std::string msg, LogLevel level)
{
    // Save level string
    std::string _level;
    // Check level
    switch(level) {
        case LEVEL_LOG:     _level = "LOG";     break;
        case LEVEL_ERROR:   _level = "ERROR";   break;
        case LEVEL_WARNING: _level = "WARNING"; break;
        case LEVEl_DEBUG:   _level = "DEBUG";   break;
    }

    // get time

    // Create log
    char log[100];
    std::sprintf(log, "%s:%s: %s", _level.c_str(), "TIME", msg.c_str());
    // Save log temporary
    save_log(log);

    // Send to stderr if its enabled
    if(m_logs == STDERR) {
        std::cerr << log << std::endl;
    }
}

void logg::logger::debug(std::string msg)
{
    // Call log in level debug
    log(msg, LEVEl_DEBUG);
}

void logg::logger::error(std::string msg)
{
    // Call log in level error
    log(msg, LEVEL_ERROR);
}

void logg::logger::warning(std::string msg)
{
    // Call log in level warning
    log(msg, LEVEL_WARNING);
}





