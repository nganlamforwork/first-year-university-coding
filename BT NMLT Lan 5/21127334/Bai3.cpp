#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 100001;
void set2dArray(int a[][MAX], int m, int n){
    cout<<"Nhap mang m dong n cot:\n";
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
}
void print2dArray(int a[][MAX], int m, int n){
    cout<<"Mang m dong n cot:\n";
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
}
int sumArray(int a[][MAX], int m, int n){
    int sum=0;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            sum+=a[i][j];
    return sum;
}
int sumDiagonal(int a[][MAX], int m, int n){
    int sum=0;
    for (int i=1;i<=m;i++)
        sum+=a[i][i];
    return sum;
}
int findMin(int a[][MAX], int m, int n){
    int Min=a[1][1];
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            Min=min(Min,a[i][j]);
    return Min;
}
bool isPrime(int n){
    if (n<=1) return 0;
    for (int i=2;i*i<=n;i++)
        if (n%i==0) return 0;
    return 1;
}
int countNumberofPrime(int a[][MAX], int m, int n){
    int cnt=0;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            if (isPrime(a[i][j])) cnt++;
    return cnt;
}
void deleteItems(int a[][MAX], int &m, int &n){

}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
