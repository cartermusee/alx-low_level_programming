#!/bin/bash
wget -P /tmp/ https://github.com/cartermusee/alx-low_level_programming/blob/master/0x18-dynamic_libraries/wishlib.so
export LD_PRELOAD=./wishlib.so
