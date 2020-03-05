# (R-MAPPER-NETWORK-TOOL)
[R-Mapper-Network-Tool](https://github.com/0x67R/rmap_nt_tool/blob/master/rmap_nt_tool_main.cpp) is software focused on scanning TCP/IP protocol ports.

#### Running Software
<img src="/screenshot/Banner.png" width="750" heigth="350">
<img src="/screenshot/Running.png" width="750" heigth="350">

# Features
 [R-Mapper-Network-Tool](https://github.com/0x67R/rmap_nt_tool/blob/master/rmap_nt_tool_main.cpp) use the SYN/ACK flags to try to find out if the door is OPEN or CLOSED
and use a TIMEOUT to try to find out if an door is FILTERED.

Tested on Debian, Ubuntu, Mint, Fedora and CentOS.

## How to build
```
g++ -std=gnu++2a -m64 -O3 -fstack-protector-all -s rmap_nt_tool_main.cpp -o rmap_nt_tool -Wall -Werror
```

## License
- Copyright (C) 2019-2020 Rafael Godoy, <0x67rafael@protonmail.com>
- This project is licensed under the GNU General Public License v3.0 - see the [LICENSE.md](https://github.com/0x67R/rmap_nt_tool/blob/master/LICENSE.md)
 file for details
 <img src="/png/freesoftware.png" width="250" heigth="250">
 
