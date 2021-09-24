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

#include "formats.hpp"

using namespace logg::_internal::fmt;

std::string get_log_level(logg::LogLevel level)
{
    // Save level string
    std::string _level;
    // Check level
    switch(level) {
        case logg::LEVEL_LOG:     _level = "LOG";     break;
        case logg::LEVEL_ERROR:   _level = "ERROR";   break;
        case logg::LEVEL_WARNING: _level = "WARNING"; break;
        case logg::LEVEL_DEBUG:   _level = "DEBUG";   break;
    }

    return _level;
}

std::string get_generate_tmp_filename(std::string filename)
{
    // Get time
    // Create a timer and get system time with time(0)
    time_t now = time(0);
    // Store time in tm_time generated with localtime
    tm *tm_time = localtime(&now);
    char fname[40];
    std::sprintf(fname, "%s_%d%d%d", filename.c_str(), tm_time->tm_hour,
                 tm_time->tm_min, tm_time->tm_sec);
    return fname;
}
