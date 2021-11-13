#include <iostream>

using namespace std;

int main()
{
    int km;
    float ans;
    cout<<"Nhap so km da di duoc: ";
    cin>>km;
    ans=15;
    if (km>=2){
        if (km<=5) ans+=13.5*(km-2+1);
        else ans+=13.5*4 + 11*(km-6+1);
    }
    if (km>120) ans=ans/100*90;
    cout<<"So tien phai tra la: "<<ans<<" dong";
    return 0;
}
