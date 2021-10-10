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

#ifndef LOGG_FORMATS_H
#define LOGG_FORMATS_H

#include "logdef.hpp"
#include <iostream>
#include <ctime>
#include <cstdarg>

namespace logg {
namespace _internal {
namespace fmt {

/// Get log format for a file. The date is Y-M-D-h-m-s
std::string get_log_in_long_format(std::string level_s);
/// Get standard log format. Used for STDOUT
std::string get_log_in_std_format(std::string level_s);
/// Generate filename based in the time for diferents applications
/// using the library , and not colisions in default tmp buffer log
std::string get_generate_tmp_filename(std::string filename);
/// Get the LogLevel string
std::string get_log_level(LogLevel level);
/// Format a string log like sprintf, require a va_list
std::string get_fmt_log(std::va_list fap, std::string fmt);

} // namespace fmt
} // namespace _internal
} // namespace logg

#endif // LOGG_FORMATS_H
