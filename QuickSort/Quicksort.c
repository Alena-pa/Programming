void swap(int* left, int* right)
{
    int justVar = *right;
    if (left != right)
    {
        *right = *left;
        *left = justVar;
    }
}

int partition(int arrayOfIntegers[], int firstIndex, int lastIndex)
{
    int pivot = arrayOfIntegers[lastIndex];
    int i = (firstIndex - 1);
    for (int j = firstIndex; j < lastIndex; j++)
    {
        if (arrayOfIntegers[j] <= pivot)
        {
            i++;
            swap(&arrayOfIntegers[i], &arrayOfIntegers[lastIndex]);
        }
    }
    swap(&arrayOfIntegers[i + 1], &arrayOfIntegers[lastIndex]);
    return (i + 1);
}

void quickSort(int arrayOfIntegers[], int firstIndex, int lastIndex)
{
    if (lastIndex > firstIndex)
    {
        int indexOfPivot = partition(arrayOfIntegers, firstIndex, lastIndex);
        quickSort(arrayOfIntegers, firstIndex, indexOfPivot - 1);
        quickSort(arrayOfIntegers, indexOfPivot + 1, lastIndex);
    }
}