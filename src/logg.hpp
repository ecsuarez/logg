/*
 ** This file is part of the liblogg project.
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

///  @file logg.hpp Global import header

#ifndef LOGG_LOGG_H
#define LOGG_LOGG_H

#include "version.hpp" // Library version
#include "logdef.hpp"  // Logs structures and enums
#include "logger.hpp"  // Public logger class

/**
 * @mainpage
 *
 * The Logg library is an easy to use and fast logging library,
 * which you can send logs into a file, or show it in a terminal.
 * The logs may be with colorized output, also you can use a formated
 * output like printf.
 *
 * The Logg project is free software, you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License
 * either version 3 of the License, or (at your option) any later version.
 *
 * # Getting Started
 * You can access to Logg library using this header file (logg.hpp).
 *
 * If you want send a log message, you should use one log level:
 * * Level Debug - Using for debug logs.
 * * Level Error - Using for errors and critical logs.
 * * Level Warning - Just a warning.
 * * Level Log - Is used for send an informative log or just output some text.
 *
 * This levels are defined in the file logdef.hpp.
 * @see logdef.hpp
 *
 * You control all logs with the logger class.
 * @see logg::logger
 *
 */

/**
 * @author Ernest C. Suarez <ernestcsuarez@gmail.com>
 */

#endif // LOGG_LOGG_H
