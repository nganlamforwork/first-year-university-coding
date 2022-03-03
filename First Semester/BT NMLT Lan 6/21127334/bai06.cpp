#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <iomanip>
using namespace std;
struct player{
    string name;
    int numAssists;
    int numGoals;
};
void input(vector<player>& x)
{
    player tmp;
    cout<<"Input name: ";
    cin.ignore();
    getline(cin,tmp.name,'\n');
    cout<<"Input numGoals: ";
    cin>>tmp.numGoals;
    cout<<"Input numAssists: ";
    cin>>tmp.numAssists;
    x.push_back(tmp);
}
void outputAll(vector<player> x)
{
    cout<<setw(20)<<"Name"<<setw(16)<<"numGoals"<<setw(16)<<"numAssists\n";
    for (int i=0;i<(int)x.size();i++)
        cout<<setw(20)<<x[i].name<<setw(16)<<x[i].numGoals<<setw(16)<<x[i].numAssists<<'\n';
}
void erasePlayer(vector<player>& x)
{
    int id;
    cout<<"Xuat id cau thu muon xoa khoi CLB: ";
    cin>>id;
    vector<player>::iterator eraseIT=x.begin()+(id-1);
    x.erase(eraseIT);
    cout<<"Bang cau thu sau khi xoa cau thu so "<<id<<"\n";
    outputAll(x);
}
void update(vector<player>& x)
{
    int id, numGoals, numAssists;
    cout<<"Nhap id cau thu muon thay doi: ";
    cin>>id;
    cout<<"Nhap so luong ban thang (cap nhat): ";
    cin>>numGoals;
    cout<<"Nhap so luong kien tao (cap nhat): ";
    cin>>numAssists;
    x[id-1].numGoals=numGoals;
    x[id-1].numAssists=numAssists;
}
void bestPlayer(vector<player>& x)
{
    int ans=-1,tmp;
    for (int i=0;i<(int)x.size();i++){
        tmp=0.4*x[i].numAssists + 0.6*x[i].numGoals;
        ans=max(ans,tmp);
    }
    if (ans==-1) cout<<"Khong co cau thu trong danh sach\n";
    else{
        cout<<"Best player la: ";
        for (int i=0;i<(int)x.size();i++){
            tmp=0.4*x[i].numAssists + 0.6*x[i].numGoals;
            if (ans==tmp) cout<<x[i].name<<' ';
        }
        cout<<'\n';
    }
}
int main()
{
    vector<player> a;
    char t;
    int type;
    while (true){
        cout<<"1\tIn ra tat ca cau thu\n";
        cout<<"2\tThem cau thu moi vao CLB\n";
        cout<<"3\tXoa cau thu khoi CLB\n";
        cout<<"4\tUpdate thong tin cho cau thu\n";
        cout<<"5\tTim ra cau thu xuat sac nhat\n";
        cout<<"Ban muon thuc hien hanh dong nao? \n";
        cin>>type;
        if (type==1) outputAll(a);
        else if (type==2) input(a);
        else if (type==3) erasePlayer(a);
        else if (type==4) update(a);
        else bestPlayer(a);
        cout<<"Ban co muon tiep tuc chuong trinh khong?(y/n)";
        cin>>t;
        if (t=='n') break;
    }

    return 0;
}
