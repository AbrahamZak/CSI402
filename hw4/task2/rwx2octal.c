#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    //Input array and our array for when we split the original
    char input [10];
    char inputSplit [3][3];
    //Get input and put into array
    fgets(input, 10, stdin);
    //Splits out array into 3 arrays of 3 characters each
    int i=0;
    for(int row=0; row < 3; row++)
    {
        for(int column=0;column < 3; column++, i++)
        {
            inputSplit[row][column] = input[i];
        }
    }
    //An int to keep octal count of current section
    int count=0;
    //Int array to keep all octals
    int totals [3];
    for(int row=0; row < 3; row++)
    {
        //If the first character is r or - we process it
        if (inputSplit[row][0] == 'r' | inputSplit[row][0] == '-'){
            //If the first character is r we add 4 to the count
            if (inputSplit[row][0] == 'r'){
            count = count + 4;
            }
        }
        //If there is no r or - we exit the program
        else{
            printf("invalid permission\n");
            exit(1);
        }
        //If the second character is w or - we process it
        if (inputSplit[row][1] == 'w'| inputSplit[row][1] == '-'){
            //If the second character is w we add 2 to the count
            if (inputSplit[row][1] == 'w'){
            count = count + 2;
            }
        }
        //If there is no w or - we exit the program
        else{
            printf("invalid permission\n");
            exit(1);
        }
        //If the third character is x or - we process it
        if (inputSplit[row][2] == 'x'| inputSplit[row][2] == '-'){
            //If the third character is x we add 1 to the count
            if (inputSplit[row][2] == 'x'){
            count = count + 1;
            }
        }
        //If there is no x or - we exit the program
        else{
            printf("invalid permission\n");
            exit(1);
        }
        //Add final octal to our array and reset the count int for our next set
        totals[row] = count;
        count = 0;
    }
    //Print the final octal
    printf ("%d%d%d\n", totals[0], totals[1], totals[2]);
    return 0;
}
