#include <iostream>
#include <math.h>
using namespace std;
void inputArray(float A[], int n)
{
    for (int i=1;i<=n;i++)
        cin>>A[i];
}
void printArray(float A[], int n)
{
    for (int i=1;i<=n;i++)
        cout<<A[i];
}
bool isPrime(int a)
{
    if (a<2) return 0;
    for (int i=2;i<=(int)sqrt(a);i++)
        if (a%i==0) return 0;
    return 1;
}
int countArrayPrime(int A[], int n)
{
    int ans=0;
    for (int i=1;i<=n;i++)
        if (isPrime(A[i]))
            ans++;
    return ans;
}
float sumArray(float A[], int n)
{
    float ans=0;
    for (int i=1;i<=n;i++)
        ans+=A[i];
    return ans;
}
bool isIncreasing(float A[], int n)
{
    for (int i=1;i<n;i++)
        if (A[i]>A[i+1])
            return 0;
    return 1;
}
bool isDecreasing(float A[], int n)
{
    for (int i=1;i<n;i++)
        if (A[i]<A[i+1])
            return 0;
    return 1;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
