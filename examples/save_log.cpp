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

#include <iostream>
#include <logg.hpp>

int main(int argc, char **argv)
{
    // Using stdout to show logs
    logg::logger l;
    l.log(logg::LEVEL_LOG, "Frist log");
    l.error("Second log, in level error");

    // use save_to_file to save in a file
    l.save_to_file("/tmp/logg_example.log");
    // or you can use operator >>
    //l >> "/tmp/logg_example.log";

    // Use other logger
    logg::logger log_in_file("logg_contructor_example.log", "/tmp");
    // All logs are atomatically store in the output file

    log_in_file << "This log is saved in the file /tmp/logg_contructor_example.log";
    log_in_file << "Second log";

    return 0;
}
