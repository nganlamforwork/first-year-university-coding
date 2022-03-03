#include <iostream>

using namespace std;

int main()
{
    int x;
    cout<<"Nhap so nguyen x: ";
    cin>>x;

    if (x<=9) cout<<x;
    else{
        char ans = x+55;
        cout<<ans;
    }
    return 0;
}
