#!/bin/bash

echo -e "filename=>bytecodes/00"
./monty bytecodes/00
echo -e "=============\n"

echo -e "filename=>bytecodes/00.m"
./monty bytecodes/00.m
echo -e "=============\n"

echo -e "filename=>bytecodes/01.m"
./monty bytecodes/01.m
echo -e "=============\n"

echo -e "filename=>bytecodes/02.m"
./monty bytecodes/02.m
echo -e "=============\n"

echo -e "filename=>bytecodes/03.m"
./monty bytecodes/03.m
echo -e "=============\n"

echo -e "filename=>bytecodes/04.m"
./monty bytecodes/04.m
echo -e "=============\n"

echo -e "filename=>bytecodes/05.m"
./monty bytecodes/05.m
echo -e "=============\n"

echo -e "filename=>bytecodes/06.m"
./monty bytecodes/06.m
echo -e "=============\n"

echo -e "filename=>bytecodes/07.m"
./monty bytecodes/07.m
echo -e "=============\n"

echo -e "filename=>bytecodes/08.m"
./monty bytecodes/08.m
echo -e "=============\n"

echo -e "filename=>bytecodes/09.m"
./monty bytecodes/09.m
echo -e "=============\n"

echo -e "filename=>bytecodes/10.m"
./monty bytecodes/10.m
echo -e "=============\n"

echo -e "filename=>bytecodes/11.m"
./monty bytecodes/11.m
echo -e "=============\n"

echo -e "filename=>bytecodes/12.m"
./monty bytecodes/12.m
echo -e "=============\n"

echo -e "filename=>bytecodes/2invalid_inst"
./monty bytecodes/2invalid_inst
echo -e "=============\n"

echo -e "filename=>bytecodes/invalid_inst.m"
./monty bytecodes/invalid_inst.m
echo -e "=============\n"

echo -e "filename=>bytecodes/unreadable.o"
sudo chmod 222 bytecodes/unreadable.o
./monty bytecodes/unreadable.o
sudo chmod 664 bytecodes/unreadable.o
echo -e "=============\n"

echo -e "./monty file1 file2"
./monty bytecodes/00 bytecodes/00.m
echo -e "=============\n"

echo -e "./monty bytecodes/unexisting_file.m"
./monty bytecodes/unexisting_file.m
echo -e "=============\n"
