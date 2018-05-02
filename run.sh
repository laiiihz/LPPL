#!/bin/sh
echo 目录：
pwd
echo ××××××××编译中××××××××
cc main.c mpc.c -ledit -lm -o main.run
echo ××××××××编译完成××××××××
