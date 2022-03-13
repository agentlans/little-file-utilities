#include <stdio.h>

#include "tools.h"

void help() {
	printf("Changes one random byte in each of the selected files.\n");
	printf("Usage: ./mutate file1 file2 [...]\n");
}

int main(int argc, char** argv) {
	if (argc == 1) {
		help();
		return 1;
	}
	int ret_value = 0;
	// For each file...
	int num_files = argc - 1;
	for (int i = 0; i < num_files; ++i) {
		const char* filename = argv[i+1];
		// Open the file and mutate it
		FILE* f = fopen(filename, "r+b");
		if (!f) {
			ret_value = 1;
			continue;
		} else {
			mutate(f);
			fclose(f);
		}
	}
	return ret_value;
}
