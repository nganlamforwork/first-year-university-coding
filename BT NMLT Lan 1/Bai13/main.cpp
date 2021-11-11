#include <bits/stdc++.h>
using namespace std;

int main()
{
    double m;
    int ans;
    cout<<"Nhap so luong tan gao: ";
    cin>>m;
    //Doi tan ra kg
    m*=1000;
    //Tinh so bao gao
    ans=(int)m/20;
    if (20.0*ans !=m) ans++;
    cout<<"So bao gao: "<<ans;
    return 0;
}
