#include <iostream>

using namespace std;

int main()
{
    int n,cnt=0,ans[17];
    cout<<"Nhap so nguyen n: ";
    cin>>n;
    while (n!=0){
        ans[cnt++]=n&1; //Tuong tu n%2
        n>>=1;          //Tuong tu n/=2
    }
    for (int i=cnt-1;i>=0;i--)
        cout<<ans[i];
    return 0;
}
