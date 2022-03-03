#include <iostream>

using namespace std;

int main()
{
    int n,cnt=1,ans=0;
    cout<<"Nhap so nguyen n: ";
    cin>>n;
    while (n!=0){
        ans+=(n&1)*cnt; //Tuong tu (n%2)*10^(cnt-1)
        cnt*=10;
        n>>=1;          //Tuong tu n/=2
    }
    cout<<"Bieu dien nhi phan cua so n la: "<<ans;
    return 0;
}
