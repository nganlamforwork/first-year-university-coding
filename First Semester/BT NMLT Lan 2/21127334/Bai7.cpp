#include <iostream>

using namespace std;

int main()
{
    float a,b,c,theMin,theMax,theMiddle;

    cout<<"Nhap 3 so a, b, c: ";
    cin>>a>>b>>c;

    theMin=a;
    if (b<theMin) theMin=b;
    if (c<theMin) theMin=c;

    theMax=a;
    if (b>theMax) theMax=b;
    if (c>theMax) theMax=c;

    theMiddle = (a+b+c)-theMax-theMin;

    cout<<"So lon nhat: "<<theMax<<'\n';
    cout<<"So nho nhat: "<<theMin<<'\n';
    cout<<"3 so theo thu tu tang dan: ";
    cout<<theMin<<' '<<theMiddle<<' '<<theMax;

    return 0;
}
