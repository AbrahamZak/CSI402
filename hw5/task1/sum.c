/*Program which accepts multiple integer numbers as command line arguments
 and prints their total to the standard output.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    //Check if there are no numbers provided
    if (argc==0 | argc==1){
        printf("no input numbers");
        return 0;
    }
    //Setup for our loop
    int i;
    char value[10];
    char *ptr;
    long result [argc-1];
    //Loop through all arguments and convert each to a long and store in array result
    for (i=0; i<argc-1; i++){
        strcpy(value, argv[i+1]);
        result[i] = strtol(value, &ptr, 10);
    }
    //Loop through all values in our result array and add them
    long sum = 0;
    for (i=0; i<argc-1; i++){
        sum = sum + result[i];
    }
    //Print the sum
    printf("%ld", sum);
    
    return 0;
}
