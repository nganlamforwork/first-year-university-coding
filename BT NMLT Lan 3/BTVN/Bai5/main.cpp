#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    for (int i=n+1;;i++){
        bool check=1;
        for (int j=2;j*j<=i;j++)
            if (i%j==0){
                check=0;
                break;
            }
        if (check){
            cout<<"So nguyen to nho nhat lon hon "<<n<<" la: "<<i;
            break;
        }
    }
    return 0;
}
