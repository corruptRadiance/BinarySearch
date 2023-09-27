#include <math.h>

/*
Search a sorted array for a given integer using binary search.
If given integer is found, returns index position of the stored integer
If given integer is not in the list, returns -1 (aka an impossible index)
*/
int BinarySearch(int *sortedArray, int numToSearch, int start, int end){
    // Guard
    if (start > end){
        printf("Number not found.\n");
        return -1;
    }

    // Find middle element
    int middle = floor((start + end) / 2);

    // Compare
    if (*(sortedArray + middle) == numToSearch){
        printf("Integer [%i] found at array index [%i].\n", numToSearch, middle);

        // Recursion should end here
        return middle;
    }

    if (*(sortedArray + middle) < numToSearch){
        return BinarySearch(sortedArray, numToSearch, middle + 1, end);
    }

    if (*(sortedArray + middle) > numToSearch){
        return BinarySearch(sortedArray, numToSearch, start, middle - 1);
    }
}


