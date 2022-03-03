#include <iostream>

using namespace std;

int main()
{
    int h,m,s;
    cout << "Nhap gio: ";
    cin>>h;
    cout << "Nhap phut: ";
    cin>>m;
    cout << "Nhap giay: ";
    cin>>s;

    if (s>=60 || m>=60 || h>=24 || s<0 || m<0 || h<0) cout<<"Khong hop le!";
    else cout<<"Hop le!";
    return 0;
}
