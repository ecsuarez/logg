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

#include <iostream>
#include <liblogg.hpp>

int main(int argc, char **argv)
{
    // Using stdout to show logs
    logg::logger l;
    l.log(logg::LEVEL_LOG, "HEllo liblogg, frist log");
    l.log(logg::LEVEL_ERROR, "HEllo liblogg, second log, level error");
    l.log(logg::LEVEL_DEBUG, "HEllo liblogg, ... log, level debug");
    // Save log
    l.save_to_file("test.log");
    return 0;
}
