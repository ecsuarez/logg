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
#include <cstring>

namespace logg {
namespace _internal {
namespace fmt {

std::string get_log_level(LogLevel level)
{
    // Save level string
    std::string _level;
    // Check level
    switch(level) {
        case logg::LogLevel::LEVEL_LOG:     _level = "LOG";     break;
        case logg::LogLevel::LEVEL_ERROR:   _level = "ERROR";   break;
        case logg::LogLevel::LEVEL_WARNING: _level = "WARNING"; break;
        case logg::LogLevel::LEVEL_DEBUG:   _level = "DEBUG";   break;
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

std::string get_log_in_std_format(std::string level_s)
{
    time_t now = time(0);
    tm *tm_time = localtime(&now);

    // Create log
    // Format: [LEVEL]:[TIME]: Message
    char format_log[40];
    std::sprintf(format_log, "[%s]:[%d:%d:%d]: ", level_s.c_str(), 
                 tm_time->tm_hour, tm_time->tm_min, tm_time->tm_sec);
    return format_log;
}

std::string get_log_in_long_format(std::string level_s)
{
    // Use a date format instead a time format
    time_t now = time(0);
    tm *tm_date = localtime(&now);

    // Create log
    // Format: [LEVEL]:[DATE: D-M-Y]: Message
    char format_log[80];
    std::sprintf(format_log, "[%s]:[%d-%d-%d %d:%d:%d]: ", level_s.c_str(), 
                 tm_date->tm_mday, tm_date->tm_mon, 1900 + tm_date->tm_year,
                 tm_date->tm_hour, tm_date->tm_min, tm_date->tm_sec);
    return format_log;
}

std::string get_fmt_log(std::va_list fap, const char *fmt)
{
    // fmt len
    const std::size_t FORMAT_LEN = std::strlen(fmt);
    // format
    char fmt_out[FORMAT_LEN];
    // output std::string
    std::string out;
    std::va_list ap;
    // Copy list
    va_copy(ap, fap);
    // Use vsprintf and put formatted log in fmt_out
    std::vsprintf(fmt_out, fmt, ap);
    // end va_list ap
    va_end(ap);
    // store format in a std::string
    out = fmt_out;
    return out;
}

}  // namespace fmt
} // namespace _internal
} // namespace logg
