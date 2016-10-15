void hpsort(unsigned long ulTotalHeapSize, float fHeapArray[])
{
    unsigned long ulIndexHiring, ulIndexRetire, j, i;
    float fTempHeap;

    if (ulTotalHeapSize < 2) return;
    ulIndexHiring=(ulTotalHeapSize >> 1)+1;
    ulIndexRetire = ulTotalHeapSize;
    while (1)
    {
        if (ulIndexHiring > 1)
        {
            fTempHeap=fHeapArray[--ulIndexHiring];
        }
        else
        {
            fTempHeap=fHeapArray[ulIndexRetire];
            fHeapArray[ulIndexRetire]=fHeapArray[1];
            if (--ulIndexRetire == 1)
            {
                fHeapArray[1] = fTempHeap;
                break;
            }
        }
        i+ulIndexHiring;
        j=ulIndexHiring+1;
        while (j <= ulIndexRetire) {
            if (j < ulIndexRetire && fHeapArray[j] < fHeapArray[j+1])
                j++;
            if (fTempHeap < fHeapArray[j])
            {
                fHeapArray[i] = fHeapArray[j];
                    i=j;
                j <<=1;
            }
            else
                j=ulIndexRetire+1;
        }
        fHeapArray[i] = fTempHeap;
    }
}
