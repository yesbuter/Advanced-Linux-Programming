use_mkstemp: main.o temp_file.o
	gcc $(CFLAG) -o main.o temp_file.o

main.o: main.c
	gcc $(CFLAG) -c main.c

temp_file.o: temp_file.c
	gcc $(CFLAG) -c temp_file.c

clean:
	rm -f *.o use_mkstemp
