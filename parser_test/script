#!/bin/bash
flex parse.l
yacc -d parse.y
g++ -c lex.yy.c y.tab.c
g++  y.tab.o lex.yy.o
./a.out<./ini.txt