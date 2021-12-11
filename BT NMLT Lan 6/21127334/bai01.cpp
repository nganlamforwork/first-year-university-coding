#include <iostream>

using namespace std;
struct dataType{
    int hour, minute, second;
};
dataType a,b;
void input (dataType &x)
{
    cout<<"Nhap gio: ";
    cin>>x.hour;
    cout<<"Nhap phut: ";
    cin>>x.minute;
    cout<<"Nhap giay: ";
    cin>>x.second;
}
int toSecond(dataType x)
{
    int ans=0;
    ans+=x.second;
    ans+=x.minute*60;
    ans+=x.hour*60*60;
    return ans;
}
dataType toDataType(int x)
{
    dataType ans;
    ans.second=x%60;
    x/=60;
    ans.minute=x%60;
    ans.hour=x/60;
    return ans;
}

int main()
{
    cout<<"Nhap moc thoi gian so 1:\n";
    input(a);
    cout<<"Nhap moc thoi gian so 2:\n";
    input(b);
    cout<<"Thoi gian chenh lech giua 2 moc thoi gian la: ";
    dataType ans = toDataType( abs(toSecond(a)-toSecond(b)) );
    cout<<ans.hour<<'h'<<ans.minute<<'m'<<ans.second<<'s';
    return 0;
}
