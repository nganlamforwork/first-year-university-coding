#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cout<<"Nhap vao 3 canh a, b, c cua 1 tam giac: ";
    cin>>a>>b>>c;

    if ((a+b)>c && abs(a-b)<c && (a+c)>b && abs(a-c)<b && (c+b)>a && abs(c-b)<a){
        if (a==b && b==c) cout<<"Tam giac deu";
        else if (a==b || a==c || b==c) cout<<"Tam giac can";
        else if (a*a+b*b==c*c || c*c+b*b==a*a || a*a+c*c==b*b) cout<<"Tam giac vuong";
        else cout<<"Tam giac thuong";
    }else cout<<"Khong phai tam giac";
    return 0;
}
