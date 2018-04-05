#include <stdio.h>
#include "knapsack.h"

int main(int argc, char *argv[]) {
    //Create an empty knapsack and add values to it
    listitemptr k1 = NULL;
    k1 = KnapsackAdd(k1, 10);
    k1 = KnapsackAdd(k1, -20);
    k1 = KnapsackAdd(k1, 10);
    k1 = KnapsackAdd(k1, 15);
    k1 = KnapsackAdd(k1, -20);
    k1 = KnapsackAdd(k1, 10);
    KnapsackPrint(k1);
    
    printf("\n");
    
    //Print the 10 count, 8 count, and total size
    printf("%d\n\n", KnapsackItemCount(k1, 10));
    printf("%d\n\n", KnapsackItemCount(k1, 8));
    printf("%d\n", KnapsackSize(k1));
    
    //Create an empty knapsack and add values
    listitemptr k2 = NULL;
    k2 = KnapsackAdd(k2, 5);
    k2 = KnapsackAdd(k2, 10);
    k2 = KnapsackAdd(k2, 15);
    k2 = KnapsackAdd(k2, 20);
    k2 = KnapsackAdd(k2, -5);
    //Remove values
    k2 = KnapsackRemove(k2, 15);
    k2 = KnapsackRemove(k2, 10);
    
    //Add a value to the original
    k1 = KnapsackAdd(k1, 10);
    
    printf("\n");
    
    //Print the sizes
    printf("%d\n\n", KnapsackSize(k1));
    printf("%d\n\n", KnapsackSize(k2));
    
    //Print both knapsacks
    KnapsackPrint(k1);
    printf("\n");
    KnapsackPrint(k2);
    printf("\n");
    
    //Remove a value from k1 that has multiple count
    k1 = KnapsackRemove(k1, 10);
    //Print k1
    KnapsackPrint(k1);
    
    return 0;
}
