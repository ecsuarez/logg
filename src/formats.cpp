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

using namespace logg::_internal::fmt;

std::string get_log_level(logg::LogLevel level)
{
    // Save level string
    std::string _level;
    // Check level
    switch(level) {
        case logg::LEVEL_LOG:     _level = "LOG";     break;
        case logg::LEVEL_ERROR:   _level = "ERROR";   break;
        case logg::LEVEL_WARNING: _level = "WARNING"; break;
        case logg::LEVEL_DEBUG:   _level = "DEBUG";   break;
    }

    return _level;
}
