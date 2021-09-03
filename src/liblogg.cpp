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

#include "liblogg.hpp"

logg::logger::logger()
{
    m_logs = LogSendto::STDERR;

}

logg::logger::logger(LogSendto send)
{
    if(send == LogSendto::FILE) {
        m_logs = LogSendto::FILE;
    } else if (send == LogSendto::STDERR) {
        m_logs = LogSendto::STDERR;
    }

}

