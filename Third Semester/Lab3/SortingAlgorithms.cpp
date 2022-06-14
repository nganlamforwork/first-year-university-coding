#include "SortingAlgorithms.h"

//------------------------SELECTION SORT------------------------
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n-1; i++){
        int minIndex = i;
        for (int j = i + 1; j < n; j++){
            if (a[minIndex] > a[j])
                minIndex = j;
        }
        swap(a[minIndex], a[i]);
    }
}

//------------------------INSERTION SORT------------------------
void insertionSort(int a[], int n){}

//------------------------BUBBLE SORT------------------------
void bubbleSort(int a[], int n){}

//------------------------SHAKER SORT------------------------
void shakerSort(int a[], int n){}

//------------------------SHELL SORT------------------------
void shellSort(int a[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i += 1){
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }
}

//------------------------HEAP SORT------------------------
void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

//------------------------MERGE SORT------------------------
void merge(int a[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftSubarray = new int[n1];
    int *rightSubarray = new int[n2];

    for (int i = 0; i < n1; i++)
        leftSubarray[i] = a[left + i];
    for (int i = 0; i < n2; i++)
        rightSubarray[i] = a[mid + 1 + i];

    int indexOfMergeArray = left;
    int i = 0;
    int j = 0;
    for ( ; i < n1 && j < n2; indexOfMergeArray++){
        if (leftSubarray[i] < rightSubarray[j])
            a[indexOfMergeArray] = leftSubarray[i++];
        else
            a[indexOfMergeArray] = rightSubarray[j++];
    }

    while (i < n1)
        a[indexOfMergeArray++] = leftSubarray[i++];
    while (j < n2)
        a[indexOfMergeArray++] = rightSubarray[j++];

    delete [] leftSubarray;
    delete [] rightSubarray;
}
void mergeSort(int a[], int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(a,left, mid);
    mergeSort(a,mid+1, right);
    merge(a,left, mid, right);
}
void mergeSort(int a[], int n)
{
    mergeSort(a,0,n-1);
}


//------------------------QUICK SORT------------------------
void quickSort(int a[], int n){}


//------------------------COUNTING SORT------------------------
void countingSort(int a[], int n){}

//------------------------RADIX SORT------------------------
void radixSort(int a[], int n){}

//------------------------FLASH SORT------------------------
void flashSort(int a[], int n){
    int numberOfGroups = n * 0.45;
    int *groups = new int [numberOfGroups];
    for (int i = 0; i < numberOfGroups; i++)
        groups[i] = 0;

    int min, max;
    min = max = a[0];
    for (int i = 1; i < n; i++){
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }

    #define groupOf(x) int((numberOfGroups - 1) * (x - min)/ (max - min))

    for (int i = 0; i < n; i++)
        ++groups[groupOf(a[i])];

    for (int i = 1; i < numberOfGroups; i++)
        groups[i] += groups[i-1];

    int numOfSwap = 0;
    int flash, i = 0, k = 0;

    while (numOfSwap < n-1){
        while (i > groups[k]-1)
            k = groupOf(a[++i]);

        flash = a[i];
        while (i != groups[k]){
            k = groupOf(flash);
            groups[k]--;
            swap(flash, a[groups[k]]);
            numOfSwap++;
        }
    }

    for (int j = 1; j < numOfSwap; j++){
        int key = a[j];
        int l = j-1;
        for ( ; a[l] > key && l >= 0; l--)
            a[l+1] = a[l];
        a[l+1] = key;
    }
    delete [] groups;
}

