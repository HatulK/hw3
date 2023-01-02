.PHONY: all clean
all: isort txtfind

isort: isort.o
	gcc isort.o -o isort -lm

txtfind: txtfind.o
	gcc txtfind.o -o txtfind -lm
clean:
	rm -f  isort txtfind *.o
