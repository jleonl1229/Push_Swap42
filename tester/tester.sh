#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'
while read line;
do
	../push_swap $line >> /dev/null
	if [ $? -eq 0 ];
	then
		printf "Input: %-20s | Output: ${GREEN}OKAY${NC}\n" "$line"
	else
		printf "Input: %-20s | Output: ${RED}FAIL${NC}\n" "$line"
	fi
done < tester.txt
