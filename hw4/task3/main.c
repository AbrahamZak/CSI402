#include <stdio.h>
#include <stdlib.h>
#define NUMBER_COUNT_MAX 100
int permute_array(int* arr, size_t len);

size_t read_numbers(int numbers[], size_t n) {
    unsigned int i = 0;
    
    /* note that in Linux you can signal end of file/stream by key combination ctrl-d */
    //While i is less than 100 and the scanner hasn't reached EOF, continue incrementing i by 1 for each number inputted/counted
    while (i < n && scanf("%d", &numbers[i]) != EOF) {
        i++;
    }
    return i;
}

int main(int argc, char *argv[]) {
    int numbers[NUMBER_COUNT_MAX];
    size_t numberlen;
    
    //Read user input and store in array
    numberlen = read_numbers(numbers, NUMBER_COUNT_MAX);
    
    if (numberlen==0){
        printf("no input numbers");
        return 0;
    }
    //Permute the array
    permute_array(numbers, numberlen);
    
    //Print the resulting array
    int i;
    for (i = 0; i < numberlen; i++){
         if (i==numberlen-1){
            printf("%d", numbers[i]);
        }
        else {
            printf("%d ", numbers[i]);
        }
}
     return 0;
}


