# little-file-utilities
Generates random input files for testing other programs

```
Compares two files.
Usage: ./compare file1 file2
Returns 0 if their contents are the same, 1 if they're not, or 2 if either file can't be opened.

Generates or overwrites a file with random data.
Usage: ./generate filename size_of_file

Tries to make files unrecoverable by overwriting and deleting them.
Usage: ./shred file1 file2 [...]

Changes one random byte in each of the selected files.
Usage: ./mutate file1 file2 [...]
```

- run `make` to compile the code
- `make test` to run the test cases
- `./help.sh` to print the above help message

## Author and license

Copyright :copyright: 2022 Alan Tseng

MIT License
