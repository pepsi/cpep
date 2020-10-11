build: src/main.c
	gcc -std=c99 -lbinaryen -lpthread src/main.c -o target/pep