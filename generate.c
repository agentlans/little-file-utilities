#include <stdio.h>
#include <stdlib.h>

#include "tools.h"

void help() {
	printf("Generates or overwrites a file with random data.\n");
	printf("Usage: ./generate filename size_of_file\n");
}

int main(int argc, char** argv) {
	if (argc != 3) {
		help();
		return 1;
	}
	// Read parameters
	const char* filename = argv[1];
	int size = atoi(argv[2]);
	// Open file
	FILE* f = fopen(filename, "wb");
	if (!f) {
		fprintf(stderr, "Couldn't create file.");
		return 1;
	}
	// Fill with random content
	write_random(f, size);
	fclose(f);
	return 0;
}
