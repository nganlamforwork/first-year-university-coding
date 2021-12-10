#include <iostream>

using namespace std;
const int maxn = 1001;
char a[maxn][maxn];
int n,m;
void Input(){
    string tmp;

    cout<<"Nhap n: ";
    cin>>n;
    cout<<"Nhap m: ";
    cin>>m;

    for (int i=1;i<=n;i++){
        cout<<"Nhap chuoi "<<i<<": ";
        cin>>tmp;
        for (int j=0;j<(int)tmp.size();j++)
            a[j+1][i]=tmp[j];
    }
}
void Output1(){
    cout<<"Yeu cau 1 - Bang ky tu duoc tao:\n";
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
}
void Output2(){
    cout<<"Yeu cau 2 - Chuoi duoc tao theo hinh zigzag:\n";
    for (int i=1;i<=m;i++){
        if (i%2==1){
            for (int j=1;j<=n;j++)
                cout<<a[i][j];
            }
        else{
            for (int j=n;j>=1;j--)
                cout<<a[i][j];
        }
    }
}
int main()
{
    Input();
    Output1();
    Output2();
    return 0;
}
