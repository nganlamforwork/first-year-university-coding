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
void insertionSort(int a[], int n)
{
    for (int i = 0; i < n; i++){
        int cur = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > cur){
            a[j + 1] = a[j];
            j--;
        };

        a[j + 1] = cur;
    };
}

//------------------------BUBBLE SORT------------------------
void bubbleSort(int a[], int n) 
{
	int count;
	for (int i = 0; i < n - 1; i++) {
		count = 0;
		for (int j = n - 1; j >= i; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				count++;
			}
		}
		if (count == 0)
			return;
	}
}

//------------------------SHAKER SORT------------------------
void shakerSort(int a[], int n) {
	int L = 0, R = n - 1;
	for (int i = L; i <= R; i++) {
		for (int j = R; j >= i; j--) {
			swap(a[j], a[j - 1]);
		}
		L++;
		for (int j = L; j <= R; j++) {
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
		R--;
	}
}

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
int partition(int a[], int low, int high)
{
    int mid = low + (high - low) / 2;
    if (a[low] > a[mid] && a[mid] > a[high])
        swap(a[low], a[mid]);
    else if (a[low] > a[high] && a[high] > a[mid])
        swap(a[low], a[high]);
    else if (a[mid] > a[high] && a[high] < a[low])
        swap(a[high], a[low]);
    else if (a[high] > a[mid] && a[mid] > a[low])
        swap(a[mid], a[low]);

    int first = low, last = high;
    int pivot = a[first];
    int last1 = first;
    int first_unknown = first + 1;
    while (first_unknown <= last){
        if (a[first_unknown] < pivot){
            swap(a[first_unknown], a[last1 + 1]);
            last1++;
            first_unknown++;
        }
        else first_unknown++;
    }
    swap(a[first], a[last1]);
    return last1;
};
void quickSort(int a[], int low, int high)
{
    if (low < high){
        int pivot = partition(a, low, high);
        quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
    }
}
void quickSort(int a[], int n)
{
    quickSort(a, 0, n - 1);
}

//------------------------COUNTING SORT------------------------
void countingSort(int a[], int n)
{
    int Max = a[0], Min = a[0];
    for (int i = 0; i < n; i++){
        if (Max < a[i]) Max = a[i];
        if (Min > a[i]) Min = a[i];
    };

    int range = Max - Min + 1;
    int* cntArr = new int [range];

    fill_n(cntArr, range, 0);

    for (int i = 0; i < n; i++)
        cntArr[a[i] - Min]++;

    for (int i = 1; i < range; i++)
        cntArr[i] += cntArr[i - 1];

    int* b = new int [n];
    for (int i = 0; i < n; i++){
        b[cntArr[a[i] - Min] - 1] = a[i];
        cntArr[a[i] - Min]--;
    };

    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

//------------------------RADIX SORT------------------------
int getMax(int a[], int n) {
    int max = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}
void countSort(int a[], int n, int exp) {

    int* output = new int[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        a[i] = output[i];
}
void radixSort(int a[], int n) {
    int MAX = getMax(a, n);
    for (int exp = 1; MAX / exp > 0; exp *= 10)
        countSort(a, n, exp);
}

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

