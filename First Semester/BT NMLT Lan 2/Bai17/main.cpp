#include <iostream>

using namespace std;

int main()
{
    char type;
    float canNang, coTay, eo, hong, canhTay, a1, a2, a3, a4, a5, b, luongMo, phanTram;

    cout<<"Ban co phai la nu khong? (y/n): ";
    cin>>type;
    cout<<"Nhap can nang: ";
    cin>>canNang;
    cout<<"Nhap kich thuoc co tay: ";
    cin>>coTay;

    if (type=='n'){
        a1=(canNang*1.082)+9.442;
        a2=coTay*4.15;
        b=a1-a2;
        luongMo=canNang-b;
        phanTram=luongMo*100/canNang;
    }
    else{
        cout<<"Nhap kich thuoc eo: ";
        cin>>eo;
        cout<<"Nhap kich thuoc hong: ";
        cin>>hong;
        cout<<"Nhap kich thuoc canh tay: ";
        cin>>canhTay;

        a1=(canNang*0.732)+8.987;
        a2=coTay/3.140;
        a3=eo*0.157;
        a4=hong*0.249;
        a5=canhTay*0.434;
        b=a1+a2-a3-a4+a5;
        luongMo=canNang-b;
        phanTram=luongMo*100/canNang;
    }
    cout<<"Luong mo cua ban la: "<<luongMo<<'\n';
    cout<<"Phan tram luong mo cua ban la: "<<phanTram;
    return 0;
}
