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


#ifndef rmap_nt_tool_socket_specs
#define rmap_nt_tool_socket_specs

#include <iostream>
#include <string>
#include <cerrno>
#include <fcntl.h>
#include <sys/utsname.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>


class SOCKET_SPECS {
public:
    struct timeval timevalue;
    fd_set fdset_rmap_nt_tool;
    struct sockaddr_in settings_socket;
    int create_socket();
    void tcp_connection_scan(const std::string &addr, int port);
};

int SOCKET_SPECS::create_socket()
{
    int socket_rmap_nt_tool;
     if ((socket_rmap_nt_tool = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("[!] SOCKET");
        exit(EXIT_FAILURE);
    }

    return socket_rmap_nt_tool;
};

void SOCKET_SPECS::tcp_connection_scan(const std::string &addr, int port)
{   
    int socket_rmap_nt_tool = create_socket();

    timevalue.tv_sec = 0;
    timevalue.tv_usec = 500000;

    settings_socket.sin_family = AF_INET;
    settings_socket.sin_addr.s_addr = inet_addr(addr.c_str());
    settings_socket.sin_port = htons(port);

    fcntl(socket_rmap_nt_tool, F_SETFL, O_NONBLOCK);
       
    connect(socket_rmap_nt_tool, (struct sockaddr *) &settings_socket, sizeof(settings_socket));

    FD_ZERO(&fdset_rmap_nt_tool);
    FD_SET(socket_rmap_nt_tool, &fdset_rmap_nt_tool);

    if (select(socket_rmap_nt_tool + 1, NULL, &fdset_rmap_nt_tool, NULL, &timevalue) == 1) {
        int status_socket_rmap_nt_tool;
        socklen_t len_socket_rmap_nt_tool = sizeof(status_socket_rmap_nt_tool);

        getsockopt(socket_rmap_nt_tool, SOL_SOCKET, SO_ERROR, &status_socket_rmap_nt_tool, &len_socket_rmap_nt_tool);

        if (status_socket_rmap_nt_tool == 0) 
            std::cout << "[+] PORT: " << port << "/TCP [OPEN]" << std::endl;
        else
            std::cerr << "[-] PORT: " << port << "/TCP [CLOSED]" << std::endl;
        
    } else
        std::cerr << "[*] PORT: " << port << "/TCP [POSSIBLE FILTERED]" << std::endl;
        
    close(socket_rmap_nt_tool);
   
};

#endif
