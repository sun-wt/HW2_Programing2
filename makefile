all: hw0201.o hw0201another.c hw0202.o hw0202another.c hw0203.o hw0203another.c hw0204.o hw0204another.c
	gcc hw0201another.c hw0201.o -o hw0201 -lm
	gcc hw0202another.c hw0202.o -o hw0202 -lm
	gcc hw0203another.c hw0203.o -o hw0203 -lm
	gcc hw0204another.c hw0204.o -o hw0204 -lm

hw0201: hw0201.c
	gcc -c hw0201.c -o hw0201.o -lm
	gcc -shared hw0201.o -o libhw0201.so

hw0202: hw0202.c 
	gcc -c hw0202.c -o hw0202.o -lm
	gcc -shared hw0202.o -o libhw0202.so

hw0203: hw0203.c
	gcc -c hw0203.c -o hw0203.o -lm
	gcc -shared hw0203.o -o libhw0203.so

hw0204: hw0204.c
	gcc -c hw0204.c -o hw0204.o -lm
	gcc -shared hw0204.o -o libhw0204.so