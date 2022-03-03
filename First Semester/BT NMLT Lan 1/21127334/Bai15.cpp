#include <bits/stdc++.h>
using namespace std;

int main()
{
    int total,num,price,money,ten,five,two,one;
    cout<<"Nhap so chai nuoc: ";
    cin>>num;
    cout<<"Nhap don gia: ";
    cin>>price;
    cout<<"Nhap so tien nguoi dung tra: ";
    cin>>money;
    total=money-num*price;

    ten=total/10;
    total%=10;
    five=total/5;
    total%=5;
    two=total/2;
    one=total%2;

    cout<<"Tien thua la: \n";
    cout<<"So to 10 dong: "<<ten<<'\n';
    cout<<"So to 5 dong: "<<five<<'\n';
    cout<<"So to 2 dong: "<<two<<'\n';
    cout<<"So to 1 dong: "<<one<<'\n';
    return 0;
}
