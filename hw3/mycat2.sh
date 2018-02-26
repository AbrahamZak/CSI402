#!/bin/bash
#check if there are 0 arguments
if [ $# -eq 0 ]  
    then
    #if true then print the following
    echo "Usage: mycat2.sh FILE ..."
    echo
    echo "Description: concatenates FILE(s) to standard output."
    #when done printing, exit 
    exit 1
 fi  

#Print text files listed in user arguments
#Loop for all arguments
for var in "$@"
do
#print the text in the file
cat "$var"
echo
done
