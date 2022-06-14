#include "SortingAlgorithms.h"

//------------------------SELECTION SORT------------------------
int selectionSortWithComparision(int a[], int n)
{
    int cmp = 0;
    for (int i = 0; ++cmp && i < n-1; i++){
        int minIndex = i;
        for (int j = i + 1; ++cmp && j < n; j++){
            if (++cmp && a[minIndex] > a[j])
                minIndex = j;
        }
        swap(a[minIndex], a[i]);
    }
    return cmp;
}


//------------------------INSERTION SORT------------------------
int insertionSortWithComparision(int a[], int n){return -1;}


//------------------------BUBBLE SORT------------------------
int bubbleSortWithComparision(int a[], int n){return -1;}


//------------------------SHAKER SORT------------------------
int shakerSortWithComparision(int a[], int n){return -1;}


//------------------------SHELL SORT------------------------
int shellSortWithComparision(int a[], int n)
{
    int cntComparision = 0;
    for (int gap = n/2; gap > 0; gap /= 2, cntComparision++){
        for (int i = gap; i < n; i += 1, cntComparision++){
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap, cntComparision+=2 )
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }
    return cntComparision;
}


//------------------------HEAP SORT------------------------
void heapifyWithComparision(int a[], int n, int i, int &cntComparision)
{
    cntComparision+=5;
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapifyWithComparision(a, n, largest,cntComparision);
    }
}

int heapSortWithComparision(int a[], int n)
{
    int cntComparision = 0;
    for (int i = n / 2 - 1; i >= 0; i--, cntComparision++)
        heapifyWithComparision(a, n, i, cntComparision);
    for (int i = n - 1; i > 0; i--, cntComparision++) {
        swap(a[0], a[i]);
        heapifyWithComparision(a, i, 0, cntComparision);
    }
    return cntComparision;
}


//------------------------MERGE SORT------------------------
int mergeWithComparision(int a[], int left, int mid, int right){
    int cmp = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftSubarray = new int[n1];
    int *rightSubarray = new int[n2];

    for (int i = 0; ++cmp && i < n1; i++)
        leftSubarray[i] = a[left + i];
    for (int i = 0; ++cmp && i < n2; i++)
        rightSubarray[i] = a[mid + 1 + i];

    int indexOfMergeArray = left;
    int i = 0;
    int j = 0;
    for ( ; ++cmp && i < n1 && ++cmp && j < n2; indexOfMergeArray++){
        if (++cmp && leftSubarray[i] < rightSubarray[j])
            a[indexOfMergeArray] = leftSubarray[i++];
        else
            a[indexOfMergeArray] = rightSubarray[j++];
    }

    while (++cmp && i < n1)
        a[indexOfMergeArray++] = leftSubarray[i++];
    while (++cmp && j < n2)
        a[indexOfMergeArray++] = rightSubarray[j++];

    delete[] leftSubarray;
    delete[] rightSubarray;

    return cmp;
}
int mergeSortWithComparision(int a[], int left, int right)
{
    int cmp = 0;
    if (++cmp && left >= right)
        return cmp;
    int mid = left + (right - left) / 2;
    int cmpInLeft = mergeSortWithComparision(a,left, mid);
    int cmpInRight = mergeSortWithComparision(a,mid+1, right);
    int cmpInMerge = mergeWithComparision(a,left, mid, right);
    return cmp + cmpInLeft + cmpInRight + cmpInMerge;
}
int mergeSortWithComparision(int a[], int n)
{
    return mergeSortWithComparision(a,0,n-1);
}


//------------------------QUICK SORT------------------------
int quickSortWithComparision(int a[], int n){return -1;}


//------------------------COUNTING SORT------------------------
int countingSortWithComparision(int a[], int n){return -1;}

//------------------------RADIX SORT------------------------
int radixSortWithComparision(int a[], int n){return -1;}

//------------------------FLASH SORT------------------------
int flashSortWithComparision(int a[], int n)
{
    int cmp = 0;
    int numberOfGroups = n * 0.45;
    int *groups = new int [numberOfGroups];
    for (int i = 0; ++cmp && i < numberOfGroups; i++)
        groups[i] = 0;

    int min, max;
    min = max = a[0];
    for (int i = 1; ++cmp && i < n; i++){
        if (++cmp && a[i] < min)
            min = a[i];
        if (++cmp && a[i] > max)
            max = a[i];
    }

    #define groupOf(x) int((numberOfGroups - 1) * (x - min)/ (max - min))

    for (int i = 0; ++cmp && i < n; i++)
        ++groups[groupOf(a[i])];
    for (int i = 1; ++cmp && i < numberOfGroups; i++)
        groups[i] += groups[i-1];

    int numOfSwap = 0;
    int flash;
    int i = 0;
    int k = 0;
    while (++cmp && numOfSwap < n-1){
        while (++cmp && i > groups[k]-1)
            k = groupOf(a[++i]);

        flash = a[i];
        while (++cmp && i != groups[k]){
            k = groupOf(flash);
            groups[k]--;
            swap(flash, a[groups[k]]);
            numOfSwap++;
        }
    }

    for (int j = 1; ++cmp && j < numOfSwap; j++){
        int key = a[j];
        int l = j-1;
        for ( ; ++cmp && a[l] > key && ++cmp && l >= 0; l--)
            a[l+1] = a[l];
        a[l+1] = key;
    }
    delete [] groups;
    return cmp;
}

