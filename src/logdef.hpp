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
 **/

/// @file logdef.hpp Logs structures and enums

#ifndef LOGG_LOGDEF_H
#define LOGG_LOGDEF_H

namespace logg {

/**
 * @brief Logs levels outputs
 *
 * Its used for select a type of log. If you can send a error message,
 * use LEVEL_ERROR level, you can enable colors output, and the error
 * is show in a red color.
 *
 * @see logg::logger::log
 */
enum LogLevel {
    LEVEL_DEBUG,    ///< For a debug message
    LEVEL_ERROR,    ///< For a error message
    LEVEL_WARNING,  ///< For a warning message
    LEVEL_LOG       ///< For a log message
};

/**
 * @brief Send logs to a file or standard output
 *
 * You can use a file for send the logs directly to this,
 * or select STDOUT and show the messages in a termial, with
 * colorized output if fou wants.
 *
 * Using a file, the log date use a long format, Y-M-D-H:M:S.
 * But in the terminal only use H:M:S. You can also send logs
 * to the terminal and before store its in a file, if you do this,
 * this logs will use a long date format when are put into the file.
 */
enum LogSendto {
    FILE,    ///< Save logs in a file directly
    STDOUT   ///< Send logs to stdout and save in a file if you wants
};

} // namespace logg

#endif // LOGG_LOGDEF_H
