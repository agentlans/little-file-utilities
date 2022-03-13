#!/usr/bin/bash

expect() {
	if [ $? -eq $2 ]
	then
		echo $1 "- OK"
	else
		echo $1 "- Failed"
	fi
}

f1=`mktemp`
f2=`mktemp`
./generate $f1 1000
expect "generate file" 0

cp $f1 $f2

./compare $f1 $f2
expect "file is the same as its copy" 0

./mutate $f2
./compare $f1 $f2
expect "mutant copy isn't the same" 1

./shred $f1 $f2
expect "shredding files" 0

if ! [ -f $f1 ] && ! [ -f $f2 ]
then
	echo "files deleted - OK"
else
	echo "files deleted - Failed"
fi

# Clean up
rm -f $f1 $f2
