CFLAGS = -g -std=c11

all:	array_of_int.o array_of_int_test

array_of_int.o:	array_of_int.c array_of_int.h
	gcc $(CFLAGS) -c array_of_int.c

array_of_int_test:	array_of_int_test.o array_of_int.o array_of_int.h
	gcc $(CFLAGS) -o array_of_int_test array_of_int_test.o array_of_int.o

array_of_int_test.o:	array_of_int_test.c array_of_int.h
	gcc $(CFLAGS) -c array_of_int_test.c

clean:
	$(RM) array_of_int.o
	$(RM) array_of_int_test.o array_of_int_test
