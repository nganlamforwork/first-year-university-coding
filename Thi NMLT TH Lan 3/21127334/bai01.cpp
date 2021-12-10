#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, x, k;
    cout<<"Nhap n = ";
    cin>>n;
    if ((n-1)%2==0){
        x=(n-1)/2;
        k=sqrt(x);
        if (k*k==x) cout<<n<<" la so gia nguyen to voi k = "<<k;
        else cout<<n<<" khong la so gia nguyen to";
    }
    else {
        cout<<n<<" khong la so gia nguyen to";
    }
    return 0;
}
