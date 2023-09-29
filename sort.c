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
Sort an array using the bubble sort algorithm
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
Sort an array using the bubble sort algorithm

I'm too high to learn how to do this rn
*/
void QuickSort(int *unsortedArray, int start, int end){

}

void PartitionArray(int *toPartition, int start, int end){

}


