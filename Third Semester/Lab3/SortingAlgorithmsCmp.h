#include <iostream>

using namespace std;

long long selectionSortWithComparision(int a[], int n);

long long insertionSortWithComparision(int a[], int n);

long long bubbleSortWithComparision(int a[], int n);

long long shakerSortWithComparision(int a[], int n);

long long shellSortWithComparision(int a[], int n);

void heapifyWithComparision(int a[], int n, int i, long long& cmp);
long long heapSortWithComparision(int a[], int n);

long long mergeWithComparision(int a[], int left, int mid, int right);
long long mergeSortWithComparision(int a[], int left, int right);
long long mergeSortWithComparision(int a[], int n);

int partitionWithComparision(int a[], int low, int high, long long& cmp);
void quickSortWithComparision(int a[], int low, int high, long long& cmp);
long long quickSortWithComparision(int a[], int n);

long long countingSortWithComparision(int a[], int n);

int getMaxWithComparision(int a[], int n, long long& cmp);
void countSortWithComparision(int a[], int n, int exp, long long& cmp);
long long radixSortWithComparision(int a[], int n);

long long flashSortWithComparision(int a[], int n);

