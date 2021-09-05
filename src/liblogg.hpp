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

#ifndef LIBLOGG_H
#define LIBLOGG_H

#include <string>

// define logg namespace
namespace logg
{
// Log level errors
enum LogLevel {
    LEVEl_DEBUG,
    LEVEL_ERROR,
    LEVEL_WARNING,
    LEVEL_LOG
};

// Send the log to:
enum LogSendto {
    FILE,
    STDOUT
};

// Control log
class logger
{
public:
    logger();
    logger(std::string filename_to_log, std::string dir_to_log);
    ~logger();
    void debug(std::string msg);
    void warning(std::string msg);
    void error(std::string msg);
    void log(std::string msg, LogLevel level);
    bool save_to_file(std::string filename);
    void set_log_sendto(LogSendto send);

private:
    LogSendto m_logs;
    std::string m_default_filename;
    std::string m_default_dir;
    void save_log(std::string log);
    void set_default_filename(std::string new_name);
};

} // namespace logg


#endif // LIBLOGG_H
