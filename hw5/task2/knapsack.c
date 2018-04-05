#include <stdio.h>
#include "knapsack.h"
#include <stdlib.h>

listitemptr KnapsackAdd(listitemptr knapsack, int item){
    //If the knapsack is empty set the first element and return
    if (knapsack == NULL){
        struct listitem *begin = (struct listitem*) malloc(sizeof(struct listitem));
        begin->count = 1;
        begin->item = item;
        knapsack = begin;
        knapsack->next = NULL;
        return knapsack;
    }
    //If the knapsack is not empty
    else{
        //Make a ptr to iterate the knapsack
        listitemptr ptr = knapsack;
        //Loop until we hit NULL
        while (ptr->next != NULL){
            //If we found an item match we add a count to it and return the knapsack
            if (ptr->item == item){
                ptr->count = ptr->count + 1;
                return knapsack;
            }
            //Otherwise we continue to iterate until we find it
            else{
                ptr = ptr->next;
            }
        }
        //If we don't find it we set the NULL element we are on to what needs to be added and return knapsack
        struct listitem *insert = (struct listitem*) malloc(sizeof(struct listitem));
        insert->count = 1;
        insert->item = item;
        ptr->next = insert;
        ptr->next->next=NULL;
        return knapsack;
    }
}

listitemptr KnapsackRemove(listitemptr knapsack, int item){
    //If knapsack is empty return it, nothing can be removed
    if (knapsack == NULL){
        return knapsack;
    }
    //Make a ptr to iterate the knapsack
    listitemptr ptr = knapsack;
    //Loop until we hit NULL
    while (ptr != NULL){
        //If we found the item and its count is above 1, lower the count and return knapsack
        if (ptr->item == item && ptr->count>1){
            ptr->count = ptr->count - 1;
            return knapsack;
        }
        //If we haven't found it, continue to iterate
        ptr = ptr->next;
    }
    //Now we check the knapsack to see if we have a match that has only 1 count
    //In this case we remove that item completely
    //Make a ptr to iterate the knapsack
    listitemptr ptrRemove = knapsack;
    listitemptr ptrPrev = NULL;
    //Loop until we hit NULL
    while (ptrRemove != NULL){
        //If we've found a match with a 1 count
        if (ptrRemove->item == item && ptrRemove->count==1){
            //If this is the only item in the list or the last item, set it to NULL and return knapsack
            if (ptrRemove->next == NULL){
                ptrRemove=NULL;
                return knapsack;
            }
            //If this item is between to items we delete it and set the link between previous and next items
            else{
                ptrPrev->next = ptrRemove->next;
                ptrRemove=NULL;
                return knapsack;
            }
        }
        ptrPrev = ptrRemove;
        ptrRemove = ptrRemove->next;
    }
    //In the case we find nothing to remove we just return knapsack
    return knapsack;
}

void KnapsackPrint(listitemptr knapsack){
    //If knapsack is empty
    if (knapsack == NULL){
        return;
    }

    //Start from the beginning and traverse the knapsack unril reaching NULL node (the end)
    while(knapsack != NULL) {
        printf("Item: %d, Count: %d\n",knapsack->item, knapsack->count);
        knapsack = knapsack->next;
    }
    return;
}

unsigned int KnapsackItemCount(listitemptr knapsack, int item){
    //If knapsack is empty
    if (knapsack == NULL){
        return 0;
    }
    //Start from the beginning and traverse the knapsack unril finding a match or reaching the end
    while(knapsack != NULL) {
        //If a match is found, return count
        if (knapsack->item == item){
            return knapsack->count;
        }
        knapsack = knapsack->next;
    }
    return 0;
}

unsigned int KnapsackSize(listitemptr knapsack){
    //If knapsack is empty
    if (knapsack == NULL){
        return 0;
    }
    int count = 0;
    //Start from the beginning and traverse the knapsack and count items until reaching the end
    while(knapsack != NULL) {
        count = count + knapsack->count;
        knapsack = knapsack->next;
    }
    return count;
}
