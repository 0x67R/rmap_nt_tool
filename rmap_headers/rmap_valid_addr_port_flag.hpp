/*
    GNU General Public License v3.0

    Copyright (C) 2019-2020, Rafael Godoy, <0x67rafael@protonmail.com> .

    This file is part of R-Mapper-Network-Tool aka rmap_nt_tool.

    R-Mapper-Network-Tool is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    R-Mapper-Network-Tool is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with R-Mapper-Network-Tool.  If not, see <https://www.gnu.org/licenses/>6.
*/


#ifndef rmap_valid_addr_port_flag
#define rmap_valid_addr_port_flag

#include <iostream>
#include <string>
#include <regex>


static int valid_input_port_and_flag(const std::string &analyze_arg)
{
    std::regex validation_input_arg ("^[0-9]+$");

    if (!std::regex_match(analyze_arg, validation_input_arg)) {
        std::cerr << "[!] ARGUMENT INVALID: " << analyze_arg << std::endl;
        exit(EXIT_FAILURE);
    }

    int analyze_port = atoi(analyze_arg.c_str());

    if (analyze_port < 0 || analyze_port > 65535) {
        std::cerr << "[!] PORT IS INVALID" << std::endl;
        exit(EXIT_FAILURE);
    }

    return analyze_port;
};

static const std::string valid_input_addr(const std::string &analyze_arg)
{
    std::regex validation_input_arg ("^[a-z0-9.]+$");

    if (!std::regex_match(analyze_arg, validation_input_arg)) {
        std::cerr << "[!] ARGUMENT INVALID: " << analyze_arg << std::endl;
        exit(EXIT_FAILURE);
    }

    return analyze_arg;
};

#endif
