#include <iostream>

using namespace std;

int main()
{
    char type;
    int minimum,current;
    float ans;

    cout << "Nhap loai tai khoan: ";
    cin>>type;
    cout << "Nhap so du toi thieu: ";
    cin>>minimum;
    cout << "Nhap so du cuoi thang: ";
    cin>>current;

    if (type=='t'){
        if (current<minimum)
            cout<<"Tong tien phat la: 10";
        else {
            ans=current * 0.04;
            cout<<"Tong tien lai la: "<<ans;
        }
    }
    else{
        if (current<minimum)
            cout<<"Tong tien phat la: 25";
        else {
            if (current-minimum>=5000) ans=current * 0.03;
            else ans=current*0.05;
            cout<<"Tong tien lai la: "<<ans;
        }
    }
    return 0;
}
