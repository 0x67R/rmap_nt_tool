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



#ifndef rmap_banner_usage
#define rmap_banner_usage

#include <iostream>

static void banner_rmap_nt_tool()
{
    std::cout << "\n\t========= <R-MAPPER-NETWORK-TOOL> [PORT SCANNER - TCP/IP]  =========\n"
                 "\tCopyright (C) 2019-2020, Rafael Godoy, <0x67rafael@protonmail.com>\n"
                 "\t\t      Github: https://github.com/0x67R\n\n"
                 "\t____________________________________________________________________\n" << std::endl; 
};

static void usage_rmap_nt_tool()
{
    std::cout << "[!] Usage: rmap_nt_tool [options...]\n\n"
                 "\t-a, --address      \t Example: 127.0.0.1, foo.com, foo.net, foo.org, etc..\n"
                 "\t-p, --port         \t Example: Choose an port from 0 to 65535\n"
           		 "\t-r, --range-port   \t Example: Choose an port from 1 to 65535 for port range\n"
                 "\t-t, --top-ports    \t Example: Choose an option 0=OFF, 1=ON" << std::endl;
};

#endif
