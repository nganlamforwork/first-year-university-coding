#include <iostream>

using namespace std;
void setArray(int a[], int &n){
    cout<<"Nhap so phan tu cua mang: ";
    cin>>n;
    for (int i=1;i<=n;i++){
        cout<<"Nhap phan tu thu "<<i<<" cua mang: ";
        cin>>a[i];
    }
}
void printArray(int a[], int n){
    for (int i=1;i<=n;i++)
        cout<<"Phan tu thu "<<i<<" cua mang la: "<<a[i]<<'\n';
}
int sumArray(int a[], int n){
    int sum=0;
    for (int i=1;i<=n;i++) sum+=a[i];
    return sum;
}
int findMin(int a[], int n){
    int Min=a[1];
    for (int i=2;i<=n;i++) Min=min(Min,a[i]);
    return Min;
}
int checkPrime(int n){
    if (n<=1) return 0;
    for (int i=2;i*i<=n;i++)
        if (n%i==0) return 0;
    return 1;
}
int countNumberofPrime(int a[], int n){
    int cnt=0;
    for (int i=1;i<=n;i++)
        if (checkPrime(a[i])) cnt++;
    return cnt;
}
int isAscendingOrder(int a[],int n){
    for (int i=1;i<n;i++)
        if (a[i]>a[i+1]) return 0;
    return 1;
}
int countOccurrences(int a[], int n, int x){
    int cnt=0;
    for (int i=1;i<=n;i++)
        cnt+= (a[i]==x);
    return cnt;
}
void deleteItems(int a[], int&n, int x){
    int i=1;
    while (n>0 && i<=n){
        if (a[i]==x){
            for (int j=i;j<n;j++)
                a[j]=a[j+1];
            n--;
        }
        else i++;
    }
}
void deleteItemsFromIndex(int a[], int &n, int index, int no_items){
    for (int i=index;i<n;i++)
        a[i]=a[i+no_items];
    n-=no_items;
}
void concatTwoArrays(int a[], int n, int b[], int m, int c[]){
    for (int i=1;i<=n;i++)
        c[i]=a[i];
    for (int i=1;i<=m;i++)
        c[n+i]=b[i];
}
void concatInterspersedlyTwoArrays(int a[], int n, int b[], int m, int c[]){
    for (int i=1;i<=min(n,m);i++){
        c[i*2-1]=a[i];
        c[i*2]=b[i];
    }
    for (int i=min(n,m)+1, j=1;i<=n;i++, j++)
        c[min(n,m)*2+j]=a[i];
    for (int i=min(n,m)+1, j=1;i<=m;i++, j++)
        c[min(n,m)*2+j]=b[i];
}
int main()
{
    int a[10000],b[10000],c[10000],n,m;
    setArray(a,n);
    setArray(b,m);
    concatInterspersedlyTwoArrays(a,n,b,m,c);
    printArray(c,n+m);
    return 0;
}
