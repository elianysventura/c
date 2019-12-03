bitops: bitops.c
	gcc -o bitops bitops.c -I.
clean:
	rm *.o *.err
