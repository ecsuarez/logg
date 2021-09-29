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
#include <logg.hpp>

int main(int argc, char **argv)
{
    // Using stdout to show logs
    logg::logger l;
    l.log(logg::LEVEL_LOG, "HEllo liblogg, frist log");
    l.log(logg::LEVEL_ERROR, "HEllo liblogg, second log, level error");
    // Enable colors
    l.set_enable_colors(true);
    l.log(logg::LEVEL_DEBUG, "HEllo liblogg, ... log, level debug");
    // Use << for send a log in LEVEL_LOG
    l << "Send a log too";
    // Format a log
    std::string sum_text = "The sum of";
    int sum_a = 10;
    int sum_b = 10;
    l.fmt_log(logg::LEVEL_DEBUG, "%s %d and %d is %d", sum_text.c_str(), sum_a,
              sum_b, sum_a + sum_b );

    // Save log
    //l.save_to_file("test.log");
    // or you can use >> for save
    //l >> "test.log";

    return 0;
}
