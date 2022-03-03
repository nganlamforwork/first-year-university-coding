#include <iostream>

using namespace std;

int main()
{
    int n, odd=0, even=0;
    cout<<"Nhap vao so nguyen duong n: ";
    cin>>n;
    cout<<"So nguoc lai la: ";
    while (n){
        int x=n%10;
        cout<<x;
        n/=10;
        if (x%2) odd++;
        else even++;
    }
    cout<<"\nSo luong chu so chan la: "<<even;
    cout<<"\nSo luong chu so le la: "<<odd;
    return 0;
}
