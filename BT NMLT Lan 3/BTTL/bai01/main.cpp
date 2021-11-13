#include <iostream>

using namespace std;

int main()
{
    int n, cnt=0;

    cout<<"n = ";
    cin>>n;
    while (n!=0){
        cnt++;
        n/=10;
    }
    cout<<"So chu so cua n la: "<<cnt;
    return 0;
}
