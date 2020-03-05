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

#ifndef rmap_time_stamp
#define rmap_time_stamp

#include <iostream>
#include <cstring>
#include <ctime>

static const std::string time_stamp()
{
    time_t cal_time;
    cal_time = time(NULL);
    auto act_time_stamp = asctime(localtime(&cal_time));
    act_time_stamp[strlen(act_time_stamp) -1] = '\0';
    return act_time_stamp;
};

#endif
