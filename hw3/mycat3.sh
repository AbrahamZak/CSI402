#!/bin/bash
#check if there are 0 arguments
if [ $# -eq 0 ]  
    then
    #if true then print the following
    echo "Usage: mycat3 [-u|-l|-t] FILE ..."
    echo
    echo "Description: concatenates FILE(s) to standard output."
    #when done printing, exit 
    exit 1
 fi  
# if the flag is u, print the strings as uppercase
if [ "$1" == "-u" ]  
    then
    #Print text files listed in user arguments
    #Loop for all arguments starting from the second argument (the first is the flag)
    for var in "${@:2}"
    do
    #convert to uppercase and print the text in the file
    cat "$var" | tr '[:lower:]' '[:upper:]'
    echo
    done
    #when done printing, exit 
    exit 1
 fi  
# if the flag is l, print the strings as lowercase
if [ "$1" == "-l" ]  
    then
    #Print text files listed in user arguments
    #Loop for all arguments starting from the second argument (the first is the flag)
    for var in "${@:2}"
    do
    #convert to lowercase and print the text in the file
    cat "$var" | tr '[:upper:]' '[:lower:]'
    echo
    done
    #when done printing, exit 
    exit 1
 fi  
# if the flag is t, print the strings as initial caps
if [ "$1" == "-t" ]  
    then
    #Print text files listed in user arguments
    #Loop for all arguments starting from the second argument (the first is the flag)
    for var in "${@:2}"
    do
    #convert to initial caps and print the text in the file
    cat "$var" | awk '{for(i=1;i<=NF;i++){ $i=toupper(substr($i,1,1)) substr($i,2) }}1'
    echo
    done
    #when done printing, exit 
    exit 1
 fi  
#If there is no flag, print every argument
#Print text files listed in user arguments
#Loop for all arguments
for var in "$@"
do
#print the text in the file
cat "$var"
echo
done


