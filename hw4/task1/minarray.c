//The program outputs the minimum from a user inputted list of integers
#include <stdio.h>
#include <stdlib.h>
#define NUMBER_COUNT_MAX 100

size_t read_numbers(int numbers[], size_t n, int *minimum) {
    unsigned int i = 0;
    
    /* note that in Linux you can signal end of file/stream by key combination ctrl-d */
    //While i is less than 100 and the scanner hasn't reached EOF, continue incrementing i by 1 for each number inputted/counted
    //Flag for first number
    int firstNum = 0;
    while (i < n && scanf("%d", &numbers[i]) != EOF) {
        //If we're at the first number set the minimum to it
        if (firstNum == 0){
            *minimum = numbers[i];
            firstNum = 1;
        }
        //Otherwise check if the current numbers is less than the minimum
        else if (firstNum == 1 && numbers[i]<*minimum){
            //If it is update the minimum
            *minimum = numbers[i];
        }
        //Continue iteration
        i++;
    }
    
    return i;
}

int main(int argc, char *argv[]) {
    int numbers[NUMBER_COUNT_MAX];
    size_t numberlen;
    int min;
    
    numberlen = read_numbers(numbers, NUMBER_COUNT_MAX, &min);
    //If we have no inputs
    if (numberlen == 0){
        printf("no input numbers");
    }
    //Otherwise print the min
    else{
    printf("%d", min);
    }
    return 0;
}

