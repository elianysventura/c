bmptool: bmptool.c
	gcc -o bmptool bmptool.c -I.
clean:
	rm -f bmptool *.o *.err *~
