blink: blink.o rpi.o
	gcc -o bink.o rpi.o

blink.o: blink.c
	gcc -o blink.o -c blink.c

rpi.o: rpi.c
	gcc -o rpi.o -c rpi.c rpi.h

clean:
	rm *.o
