/*
 ** This file is part of the logg project.
 ** Copyright 2021-2022 Ernest C. Suarez <ernestcsuarez@gmail.com>.
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

/// @file logdef.h Logs structures and enums

#ifndef LOGG_LOGDEF_H
#define LOGG_LOGDEF_H

// Define Platforms export symbols
#if defined(_MSC_VER) || defined(WIN64) || defined(_WIN64) || defined(WIN32) || defined(_WIN32)
#  define LOGG_EXPORT __declspec(dllexport)
#  define LOGG_IMPORT __declspec(dllimport)
#else
#  define LOGG_EXPORT     __attribute__((visibility("default")))
#  define LOGG_IMPORT     __attribute__((visibility("hidden")))
#endif

/**
 * @brief Log levels output
 *
 * Its used for select a log type. If you can send an error message,
 * use LEVEL_ERROR level, you can enable colors output, and the error
 * will be show with red color.
 *
 * @see logg_logger_log
 */
enum LOGG_EXPORT LoggLogLevel {
    LEVEL_DEBUG,    ///< A debug message
    LEVEL_ERROR,    ///< An error message
    LEVEL_WARNING,  ///< A warning message
    LEVEL_MESSAGE,  ///< A communicated message
    LEVEL_LOG       ///< A log message
};

/**
 * @brief Send logs to a file or standard output
 *
 * You can use a file for send logs directly to this,
 * or select STDOUT and show the messages in a termial, with
 * colorized output if fou wants.
 *
 * Using a file, the log date use a long format, Y-M-D-H:M:S.
 * But in the terminal only use H:M:S. You can also send logs
 * to the terminal and before store its in a file, if you do this,
 * this logs will use a long date format when are put into the file.
 */
enum LOGG_EXPORT LoggLogSendto {
    FILE,    ///< Save logs in a file directly
    STDOUT   ///< Send logs to stdout and save in a file if you wants
};


#endif // LOGG_LOGDEF_H
