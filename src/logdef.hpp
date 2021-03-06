/**
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

#ifndef LOGG_LOGDEF_H
#define LOGG_LOGDEF_H

namespace logg {

/// Logs levels
enum LogLevel {
    LEVEL_DEBUG,    /// For a debug message
    LEVEL_ERROR,    /// For a error message
    LEVEL_WARNING,  /// For a warning message
    LEVEL_LOG       /// For a log message
};

/// Send logs to a file or standard output
enum LogSendto {
    FILE,    /// Save logs in a file directly
    STDOUT   /// Send logs to stdout and save in a file if you wants
};

} // namespace logg

#endif // LOGG_LOGDEF_H
