#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s,hours,minutes,seconds;
    cout<<"Nhap so giay: ";
    cin>>hours;
    seconds=hours%60;
    hours/=60;
    minutes=hours%60;
    hours/=60;
    cout<<"Dinh dang gio:phut:giay la: "<<hours<<":"<<minutes<<":"<<seconds;
    return 0;
}
