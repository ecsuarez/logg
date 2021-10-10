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

#ifndef LOGG_IO_H
#define LOGG_IO_H

#include <iostream>
#include <fstream>

namespace logg {
namespace _internal {
namespace io {

/// Save text in a file
void save_text_in_file(std::string filename, std::string text);
/// Copy file content to other file
bool copy_file_to_file(std::string filename_in, std::string filename_to);

} // namespace io
} // namespace _internal
} // namespace logg

#endif // LOGG_IO_H
