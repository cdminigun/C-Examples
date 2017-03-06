/*****************************heapSort***************************
 *
 * A program to sort the elements of a heap from 1, 2, ..., n
 * where n is represented by ulTotalHeapSize.
 *
 * unsigned long ulTotalHeapSize    The total elements of the heap.
 *
 * float fHeapArray[]               A heap to be sorted by the algorithm. 
 *
 * ************************************************************/
void heapSort(unsigned long ulTotalHeapSize, float fHeapArray[])
{
    // Variables
    unsigned long ulIndexHiring, ulIndexRetire, j, i;
    float fTempHeap;

    // A heap of 0 and 1 trivially is sorted.
    if (ulTotalHeapSize < 2) return;
    // Set the values of hiring and retiring.
    ulIndexHiring=(ulTotalHeapSize >> 1)+1;
    ulIndexRetire = ulTotalHeapSize;
    while (1)
    {
        //Hiring phase where items are itterated through.
        if (ulIndexHiring > 1)
        {
            fTempHeap=fHeapArray[--ulIndexHiring];
        }
        // Retirement / promotion phase
        else
        {
            fTempHeap=fHeapArray[ulIndexRetire];  //Clears space at the end of the array
            fHeapArray[ulIndexRetire]=fHeapArray[1]; //Retire the top of the heap into it
            if (--ulIndexRetire == 1) //Done with the last promotion
            {
                fHeapArray[1] = fTempHeap; //Set the lowest value to the bottom. 
                break; //Exit the initial while loop.
            }
        }
        /******************************************************************
         * Whether in the hiring phase or the promotion phase, we are now 
         * going to set up the heap to sift down element fTempHeap to it's
         * propper value. 
         ******************************************************************/
        i=ulIndexHiring;
        j=ulIndexHiring+1;
        while (j <= ulIndexRetire) { //Itterate down the heap.
            if (j < ulIndexRetire && fHeapArray[j] < fHeapArray[j+1]) // Compare the better underling.
                j++;
            if (fTempHeap < fHeapArray[j]) //Demote fTempHeap
            {
                fHeapArray[i] = fHeapArray[j];
                    i=j;
                j <<=1;
            }
            else //Thiss is the level at which fTempHeap is going to reside.
                j=ulIndexRetire+1; //Set j to terminate the sift-down. 
        }
        fHeapArray[i] = fTempHeap; //Assign fTempHeap to it's spot in fHeapArray. 
    }
}
