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


#ifndef rmap_printscan
#define rmap_printscan

#include <iostream>
#include "rmap_time_stamp.hpp"
#include "rmap_banner_usage.hpp"

static void printscan(const std::string &addr)
{
	banner_rmap_nt_tool();
	std::cout << "[*] Starting RMAP NETWORK TOOL at ( " << time_stamp() << " )\n" << std::endl;
	std::cout << "====================================" << std::endl;
	std::cout << "[+] Target IP: " << addr << std::endl;
	std::cout << "====================================" << std::endl;
};

static void finished_scan()
{
	std::cout << "====================================" << std::endl;
	std::cout << "\n\n[*] Finished scan at ( " << time_stamp() << " )" << std::endl;
};

#endif
