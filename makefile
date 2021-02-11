CFLAG= -Wall -Werror
OBJS=cbfifo.o llfifo.o test_cbfifo.o test_llfifo.o main.o

all: main

main.o: main.c
	gcc -c $(CFLAGS) $< -o $@

cbfifo.o: cbfifo.c cbfifo.h
	gcc -c $(CFLAGS) $< -o $@

llfifo.o: llfifo.c llfifo.h
	gcc -c $(CFLAGS) $< -o $@

test_llfifo.o: test_llfifo.c llfifo.h
	gcc -c $(CFLAGS) $< -o $@

test_cbfifo.o: test_cbfifo.c cbfifo.h
	gcc -c $(CFLAGS) $< -o $@


main:	$(OBJS)
	gcc -o main $(OBJS)

clean:
	rm -f main $(OBJS)


