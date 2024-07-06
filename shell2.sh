#!/bin/bash

echo -e "\n1. OS version,release number,kernel version"
lsb_release -a
uname -r
echo -e "\n2. All available shells"
cat /etc/shells
echo -e "\n3. File system mounted"
df -h
echo -e "\n4. Memory information"
free -m
echo -e "\n5. Hardisk info"
lsblk|grep sda
echo -e "\n6. CPU information"
lscpu
