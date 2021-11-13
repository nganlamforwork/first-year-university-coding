#include <iostream>

using namespace std;

int main()
{
    int Old, New, num, ans;

    cout<<"Nhap chi so cu: ";
    cin>>Old;
    cout<<"Nhap chi so moi: ";
    cin>>New;

    num=New-Old+1;
    ans=0;
    if (num<=100) ans+=1000*num;
    else{
        ans+= 1000*num;
        if (num<=150) ans+= 1200*(150-num+1);
        else{
            ans+=50*1200;
            if (num<=200) ans+= 2000*(200-num+1);
            else
                ans+=1500*50+(num-200+1)*2500;
        }
    }
    cout<<"So tien phai tra la: "<<ans;
    return 0;
}
