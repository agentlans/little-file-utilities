#ifndef _TESTINGTOOLS
#define _TESTINGTOOLS

#include <stdio.h>
#include <stddef.h>

void mutate(FILE *file);
void write_random(FILE *file,size_t n);
size_t file_size(FILE *file);
void rewind(FILE *file);
unsigned int random_uniform_int(unsigned int n);

#endif