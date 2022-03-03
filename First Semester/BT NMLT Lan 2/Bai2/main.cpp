#include <iostream>

using namespace std;

int main()
{
    int math,physics,chemistry;

    cout << "Nhap diem mon Toan: ";
    cin>>math;
    cout << "Nhap diem mon Ly: ";
    cin>>physics;
    cout << "Nhap diem mon Hoa: ";
    cin>>chemistry;

    if (math+physics+chemistry>=15 && math>=4 && physics>=4 && chemistry>=4) {
        if (math>=5 && physics>=5 && chemistry>=5)
            cout<<"Hoc deu cac mon";
        else if (math<5 || physics<5 || chemistry<5)
            cout<<"Hoc chua deu cac mon";
        else cout<<"Dau";
    }
    else cout<<"Thi hong";
    return 0;
}
