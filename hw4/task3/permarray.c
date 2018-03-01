#include <stdio.h>
//Method for permutation of the elements of an array of integer values
int permute_array(int* arr, size_t len){
    int i;
    int temp;
    //Count (and place) of negative or 0 integers in array
    int negNumCount = 0;
    //First, sort through all 0 or below integers and move them to the front in their original order
    for (i = 0; i < len; i++){
        if (arr[i]<=0){
            temp = arr[negNumCount];
            arr[negNumCount] = arr[i];
            arr[i] = temp;
            negNumCount++;
        }
    }
    //Now, run a double loop to sort all other numbers in array in acending order
    int j;
    for (int i = negNumCount; i < len; i++)
    {
        for (j = negNumCount; j < len; j++)
        {
            if (arr[j] > arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    return 0;
}
