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

#include "logger.hpp"
#include "internal/colors.hpp"
#include <fstream>
#include <cstdarg>

namespace logg {

logger::logger()
{
    // Disable colors for default
    m_enable_colors = false;
    this->set_default_stdout(LogSendto::STDOUT, ".log_default", P_tmpdir);
}

logger::logger(std::string filename_to_log, std::string dir_to_log)
{
    // Disable colors for default
    m_enable_colors = false;
    m_logs = LogSendto::FILE;
    m_default_dir = dir_to_log;
    this->set_default_filename(filename_to_log);

}

logger::~logger()
{
    // Remove temporary app log
    if(m_logs == STDOUT) {
        if(m_default_filename.empty() == false)
            std::remove(m_default_filename.c_str());
    }
}

void logger::set_default_filename(std::string new_name)
{
    // Clear last name if not empty
    if(m_default_filename.empty() == false)
        m_default_filename.clear();

    // Set new filename and save default in /tmp
    char n[50];
    std::sprintf(n, "%s/%s.log", m_default_dir.c_str(), new_name.c_str());
    // Insert
    m_default_filename.insert(0, n);
}

void logger::set_default_stdout(LogSendto send, std::string file, std::string dir)
{
    // Set logs default to stderr
    m_logs = send;
    m_default_dir = dir;
    // Get a generated filename based in the clock
    std::string fname = _internal::fmt::get_generate_tmp_filename(file);
    this->set_default_filename(fname);
}

void logger::set_log_sendto(LogSendto send)
{
    if(send == LogSendto::STDOUT)
        this->set_default_stdout(LogSendto::STDOUT, ".log_default", P_tmpdir);
}

void logger::operator<<(std::string log)
{
    this->log(LogLevel::LEVEL_LOG, log);
}

bool logger::operator>>(std::string filename)
{
    // Use save_to_file function and check
    bool ok = this->save_to_file(filename);
    if(ok) {
        return true;
    } else {
        return false;
    }

}

void logger::set_enable_colors(bool op)
{
    m_enable_colors = op;
}

bool logger::get_enable_colors()
{
    return m_enable_colors;
}

void logger::save_log(std::string log)
{
    _internal::io::save_text_in_file(m_default_filename, log);
}

bool logger::save_to_file(std::string filename)
{
    bool copy_is_ok = _internal::io::copy_file_to_file(
                m_default_filename, filename);
    if(copy_is_ok)
        return true;
    else
        return false;
}


void logger::log(LogLevel level, std::string msg)
{
    // Get generated level string
    std::string _level = _internal::fmt::get_log_level(level);

    std::string format_log;
    // Use log_long_format for save in buffer log
    format_log = _internal::fmt::get_log_in_long_format(_level);
    // Save log temporary
    this->save_log(format_log + msg);

    // Send to stderr if enabled
    if(m_logs == STDOUT) {
        // Use log_std_format for show in stdout
        format_log = _internal::fmt::get_log_in_std_format(_level);
        if(m_enable_colors) {
            switch(level) {
                case LEVEL_LOG:
                    std::cout << LOGG_COLOR_WHITE << format_log << msg
                              << LOGG_COLOR_RESET << std::endl;
                    break;
                case LEVEL_ERROR:
                    std::cout << LOGG_COLOR_RED << format_log << msg
                              << LOGG_COLOR_RESET << std::endl;
                    break;
                case LEVEL_WARNING:
                    std::cout << LOGG_COLOR_YELLOW << format_log << msg
                              << LOGG_COLOR_RESET << std::endl;
                    break;
                case LEVEL_DEBUG:
                    std::cout << LOGG_COLOR_GREEN << format_log << msg
                              << LOGG_COLOR_RESET << std::endl;
                    break;
                case LEVEL_MESSAGE:
                    std::cout << LOGG_COLOR_GREY << format_log << msg
                              << LOGG_COLOR_RESET << std::endl;
            }
        } else {
            // Send log without colors
            std::cout << format_log << msg << std::endl;
        }
    }
    
}

void logger::fmt_log(LogLevel level, std::string fmsg, ...)
{
    std::va_list ap;
    va_start(ap, fmsg);
    // Get log
    std::string formatted_log = _internal::fmt::get_fmt_log(ap, fmsg);
    va_end(ap);
    this->log(level, formatted_log);
}

void logger::debug(std::string msg)
{
    // Call log in level debug
    this->log(LEVEL_DEBUG, msg);
}

void logger::error(std::string msg)
{
    // Call log in level error
    this->log(LEVEL_ERROR, msg);
}

void logger::message(std::string msg)
{
    // Call log in level message
    this->log(LEVEL_MESSAGE, msg);
}

void logger::warning(std::string msg)
{
    // Call log in level warning
    this->log(LEVEL_WARNING, msg);
}

void logger::log(std::string msg)
{
    // Call log
    this->log(LEVEL_LOG, msg);
}


} // namespace logg


