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
    set_default_stdout(LogSendto::STDOUT, ".log_default", "/tmp");
}

logg::logger::logger(std::string filename_to_log, std::string dir_to_log)
{
    m_logs = LogSendto::FILE;
    m_default_dir = dir_to_log;
    set_default_filename(filename_to_log);

}

logg::logger::~logger()
{
    // Remove temporary app log
    if(m_logs == STDOUT) {
        if(m_default_filename.empty() == false)
            std::remove(m_default_filename.c_str());
    }
}

void logg::logger::set_default_filename(std::string new_name)
{
    // Clear last name if not empty
    if(m_default_filename.empty() == false)
        m_default_filename.clear();

    // Set a new filename and save default in /tmp
    char n[50];
    std::sprintf(n, "%s/%s.log", m_default_dir.c_str(), new_name.c_str());
    // Insert
    m_default_filename.insert(0, n);
}

void logg::logger::set_default_stdout(LogSendto send, std::string file, std::string dir)
{
    // Set logs default to stderr
    m_logs = send;
    m_default_dir = dir;
    // Generate filenames based in the time for diferents applications
    // using the library , and not colisions in default buffer log
    // Get time
    // Create a timer and get system time with time(0)
    time_t now = time(0);
    // Store time in tm_time generated with localtime
    tm *tm_time = localtime(&now);
    char fname[40];
    std::sprintf(fname, "%s_%d%d%d", file.c_str(), tm_time->tm_hour,
                 tm_time->tm_min, tm_time->tm_sec);
    set_default_filename(fname);
}

void logg::logger::set_log_sendto(LogSendto send)
{
    if(send == LogSendto::STDOUT)
        set_default_stdout(LogSendto::STDOUT, ".log_default", "/tmp");
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
    }  catch (std::exception &e) {}

}

bool logg::logger::save_to_file(std::string filename)
{
    std::ifstream in;
    std::ofstream out;
    //std::string in_log_text;

    try {
        // Try to open tmp file
        in.open(m_default_filename);

        // Write read text in out
        out.open(filename, std::ios::app);
        if(!out.is_open()) {
            return false;
        }
        out << in.rdbuf();
        out.close();
        // All ok
        return true;
    } catch(std::exception &e) {
        // Return error
        return false;
    }
}


void logg::logger::log(LogLevel level, std::string msg)
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
    // Create a timer and get system time with time(0)
    time_t now = time(0);
    // Store time in tm_time generated with localtime
    tm *tm_time = localtime(&now);

    // Create log
    char log[100];
    std::sprintf(log, "[%s]:[%d:%d:%d]: %s", _level.c_str(), tm_time->tm_hour, tm_time->tm_min,
                 tm_time->tm_sec, msg.c_str());
    // Save log temporary
    save_log(log);

    // Send to stderr if its enabled
    if(m_logs == STDOUT) {
        std::clog << log << std::endl;
    }

}

void logg::logger::debug(std::string msg)
{
    // Call log in level debug
    log(LEVEl_DEBUG, msg);
}

void logg::logger::error(std::string msg)
{
    // Call log in level error
    log(LEVEL_ERROR, msg);
}

void logg::logger::warning(std::string msg)
{
    // Call log in level warning
    log(LEVEL_WARNING, msg);
}

void logg::logger::log(std::string msg)
{
    // Call log
    log(LEVEL_LOG, msg);
}





