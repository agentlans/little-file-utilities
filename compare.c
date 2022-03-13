#include <stdio.h>
#include <string.h>

#define CLOSE if (f1) fclose(f1); if (f2) fclose(f2);

int main(int argc, char** argv) {
	if (argc != 3) {
		printf("Compares two files.\n");
		printf("Usage: ./compare file1 file2\n");
		printf("Returns 0 if their contents are the same, 1 if they're not, "
			"or 2 if either file can't be opened.\n");
		return 2;
	}
	char* file1 = argv[1];
	char* file2 = argv[2];
	FILE* f1 = fopen(file1, "rb");
	FILE* f2 = fopen(file2, "rb");
	if (!f1 || !f2) {
		CLOSE
		return 2;
	}
	char buf1[128];
	char buf2[128];
	do {
		size_t n1 = fread(buf1, 1, 128, f1);
		size_t n2 = fread(buf2, 1, 128, f2);
		if (n1 != n2) {
			CLOSE
			return 1;
		}
		// Both read the same length.
		// See whether their contents match.
		if (memcmp(buf1, buf2, n1) != 0) {
			CLOSE
			return 1;
		}
	} while (!feof(f1) && !feof(f2));
	return 0;
}
