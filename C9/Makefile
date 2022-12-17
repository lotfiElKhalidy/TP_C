OPTIONS=-Wall -Wextra -g
CC=gcc
prog:calculatrice.o teZZt.o tests_calcul.o
	${CC} -o prog calculatrice.o teZZt.o tests_calcul.o
calculatrice.o:calculatrice.c calculatrice.h
	${CC} ${OPTIONS} calculatrice.c -c
tests_calculatrice.o:calculatrice.h teZZt.h tests_calcul.c
	${CC} ${OPTIONS} tests_calcul.c -c
teZZt.o:teZZt.h teZZt.c
	${CC} ${OPTIONS} -c teZZt.c
clean:
	rm -f calculatrice.o teZZt.o tests_calcul.o prog
