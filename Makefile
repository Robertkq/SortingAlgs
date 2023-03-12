clean:
	-rm -rf main

all: clean
	clang++ -o main main.cpp sorting.cpp -O3

run: all
	./main
