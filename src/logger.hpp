/*
 ** This file is part of the liblogg project.
 ** Copyright 2021 Ernest C. Suarez <ernestcsuarez@gmail.com>.
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
 */

/// @file logger.hpp Control Log class

#ifndef LOGG_LOGGER_H
#define LOGG_LOGGER_H

#include "logdef.hpp"
#include "io.hpp"
#include "formats.hpp"
#include <iostream>

/**
 * @brief Namespace logg.
 *
 * All logg clases and functions are here.
 */
namespace logg {

/**
 * @brief The logger class control all logs.
 *
 * Use for send logs into a file, or the terminal.
 * The logs show in the terminal, arent colorized by
 * default. You can store its logs in a file.
 *
 * Eg:
 *
 *     logg::logger log; // use default output log, LogSendto::STDOUT
 *     // send logs with log()
 *     log.log(LogLevel::Error, "Ops, an error ocurred");
 *     // or send logs with specific method
 *     log.error("Ops, an error ocurred");
 *
 * @see set_enable_colors
 *
 * @see save_to_file
 */
class LOGG_EXPORT logger
{

public:

    /**
     * @brief Default contructor.
     *
     * The default constructor send logs to stdout per default.
     */
    logger();

    /**
     * @brief Initialize logs into a file
     *
     * Send logs to a specific file.
     *
     * @param filename_to_log A file wich store the log.
     *
     * @param dir_to_log A directory to store the file.
     *
     * @warning You need permission for write in the directory.
     */
    logger(std::string filename_to_log, std::string dir_to_log);
    /**
     * @brief Default destructor.
     */
    ~logger();

    // Send logs using specifics methods:

    /**
     * @brief Send a log debug message.
     *
     * @param msg Log message.
     */
    void debug(std::string msg);

    /**
     * @brief Send a log warning message.
     *
     * @param msg Log message.
     */
    void warning(std::string msg);

    /**
     * @brief Send a log error message.
     *
     * @param msg Log message.
     */
    void error(std::string msg);

    /**
     * @brief Send a log standard message.
     *
     * @param msg Log message.
     */
    void log(std::string msg);

    /**
     * @brief Send a log standard message.
     *
     * You should specify the log level.
     *
     * @param level LogLevel enum type.
     *
     * @param msg Log message.
    */
    void log(LogLevel level, std::string msg);

    /**
     * @brief A formatted log, like printf.
     *
     * Eg:
     *     log.log(LogLevel::Error, "Cannot open this file: %s" ,
     *         "No souch file in directry");
     *
     * @param level LogLevel enum type.
     *
     * @param fmsg Formatted log message.
     *
     * @param ... Infinite parameters.
     */
    void fmt_log(LogLevel level, std::string fmsg, ...);

    /**
     * @brief Save all logs messages into a file.
     *
     * Eg:
     *     logg::logger log;
     *     log.error("Ops, an error ocurred");
     *     log.warning("See the file");
     *     log.save_to_file("/tmp/all_logg_logs.log");
     *
     * @param filename Rute and file name string to store the logs.
     *
     * @return Return true if all ok, or false, if an error occurs.
     */
    bool save_to_file(std::string filename);

    /**
     * @brief Change the output log.
     *
     * If you are using a logger storing the logs
     * in a file directly, you can change this to
     * send the logs in the terminal.
     * The logs sends now not are save into the other
     * old file, you can use save_to_file method for
     * store the new logs.
     *
     * @warning You need permission for write in the directory.
     *
     * @param send Use FILE or STDOUT for change.
     *
     * @see save_to_file
     */
    void set_log_sendto(LogSendto send);

    /**
     * @brief Send default logs with operator >>.
     *
     * Use for send standards logs like use log(msg).
     *
     * @warning Only you can send logs with level LEVEL_LOG.
     *
     * @param log A log message.
     */
    void operator<<(std::string log);

    /**
     * @brief Save logs with operator >>.
     *
     * Is the same thing that using log.save_to_file(filename)
     *
     * @warning You need permission for write in the directory.
     *
     * @param filename Rute and filename string to store the logs.
     *
     * @return Return true if all ok, or false, if an error occurs.
     */
    bool operator>>(std::string filename);

    /**
     * @brief Enable colors ouput, or disable its.
     *
     * The colors output are disabled per default.
     *
     * @param op Enable colors if op = true.
     */
    void set_enable_colors(bool op);

    /**
     * @brief Get if enable colors is true.
     * @return true if enable colors is enabled, false if not.
     */
    bool get_enable_colors();

private:
    LogSendto m_logs;
    std::string m_default_filename;
    std::string m_default_dir;
    // Enable colors in output logs. Default is false
    bool m_enable_colors;
    // It call when write a new log message, save the buffer
    // log in a temporary file
    void save_log(std::string log);
    // Assign a random name based in the system clock
    void set_default_filename(std::string new_name);
    void set_default_stdout(LogSendto send, std::string file, std::string dir);
};

} // namespace logg


#endif // LOGG_LOGGER_H
