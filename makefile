bazinga: fopen.o
	gcc fopen.o -o "runner"
fopen.o: fopen.c
	gcc -c fopen.c
run: bazinga
	./runner
