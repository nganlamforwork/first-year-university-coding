#include <iostream>
#include <algorithm>
using namespace std;
int sum(int a[], int n, int id)
{
    if (id==0) return a[id];
    return a[id]+sum(a,n,id-1);
}
int factorial(int n)
{
    if (n==1) return 1;
    return factorial(n-1)*n;
}
int power(int x, int n)
{
    if (n==1) return x;
    if (n==0) return 1;
    if (n%2==0) return power(x,n/2)*power(x,n/2);
    return power(x,n/2)*power(x,n/2)*x;
}
int countDigits(int n)
{
    if (n<10) return n!=0;
    return countDigits(n/10)+1;
}
int countOddDigits(int n)
{
    if (n<10) return n!=0 && (n%2);
    return countOddDigits(n/10)+ ((n%10)%2);
}
bool verifyEven(int n)
{
    if (n<10) return n!=0 && (n%2==0);
    return verifyEven(n/10) && ((n%10)%2==0);
}
int GCD(int x, int y) {
    if (y == 0) return x;
    else return GCD(y, x % y);
}
int countDivisors(int n, int i)
{
    if (i==1) return 1;
    return countDivisors(n,i-1) + (n%i==0);
}
int countCommonDivisors(int x, int y)
{
    return countDivisors(GCD(x,y),GCD(x,y));
}
int reverseInteger(int n, int cur)
{
    if (n<10) return cur*10+n;
    cur = cur*10 + n%10;
    return reverseInteger(n/10,cur);
}
string findBinary(int n)
{
    if (n<2) return n ? "1" : "0";
    return findBinary(n/2) + (n%2 ? "1" : "0");
}
int fibonacci(int n)
{
    if (n==0) return 0;
    if (n==1) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}
void permutation(char a[], int n, int id, char ans[], bool check[])
{
    if (id==n) {
        cout<<ans<<'\n';
        return;
    }
    for (int i=0;i<n;i++)
        if (!check[i]){
            check[i]=1;
            ans[id]=a[i];
            permutation(a,n,id+1,ans,check);
            check[i]=0;
        }
}
int main()
{
    char a[] = "DBCA";
    char ans[] = "ABCD";
    bool check[] = {0,0,0,0};
    int n = 4;
    sort(a,a+n);
    permutation(a,4,0,ans,check);
    return 0;
}
