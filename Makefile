.PHONY: clean
CC=clang
CFLAGS=-g --std=c11 -fpic

all: flowchart

flowchart: flowchart.o
	$(CC) -Wall -o $@ $^

flowchart.o: flowchart.c 
	$(CC) -c -Wall -o $@ $< $(CFLAGS)

clean:
	rm -f flowchart.o flowchart
