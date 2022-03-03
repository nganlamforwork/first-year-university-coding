#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float a,b,c,delta,ans;

    cout<<"Nhap vao cac so a, b, c cua phuong trinh ax^2 + bx + c = 0: ";
    cin>>a>>b>>c;

    delta = b*b - 4*a*c;
    if (delta<0) cout<<"Phuong trinh vo nghiem";
    else if (delta==0) {
        ans=-b/(2*a);
        cout<<"Phuong trinh co nghiem kep la: "<<ans;
    }
    else{
        ans=(-b+sqrt(delta))/(2*a);
        cout<<"Phuong trinh co nghiem x1 la: "<<ans<<'\n';
        ans=(-b-sqrt(delta))/(2*a);
        cout<<"Phuong trinh co nghiem x2 la: "<<ans<<'\n';
    }
    return 0;
}
