#include <bits/stdc++.h>
using namespace std;

int main()
{
    double m,D,ans;
    cout<<"Nhap khoi luong cua vat m (don vi kg): ";
    cin>>m;
    cout<<"Nhap khoi luong rieng cua vat D (don vi kg/m2): ";
    cin>>D;
    ans=m/D;
    cout<<"The tich cua vat la: "<<ans<<" m3";
    return 0;
}
