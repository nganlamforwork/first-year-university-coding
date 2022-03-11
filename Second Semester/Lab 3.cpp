#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
void swap(int* a, int* b)
{
    int * tmp = new int;
    *tmp = *a;
    *a = *b;
    *b = *tmp;
    delete tmp;
}
int* sum(int* a, int* b)
{
    int * ans = new int;
    *ans = *a + *b;
    return ans;
}
void inputArray(int* a, int &n)
{
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
}
void printArray(int* a, int n)
{
    for (int i=0;i<n;i++)
        cout<<a[i]<<' ';
}
int* findMax(int* arr, int n)
{
    int * ans = new int;
    *ans = 0;
    for (int i=0;i<n;i++)
        *ans = max(*ans,arr[i]);
    return ans;
}
int* copyArray(int* arr, int n)
{
    int * ans = new int[n];
    for (int i=0;i<n;i++)
        *(ans+i) = *(arr+i);
    return ans;
}
int* countEvens(int* arr, int n, int* evens)
{
    int *cnt = new int;
    *cnt = 0;
    for (int i=0;i<n;i++)
        if (arr[i]%2==0)
            evens[(*cnt)++]=arr[i];
    return cnt;
}
int* genEvenSubarray(int* arr, int n, int* count)
{
    int *ans = new int[n];
    for (int i=0;i<n;i++)
        if (arr[i]%2==0)
            ans[(*count)++]=arr[i];
    return ans;
}
int* findLargestTotalSubarray(int* a, int n, int &total, int &length)
{
    int * ans = new int[n]; //Init ans array
    for (int i=0;i<n;i++){
        int * tmpArr = new int[n]; //Init tmp array
        int tmp = 0; //Init tmp sum
        int cnt = 0; //Quantity of tmp array
        for (int j=i;j<n;j++){
            tmp+=a[j];
            tmpArr[++cnt]=a[j];
            if (tmp>total){
                total=tmp;
                ans=tmpArr;
                length = cnt;
            }
        }
        delete tmpArr;
    }
    return ans;
}
int* findLongestAscendingSubarray(int* a, int n, int &length)
{
    int * ans = new int[n]; //Init ans array
    int * tmp = new int[n];
    int cnt = 0;
    length = 1;
    tmp[cnt]=a[0];
    ans[length]=a[0];
    for (int i=0;i<n-1;i++)
        if (a[i]<=a[i+1]){
            tmp[++cnt]=a[i+1];
            if (cnt+1>length){
                length=cnt;
                ans=tmp;
            }
        }
        else{
            delete tmp;
            tmp = new int [n];
            cnt = 0;
            tmp[cnt]=a[0];
        }
    return ans;
}
void swapArrays(int* a, int* b, int &na, int &nb)
{
    int * tmp = new int[max(na,nb)];
    *tmp = *a;
    *a = *b;
    *b = *tmp;
    swap(na,nb);
}
int* concatenate2Arrays(int* a, int* b, int na, int nb)
{
    int * ans = new int[na+nb];
    for (int i=0;i<na;i++)
        ans[i]=a[i];
    for (int j=0;j<nb;j++)
        ans[na+j]=b[j];
    return ans;
}
int* merge2Arrays(int* a, int* b, int na, int nb, int&nc)
{
    nc=na+nb;
    int * ans = new int[nc];
    for (int i=0;i<na;i++)
        ans[i]=a[i];
    for (int j=0;j<nb;j++)
        ans[na+j]=b[j];
    sort(ans,ans+nc);
    return ans;
}
void generateMatrix1(int** A, int &length, int &width)
{
    srand(time(NULL));
//    length = rand()%10;
//    width = rand()%10;
    for (int i=0;i<length;i++)
        for (int j=0;j<width;j++)
            A[i][j] = rand()%100;

    //cout
    for (int i=0;i<length;i++){
        for (int j=0;j<width;j++)
            cout<<A[i][j]<<' ';
        cout<<'\n';
    }
}
int** generateMatrix2(int* a, int* b, int na, int nb)
{
    int **ans;
    ans = new int* [nb];
    for (int i=0;i<na;i++)
        for (int j=0;j<nb;j++)
            ans[i][j]=a[i]*b[j];
    return ans;
}
void swapRows(int** a, int length, int width)
{
    int *tmpRow1, *tmpRow2;
    tmpRow1 = a[0];
    tmpRow2 = a[1];

    //swap
    int *tmpRow = new int[length];
    *tmpRow = *tmpRow1;
    *tmpRow1 = *tmpRow2;
    *tmpRow2 = *tmpRow;
    //cout
    for (int i=0;i<length;i++){
        for (int j=0;j<width;j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
}
void swapColumns(int** a, int length, int width)
{

}
int** transposeMatrix(int** a, int length, int width) {
    for(int i=0; i<width; i++) {
        for(int j=0; j<length/2; j++) {
            int tmp = *(*(a+i)+j);
            *(*(a+i)+j) = *(*(a+i)+length-j-1);
            *(*(a+i)+length-j-1) = tmp;
        }
    }
    return a;
}
int main()
{
//    int a[20][20];
//    int n=5, m=6;
//    generateMatrix1((int**)a,n,m);
    //swapRows((int**)a,n,m);
    int a[]={1,2,3,4,5};
    int n=5;
    printArray(copyArray(a,n),n);
    return 0;
}
