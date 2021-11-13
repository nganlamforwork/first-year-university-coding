#include <iostream>

using namespace std;

void extendedEuclid(int A, int B, int &x, int &y, int &ans) {
    if (B==0) {
        ans=A;
        x=1;
        y=0;
    }
    else {
        extendedEuclid(B,A%B,x,y,ans);
        int tmp=x;
        x=y;
        y=tmp-(A/B)*y;
    }
}
int main()
{
    int a,b,x,y,ans;
    cout<<"Chuong trinh tim UCLN cua 2 so a va b!\n";
    cout<<"Nhap a: ";
    cin>>a;
    cout<<"Nhap b: ";
    cin>>b;

    extendedEuclid(a,b,x,y,ans);
8
48

    cout<<"UCLN cua "<<a<<" va "<<b<<" la: "<<ans<<'\n';
    cout<<"Hai so nguyen x va y thoa man UCLN(a,b) = a*x + b*y la:\n";
    cout<<"x = "<<x<<"\ny = "<<y<<'\n';
    cout<<"BCNN cua "<<a<<" va "<<b<<" la: "<<a*b/ans<<'\n';
    return 0;
}
