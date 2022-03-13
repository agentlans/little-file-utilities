#include <stdio.h>
#include "tools.h"

void help() {
	printf("Tries to make files unrecoverable by overwriting and deleting them.\n");
	printf("Usage: ./shred file1 file2 [...]\n");
}

int main(int argc, const char** argv) {
	if (argc <= 1) {
		help();
		return 1;
	}
	int ret_val = 0;
	int num_files = argc - 1;
	for (int i = 0; i < num_files; ++i) {
		const char* file = argv[i+1];
		// Open file
		FILE* f = fopen(file, "r+b");
		if (!f) {
			// Skip unopenable files
			ret_val = 1;
			continue;
		}
		// Fill the file with random data
		size_t fs = file_size(f);
		for (int round = 0; round < 3; ++round) {
			write_random(f, fs);
			rewind(f);
		}
		fclose(f);
		// Delete the file
		remove(file);
	}
	return ret_val;
}
