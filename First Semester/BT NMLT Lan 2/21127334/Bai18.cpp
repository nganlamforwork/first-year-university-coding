#include <iostream>

using namespace std;

int main()
{
    float w,h,bmi;
    cout<<"Nhap can nang (don vi kg): ";
    cin>>w;
    cout<<"Nhap chieu cao (don vi m): ";
    cin>>h;

    bmi=w/(h*h);

    if (bmi<18.5) cout<<"Duoi chuan";
    else if (bmi>=18.5&&bmi<25) cout<<"Chuan";
    else if (bmi>=25&&bmi<30) cout<<"Thua can";
    else if (bmi>=30&&bmi<40) cout<<"Beo - nen giam can";
    else cout<<"Rat bep - can giam can ngay";
    return 0;
}
