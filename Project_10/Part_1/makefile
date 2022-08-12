#Hanz Chua 
#U26738740
#makefile for tshirt_store2
tshirt_store2: tshirt_store2.o tshirt.o readline.o
	gcc -o tshirt_store2 tshirt.o tshirt_store2.o readline.o

tshirt_store2.o: tshirt.h tshirt_store2.c
	gcc -c tshirt_store2.c

tshirt.o: tshirt.c tshirt.h readline.h
	gcc -c tshirt.c

readline.o: readline.c readline.h
	gcc -c readline.c

clean:
	rm tshirt_store2 tshirt.o readline.o tshirt_store2.o
