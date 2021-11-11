#include <bits/stdc++.h>
using namespace std;

int main()
{
    double origin,ans;
    cout<<"Nhap gia tien san pham chua co gia tri thue gia tri gia tang VAT: ";
    cin>>origin;
    ans=origin/100.0*110.0;
    cout<<"Thanh tien san pham sau khi co VAT: "<<ans;
    return 0;
}
