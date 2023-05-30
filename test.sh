#!/bin/bash

echo -e "filename=>bytecodes/00"
(./monty bytecodes/00) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/00.m"
(./monty bytecodes/00.m) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/01.m"
(./monty bytecodes/01.m) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/02.m"
(./monty bytecodes/02.m) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/03.m"
(./monty bytecodes/03.m) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/04.m"
(./monty bytecodes/04.m) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/05.m"
(./monty bytecodes/05.m) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/06.m"
(./monty bytecodes/06.m) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/07.m"
(./monty bytecodes/07.m) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/08.m"
(./monty bytecodes/08.m) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/09.m"
(./monty bytecodes/09.m) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/10.m"
(./monty bytecodes/10.m) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/11.m"
(./monty bytecodes/11.m) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/12.m"
(./monty bytecodes/12.m) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/13.m"
(./monty bytecodes/13.m) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/14.m"
(./monty bytecodes/14.m) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/2invalid_inst"
(./monty bytecodes/2invalid_inst) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/invalid_inst.m"
(./monty bytecodes/invalid_inst.m) | cat -e
echo -e "=============\n"

echo -e "filename=>bytecodes/unreadable.o"
sudo chmod 222 bytecodes/unreadable.o
(./monty bytecodes/unreadable.o) | cat -e
sudo chmod 664 bytecodes/unreadable.o
echo -e "=============\n"

echo -e "./monty file1 file2"
./monty bytecodes/00 bytecodes/00.m
echo -e "=============\n"

echo -e "./monty bytecodes/unexisting_file.m"
(./monty bytecodes/unexisting_file.m) | cat -e
echo -e "=============\n"
