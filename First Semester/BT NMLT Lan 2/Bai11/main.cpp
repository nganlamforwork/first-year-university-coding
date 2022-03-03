#include <iostream>

using namespace std;

int main()
{
    float x,ans;
    cout<<"Nhap so km vuot toc do cho phep: ";
    cin>>x;

    ans=0;
    if (x>5 && x<=10) ans=0.7;
    else if (x>10 && x<=20) ans=2.5;
    else if (x>20 && x<=35) ans=5.5;
    else if (x>35) ans=7.5;

    cout<<"So tien phat la: "<<ans;
    return 0;
}
