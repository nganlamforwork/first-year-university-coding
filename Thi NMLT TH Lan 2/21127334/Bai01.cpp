#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
using namespace std;

void formatNumberWithCommas(string str){
    string ans="";
    int cnt=0;
    int length=str.size();
    for (int i=length-1;i>=0;i--){
        cnt++;
        if (cnt<3) {
            ans=str[i]+ans;
        }
        else {
            cnt=0;
            ans=str[i]+ans;
            ans=','+ans;
        }
    }
    if (ans[0]==',') ans.erase(0,1);
    cout<<ans;
}
int main()
{
    string n;
    cout<<"Nhap chuoi so nguyen: ";
    cin>>n;
    formatNumberWithCommas(n);
    return 0;
}
