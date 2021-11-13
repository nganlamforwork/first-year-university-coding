#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Nhap chieu cao cua tam giac: ";
    cin>>n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<2*n; j++)
            if (j<=n-i || j>n+i-1) cout<<' ';
            else cout<<'*';
        cout<<'\n';
    }
    return 0;
}
