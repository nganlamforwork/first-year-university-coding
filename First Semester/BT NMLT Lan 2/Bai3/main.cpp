#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    if (sqrt(n)*sqrt(n) != n) cout<<"Khong la so chinh phuong";
    else cout<<"La so chinh phuong";
    return 0;
}
