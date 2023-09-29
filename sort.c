/* 
Returns an array of randomized integers
given some length and maximum element size
*/
int *RandomizedIntegerArray(int arrayLength, int maxElementSize){
    // Alloc
    int *randomizedArray = (int *) malloc(arrayLength * sizeof(int));

    // Populate array
    for (int i = 0; i < arrayLength; i++){
        *(randomizedArray + i) = rand() % maxElementSize;
    }

    return randomizedArray;
}

/*
Recursively sort an array using the bubble sort algorithm
*/
void BubbleSort(int *unsortedArray, int arrayLength){
    // Guard
    if (arrayLength <= 1){return;}

    int swapCount;
    do{
        swapCount = 0;

        // Iterate through array
        for (int i = 0; i < arrayLength - 1; i++){
            int currentElement = *(unsortedArray + i);
            int nextElement = *(unsortedArray + i + 1);

            // Check current element against next element in the list
            if (currentElement > nextElement){
                // Swap elements
                *(unsortedArray + i) = nextElement;
                *(unsortedArray + i + 1) = currentElement;
                swapCount++;
            }
        }
    }while (swapCount > 0);
}

/*
Partitions array around a pivot, returns index of pivot value.
For use with QuickSort().
*/
int PartitionArray(int *toPartition, int start, int end){
    // Assign final element in partition as pivot
    int pivotValue = *(toPartition + end);

    // Swap elements in partition
    int forward, pivotTemp, swapTemp;
    pivotTemp = start - 1;

    for (forward = start; forward < end; forward++){
        if (*(toPartition + forward) >= pivotValue){continue;}

        // Swap
        pivotTemp++;
        swapTemp = *(toPartition + pivotTemp);
        *(toPartition + pivotTemp) = *(toPartition + forward);
        *(toPartition + forward) = swapTemp;
    }

    // Move pivot to final position
    pivotTemp++;
    swapTemp = *(toPartition + pivotTemp);
    *(toPartition + pivotTemp) = *(toPartition + end);
    *(toPartition + end) = swapTemp;

    return pivotTemp;
}

/*
Recursively sort an array using the quicksort algorithm.
When sorting an entire array, pass (length - 1) as end.
*/
void QuickSort(int *unsortedArray, int start, int end){
    if (start >= end || end < 0){return;}

    int partition = PartitionArray(unsortedArray, start, end);

    QuickSort(unsortedArray, start, partition - 1);
    QuickSort(unsortedArray, partition + 1, end);
}

/*
Checks if a given array is sorted.
Returns 0 if the list is sorted
Returns 1 if any element is found to be out of place.
*/
int CheckSorted(int *toCheck, int arrayLength){
    // Check if each element in the list is greater than the next
    // At each step, store the greatest value in the list, and check if the element is less than that
    int highest = *toCheck;

    for (int i = 0; i < arrayLength - 2; i++){
        if (*(toCheck + i) < highest){
            printf("\nThe list is not sorted.\n");
            return 1;
        }

        if (*(toCheck + i) > *(toCheck + i + 1)){
            printf("\nThe list is not sorted.\n");
            return 1; 
        }

        if (*(toCheck + i) > highest){
            highest = *(toCheck + i);
        }
    }

    // If we reach this point, the list is sorted.
    printf("\nThe list is sorted.\n");
    return 0;
}




