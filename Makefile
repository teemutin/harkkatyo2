my-cat: my-cat.o
		gcc my-cat.o -o my-cat
my-cat.o:
		gcc -c my-cat.c