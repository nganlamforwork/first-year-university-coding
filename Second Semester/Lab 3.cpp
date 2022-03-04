#include <iostream>
#include <cstdio>

using namespace std;
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int* sum(int* a, int* b)
{
    int ans = *a + *b;
    int *ans2 = &ans;
    return ans2;
}
void inputArray(int* a, int &n)
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
}
void printArray(int* a, int n)
{
    for (int i=1;i<=n;i++)
        cout<<a[i]<<' ';
}
int* findMax(int* arr, int n)
{
    int *themax = 0;
    for (int i=1;i<=n;i++)
        if (arr[i]>*themax)
            *themax = arr[i];
    return themax;
}
int* copyArray(int* arr, int n)
{
    int *b = arr;
    return b;
}
int* countEvens(int* arr, int n, int *evens)
{
    int ans = 0;
    for (int i=1;i<=n;i++)
        if (arr[i]%2==0){
            evens[++ans] = arr[i];
        }
    printArray(arr,5);
    int *ans2 = &ans;
    return ans2;
}
int* genEvenSubarray(int* arr, int n, int* count)
{
    int b[n+1];
    *count = 0;
    for (int i=1;i<=n;i++)
        if (arr[i]%2==0){
            evens[++ans] = arr[i];
        }
    return b;
}
int main()
{
    int a[6]={0,1,2,3,5,6}, b[6]={};
    return 0;
}
