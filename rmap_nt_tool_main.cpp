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


#include "rmap_headers/rmap_printscan.hpp"
#include "rmap_headers/rmap_valid_addr_port_flag.hpp"
#include "rmap_headers/rmap_hostname_to_ip.hpp"
#include "rmap_headers/rmap_socket_specs.hpp"
#include <cstdio>
#include <getopt.h>


#define PORT_ACT 0
#define PORT_NEXT 1


static void ___rmap_nt_tool_scan___(const std::string &addr, std::vector<int> &ports, signed int flag)
{
    SOCKET_SPECS rmap_nt_tool_scan;   
    switch (flag) {
        case 0: {         
            if (ports.size() == 1) {
                printscan(addr);
                rmap_nt_tool_scan.tcp_connection_scan(addr, ports[PORT_ACT]);
                finished_scan();
            } else {
                printscan(addr);
                while (ports[PORT_ACT] <= ports[PORT_NEXT]) {
                    rmap_nt_tool_scan.tcp_connection_scan(addr, ports[PORT_ACT]);
                    ports[PORT_ACT]++;
                }

                finished_scan();
            }
            break;
        }

        case 1: {
            ports.clear();
            ports = {21,23,25,53,80,110,111,135,139,143,443,445,993,995,1723,3306,3389,5900,8080}; // TOP PORTS //
            std::vector<int>::iterator it_ports;   
            printscan(addr);
            
            for (it_ports = ports.begin(); it_ports < ports.end(); it_ports++) {
                rmap_nt_tool_scan.tcp_connection_scan(addr, *it_ports);
            }
            finished_scan();
            break;
        }
    }
};

int main(int argc, char *argv[])
{
    std::string addr;
    
    std::vector<int> ports;
    signed int flag_top_ports = 0;

    int option_index, arguments_parse;

    static const struct option long_options[] = {
        { "address",      required_argument,  NULL, 'a'},
        { "port",         required_argument,  NULL, 'p'},
        { "range-port",   required_argument,  NULL, 'r'},
        { "top-ports",    required_argument,  NULL, 't'},
        {  0,             0,                  0,     0 }
    };


    static const char *optstring = "a:p:r:t:";

    while ((arguments_parse = getopt_long(argc, argv, optstring, long_options, &option_index)) != -1) {
        switch (arguments_parse) {
            case 'a':
                addr = valid_input_addr(optarg);
                break;
            case 'p':
                ports.push_back(valid_input_port_and_flag(optarg));
                break;
            case 'r':
                ports.push_back(valid_input_port_and_flag(optarg));
                break;         
            case 't':
                flag_top_ports = valid_input_port_and_flag(optarg);
                break;
            default:
                banner_rmap_nt_tool();
                usage_rmap_nt_tool();
                exit(EXIT_FAILURE);
        }
    }

    if (optind < argc || argc == 1 || argc < 5 || addr.empty()) {
        banner_rmap_nt_tool();
        usage_rmap_nt_tool();
        exit(EXIT_FAILURE);
    }

    ___rmap_nt_tool_scan___(hostname_to_ip(addr), ports, flag_top_ports);

    return 0;
}
