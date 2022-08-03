cc=gcc
flags= -Wall -Wextra 

rule-110: main.c
	$(cc) main.c -o rule-110 $(flags)
