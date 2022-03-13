.PHONY: all test clean

all: compare generate mutate shred

compare: compare.c
	$(CC) compare.c -o compare

generate: generate.c tools.c
	$(CC) $^ -o $@

mutate: mutate.c tools.c
	$(CC) $^ -o $@

shred: shred.c tools.c
	$(CC) $^ -o $@

test:
	./test.sh

clean:
	rm -f compare generate mutate shred
