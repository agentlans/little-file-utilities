#include <stdio.h>
#include <stdlib.h>

#include "tools.h"

// Returns a uniformly-distributed integer in [0,n).
unsigned int random_uniform_int(unsigned int n) {
	float r = ((float) rand()) / RAND_MAX;
	return (unsigned int) (r * n);
}

// Rewinds file back to beginning
void rewind(FILE* file) {
	fseek(file, 0, SEEK_SET);
}

// Returns size of file in bytes
size_t file_size(FILE* file) {
	fseek(file, 0, SEEK_END);
	return ftell(file);
}

// Writes n random bytes to file
void write_random(FILE* file, size_t n) {
	for (int i = 0; i < n; ++i) {
		char byte = random_uniform_int(256);
		fwrite(&byte, 1, 1, file);
	}
	fflush(file);
}

// Changes a random byte in the file
void mutate(FILE* file) {
	size_t fs = file_size(file);
	size_t place = random_uniform_int(fs);
	// Get the byte, change it, and put it back.
	fseek(file, place, SEEK_SET);
	char dat;
	fread(&dat, 1, 1, file);
	dat++; // will automatically wrap around if over 255
	fseek(file, place, SEEK_SET);
	fwrite(&dat, 1, 1, file);
}
