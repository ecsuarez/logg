/**
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

#ifndef LOGG_OPS_H
#define LOGG_OPS_H

#include "logdef.h"

/// Get the LoggLevel string
const char  *__logg_get_loglevel(const logg_logger_t *__logger, const LoggLevel __level);



#endif // LOGG_OPS_H