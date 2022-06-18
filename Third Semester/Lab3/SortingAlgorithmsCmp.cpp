#include "SortingAlgorithms.h"

//------------------------SELECTION SORT------------------------
long long selectionSortWithComparision(int a[], int n)
{
    long long cmp = 0;
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
long long insertionSortWithComparision(int a[], int n)
{
    long long cmp = 0;
    for (int i = 0; i < n; i++, ++cmp) {
        int cur = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > cur) {
            a[j + 1] = a[j];
            j--;
            cmp += 2;
        };

        a[j + 1] = cur;
    };
    return cmp;
}


//------------------------BUBBLE SORT------------------------
long long bubbleSortWithComparision(int a[], int n)
{
	long long cmp = 0;
	int count;
	for (int i = 0; i < n - 1; i++, cmp++) {
		count = 0;
		for (int j = n - 1; j >= i; j--, cmp++) {
			if (a[j] < a[j - 1] && cmp++) {
				swap(a[j], a[j - 1]);
				count++;
			}
		}
		if (count == 0 && cmp++)
			return cmp;
	}
    return cmp;
}


//------------------------SHAKER SORT------------------------
long long shakerSortWithComparision(int a[], int n)
{
	long long cmp = 0;
	int L = 0, R = n - 1;
	for (int i = L; i <= R; i++, cmp++) {
		for (int j = R; j >= i; j--, cmp++) {
			swap(a[j], a[j - 1]);
		}
		L++;
		for (int j = L; j <= R; j++, cmp++) {
			if (a[j] > a[j + 1] && cmp++)
				swap(a[j], a[j + 1]);
		}
		R--;
	}
    return cmp;
}



//------------------------SHELL SORT------------------------
long long shellSortWithComparision(int a[], int n)
{
    long long cmp = 0;
    for (int gap = n/2; gap > 0; gap /= 2, cmp++){
        for (int i = gap; i < n; i += 1, cmp++){
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap, cmp+=2 )
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }
    return cmp;
}


//------------------------HEAP SORT------------------------
void heapifyWithComparision(int a[], int n, int i, long long &cmp)
{
    cmp += 5;
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapifyWithComparision(a, n, largest, cmp);
    }
}
long long heapSortWithComparision(int a[], int n)
{
    long long cmp = 0;
    for (int i = n / 2 - 1; i >= 0; i--, cmp++)
        heapifyWithComparision(a, n, i, cmp);
    for (int i = n - 1; i > 0; i--, cmp++) {
        swap(a[0], a[i]);
        heapifyWithComparision(a, i, 0, cmp);
    }
    return cmp;
}


//------------------------MERGE SORT------------------------
long long mergeWithComparision(int a[], int left, int mid, int right){
    long long cmp = 0;
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
long long mergeSortWithComparision(int a[], int left, int right)
{
    long long cmp = 0;
    if (++cmp && left >= right)
        return cmp;
    int mid = left + (right - left) / 2;
    long long cmpInLeft = mergeSortWithComparision(a,left, mid);
    long long cmpInRight = mergeSortWithComparision(a,mid+1, right);
    long long cmpInMerge = mergeWithComparision(a,left, mid, right);
    return cmp + cmpInLeft + cmpInRight + cmpInMerge;
}
long long mergeSortWithComparision(int a[], int n)
{
    return mergeSortWithComparision(a,0,n-1);
}


//------------------------QUICK SORT------------------------
int partitionWithComparision(int a[], int low, int high, long long& cmp)
{
    int mid = low + (high - low) / 2;
    if (a[low] > a[mid] && a[mid] > a[high])
        swap(a[low], a[mid]), cmp += 2;
    else if (a[low] > a[high] && a[high] > a[mid])
        swap(a[low], a[high]), cmp += 2;
    else if (a[mid] > a[high] && a[high] < a[low])
        swap(a[high], a[low]), cmp += 2;
    else if (a[high] > a[mid] && a[mid] > a[low])
        swap(a[mid], a[low]), cmp += 2;

    int first = low, last = high;
    int pivot = a[first];
    int last1 = first;
    int first_unknown = first + 1;
    while (first_unknown <= last && ++cmp) {
        if (a[first_unknown] < pivot && ++cmp) {
            swap(a[first_unknown], a[last1 + 1]);
            last1++;
            first_unknown++;
        }
        else first_unknown++;
    }
    swap(a[first], a[last1]);
    return last1;
};
void quickSortWithComparision(int a[], int low, int high, long long& cmp)
{
    if (low < high && ++cmp) {
        int pivot = partitionWithComparision(a, low, high, cmp);
        quickSortWithComparision(a, low, pivot - 1, cmp);
        quickSortWithComparision(a, pivot + 1, high, cmp);
    }
}
long long quickSortWithComparision(int a[], int n)
{
    long long cmp = 0;
    quickSortWithComparision(a, 0, n - 1, cmp);
    return cmp;
}


//------------------------COUNTING SORT------------------------
long long countingSortWithComparision(int a[], int n)
{
    long long cmp = 0;
    int Max = a[0], Min = a[0];
    for (int i = 0; i < n; i++, ++cmp) {
        if (Max < a[i] && ++cmp) Max = a[i];
        if (Min > a[i] && ++cmp) Min = a[i];
    };

    int range = Max - Min + 1;
    int* cntArr = new int[range];

    fill_n(cntArr, range, 0);

    for (int i = 0; i < n; i++, ++cmp)
        cntArr[a[i] - Min]++;

    for (int i = 1; i < range; i++, ++cmp)
        cntArr[i] += cntArr[i - 1];

    int* b = new int[n];
    for (int i = 0; i < n; i++, ++cmp) {
        b[cntArr[a[i] - Min] - 1] = a[i];
        cntArr[a[i] - Min]--;
    };

    for (int i = 0; i < n; i++, ++cmp)
        a[i] = b[i];
    
    return cmp;
}


//------------------------RADIX SORT------------------------
int getMaxWithComparision(int a[], int n, long long& cmp) {
    int max = a[0];
    for (int i = 0; i < n; i++, ++cmp)
        if (a[i] > max && ++cmp)
            max = a[i];
    return max;
}
void countSortWithComparision(int a[], int n, int exp, long long& cmp) {

    int* output = new int[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++, ++cmp)
        count[(a[i] / exp) % 10]++;
    for (i = 1; i < 10; i++, ++cmp)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--, ++cmp) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++, ++cmp)
        a[i] = output[i];
}
long long radixSortWithComparision(int a[], int n) {
    long long cmp = 0;
    int MAX = getMaxWithComparision(a, n, cmp);
    for (int exp = 1; MAX / exp > 0; exp *= 10, ++cmp)
        countSortWithComparision(a, n, exp, cmp);
    return cmp;
}

//------------------------FLASH SORT------------------------
long long flashSortWithComparision(int a[], int n)
{
    long long cmp = 0;
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

