#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "search.c"
#include "sort.c"

int main(){
    srand(time(NULL));
    const int length, max;
    int search;
    
    // Declare Parameters
    printf("Array Length: ");
    scanf("%i", &length);
    printf("Max Element Size: ");
    scanf("%i", &max);

    // Store and display sorted list
    int *p_array = RandomizedIntegerArray(length, max);
    BubbleSort(p_array, length);

    printf("\nSorted Array: ");
    for (int i = 0; i < length; i++){
        printf("%i ", *(p_array + i));
    }

    // Search for a given element
    printf("\nElement to Search: ");
    scanf("%i", &search);

    BinarySearch(p_array, search, 0, length - 1);
    
    free(p_array);
    return 0;
}