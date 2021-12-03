#include <iostream>
#include <iomanip>

using namespace std;
const int maxn=101;
void initBoard(char a[maxn][maxn])
{
    for (int i=1;i<=13;i++)
        for (int j=1;j<=6;j++)
            a[i][j]='*';
}
void showBoard(char a[maxn][maxn])
{
    int w=5;
    for (int i=1;i<=6;i++){
        char c='A'+i-1;
        if (i==1) cout<<setw(10)<<c;
        else cout<<setw(w)<<c;
    }
    cout<<'\n';
    for (int i=1;i<=13;i++){
        cout<<"Row "<<i;
        for (int j=1;j<=6;j++)
            cout<<setw(w-(i>9&&j==1))<<a[i][j];
        cout<<'\n';
    }
}

bool check(char a[maxn][maxn], int x, int y)
{
    return (a[x][y]=='*');
}
int main()
{
    int x, y;
    char c,a[maxn][maxn];

    initBoard(a);

    while (true){
        cout<<"\n\nBang cho ngoi hien tai:\n";
        showBoard(a);
        cout<<"Ban muon lua chon loai ve nao?\n";
        cout<<"Hang nhat: 1-2\n";
        cout<<"Hang thuong gia: 3-7\n";
        cout<<"Hang pho thong: 8-13\n";
        cout<<"Vui long nhap so tuong ung: ";
        cin>>x;
        cout<<"Vui long nhap vi tri tren hang ma ban muon (A-F): ";
        cin>>c;
        y=c-'A'+1;
        if (check(a,x,y)){
            cout<<"Chuc mung ban da dat ve thanh cong!\n";
            a[x][y]='X';
            cout<<"Ban co muon tiep tuc dat ve khong? (y/n)\n";
            cin>>c;
            if (c=='y') continue;
            else break;
        }
        else cout<<"Ban da dat ve khong thanh cong! Vui long dat lai!\n";
    }

    return 0;
}
