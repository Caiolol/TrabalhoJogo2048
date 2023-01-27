all:
	gcc 2048.c -o 2048

clean:
	rm 2048

run: all
	./2048