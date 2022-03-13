#!/usr/bin/bash

# Run make first to generate the programs
make

print_help() {
	app=$1
	# Call programs with no parameters to print help message
	printf "`./$app`\n"
	echo 
}

for prog in compare generate shred mutate
do
	print_help $prog
done
