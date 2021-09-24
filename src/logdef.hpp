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

#ifndef LOGG_LOGDEF_H
#define LOGG_LOGDEF_H

namespace logg {

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

} // namespace logg

#endif // LOGG_LOGDEF_H
