#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
    for (int i=2;i<=sqrt(n);i++)
        if (n%i==0)
            return 0;
    return 1;
}
int main()
{
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    for (int i=n+1;;i++)
        if (isPrime(i)){
            cout<<"So nguyen to nho nhat lon hon "<<n<<" la: "<<i;
            break;
        }
    return 0;
}
