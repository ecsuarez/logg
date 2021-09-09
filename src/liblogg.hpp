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

// Library Version
#define LOGG_VERSION 0.2

#include <string>

// define logg namespace
namespace logg
{
/** Log level errors
 * Its used for select the log mode, and used intern
 * Eg:
 * logg::log(logg::LogLevel::LEVEL_DEBUG, "My Debug Message");
 */
enum LogLevel {
    LEVEL_DEBUG,
    LEVEL_ERROR,
    LEVEL_WARNING,
    LEVEL_LOG
};

/** Send the log to a file or standard output,
 * you can use the function set_log_sendto()
 * to change the LogSendto, but normally its
 * used intern
 */
enum LogSendto {
    FILE,
    STDOUT
};

/** This class is a logger, you must send logs
 * from it.
 * Eg:
 * logg::logger log; // use default output log, LogSendto::STDOUT
 * log.log(LogLevel::Error, "Ops, an error ocurred"); // send logs with log()
 * log.error("Ops, an error ocurred"); // or send logs with specific method
 */
class logger
{
public:
    /** The default constructor send logs to stdout */
    logger();
    /** Send logs to a specific file, you should get permissions for write */
    logger(std::string filename_to_log, std::string dir_to_log);
    ~logger();
    /** Send logs using specifics methods:
     * debug   - Used for Debugs logs
     * warning - Used for Warnings logs
     * error   - Used for Errors logs
     * log     - Used for normal logs
     */
    void debug(std::string msg);
    void warning(std::string msg);
    void error(std::string msg);
    void log(std::string msg);
    /** Used for send logs,you must specify as sending the log */
    void log(LogLevel level, std::string msg);
    /** This save all logs messages to a file
     * Eg:
     * logg::logger log;
     * log.error("Ops, an error ocurred");
     * log.warning("See the file");
     * log.save_to_file("/tmp/all_logg_logs.log");
     */
    bool save_to_file(std::string filename);
    void set_log_sendto(LogSendto send);

private:
    LogSendto m_logs;
    std::string m_default_filename;
    std::string m_default_dir;
    // It call when write a new log message
    // save the buffer log in a temporary file
    void save_log(std::string log);
    // Assign a random nomber based in the system
    // clock for the name
    void set_default_filename(std::string new_name);
    void set_default_stdout(LogSendto send, std::string file, std::string dir);
};

} // namespace logg


#endif // LIBLOGG_H
