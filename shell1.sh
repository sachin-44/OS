#!/bin/bash

echo "1. Current logged user and username"
whoami
echo "2. Current shell"
echo $SHELL
echo "3. Home directory"
echo $HOME
echo "4. OS type"
uname -s
echo "5. Current path setting"
echo $PATH
echo "6. Current directory"
pwd
echo "7. Number of users logged in"
who -q
