#!/bin/bash

gcc -I./header -o ./bin/main ./src/main.c ./src/utils.c
./bin/main 