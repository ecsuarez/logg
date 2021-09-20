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

#ifndef LOGG_COLOR_H
#define LOGG_COLOR_H

#include "termcolor/termcolor.hpp"

// Definitions of used colors
// Log color used white and blod
#define LOGG_COLOR_WHITE termcolor::white
// Error color
#define LOGG_COLOR_RED termcolor::red
// Debug color
#define LOGG_COLOR_GREEN termcolor::green
// Warning color
#define LOGG_COLOR_YELLOW termcolor::yellow
// Reset colors
#define LOGG_COLOR_RESET termcolor::reset

#endif // LOGG_COLOR_H
