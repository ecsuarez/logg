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

#include "io.hpp"

namespace logg {
namespace _internal {
namespace io {

void save_text_in_file(std::string filename, std::string text)
{
    std::ofstream out;
    try {
        // Try open file
        // open in app mode to store all logs
        out.open(filename, std::ios::app);
        // Set \n to end line
        out << text << "\n";
        // always close
        out.close();
    }  catch (std::exception &e) {}
}

bool copy_file_to_file(std::string filename_in, std::string filename_to) 
{
    std::ifstream in;
    std::ofstream out;

    try {
        // Try to open input file
        in.open(filename_in);
        if(!in.is_open()) {
            return false;
        }

        // Write read text in output file
        out.open(filename_to, std::ios::app);
        if(!out.is_open()) {
            return false;
        }
        out << in.rdbuf();
        out.close();
        // All ok
        return true;
    } catch(std::exception &e) {
        // Return error
        return false;
    }
}

} // namespace io
} // namespace _internal
} // namespace logg
