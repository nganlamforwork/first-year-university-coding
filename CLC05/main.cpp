#include <iostream>
#include <fstream>
using namespace std;
string mssv = "21127334";

struct Data{
    int MaSV;
    string info[9];
};

Data a[101];
int n;

bool check(int x){
    for (int i=0; i<(int)mssv.size();i++)
        if (mssv[i]-'0' ==x-1)
            return 1;
    return 0;
}

void Input(string x, int MaSV)
{
    a[++n].MaSV=MaSV; //Add element

    int i=0,id=0;
    (a[n].info)[id]=""; //Init string

    while (i<x.size()){
        if (x[i]!='\t')
            (a[n].info)[id] += x[i];
        else
            (a[n].info)[++id] = "";
        ++i;
    }
}
void bai1(char input[]){
    ifstream in;
    in.open(input);

    string tmp;
    int MaHS;

    getline(in,tmp,'\n');

    for(int i = 1; i <= 10; i++){
        in >> MaHS;
        if (!check(MaHS)) {
            getline(in,tmp,'\n');
            continue;
        }
        getline(in,tmp,'\n');
        Input(tmp,i);
    }
}
int main()
{
    char input1[] = "Diem-kiem-tra-1-tiet.txt";
    bai1("Danh-sach-hoc-sinh.txt");

    //Check solution
    for (int i=1;i<=n;i++){
        cout<<a[i].MaSV<<'\t';
        for (int j=1;j<=6;j++)
            cout<<(a[i].info)[j]<<'\t';
        cout<<'\n';
    }
    return 0;
}
