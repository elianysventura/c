all:	tenthreads

tenthreads:	tenthreads.o
	gcc tenthreads.c -o tenthreads -lpthread

tenthreads.o:	tenthreads.c
	gcc -c tenthreads.c -o tenthreads.o

clean:
	rm -f tenthreads tenthreads.o core*~
