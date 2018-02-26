#!/bin/bash
#Print text files listed in user arguments
#Loop for all arguments
for var in "$@"
do
#print the text in the file
cat "$var"
echo
done
