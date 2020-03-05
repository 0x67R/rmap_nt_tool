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


#ifndef rmap_hostname_to_ip
#define rmap_hostname_to_ip

#include <iostream>
#include <cerrno>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

static const std::string hostname_to_ip(const std::string &hostname_target)
{
    struct hostent *h_to_ip;
    h_to_ip = gethostbyname(hostname_target.c_str());
    if (h_to_ip == NULL) {
        herror("[!] GETHOSTBYNAME");
        exit(EXIT_FAILURE);
    }

    const std::string c_host_to_ip = inet_ntoa(*((struct in_addr *) h_to_ip->h_addr_list[0]));

    if (c_host_to_ip.empty()) {
        perror("[!] INET_NTOA");
        exit(EXIT_FAILURE);
    }

    return c_host_to_ip;
};

#endif
