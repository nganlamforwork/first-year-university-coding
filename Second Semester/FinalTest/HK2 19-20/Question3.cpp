#include <iostream>
#include <fstream>
using namespace std;
struct staff{
    int id;
    char name[30];
    float value;
};
void createBINfile()
{
    ifstream in("COMPANY.TXT");
    ofstream out("COMPANY.BIN",ios::binary);
    staff tmp;
    while (!in.eof()){
        in>>tmp.id; in.ignore();
        in.getline(tmp.name,30,' ');
        in>>tmp.value;

        out.write(reinterpret_cast<char *> (&tmp),sizeof(tmp));
    }
    in.close(); out.close();
}
void readAndShow(const char* filename)
{
    ifstream in(filename,ios::binary);
    staff a[100];
    bool check[100]={};
    int n=0;
    while (!in.eof()){
        in.read(reinterpret_cast<char *> (&a[n]), sizeof(a[n]));
        ++n;
    }
    n--;
    for (int i=0;i<n;i++)
        if (!check[i]){
            check[i]=1;
            int sum=a[i].value;
            for (int j=i+1;j<n;j++)
                if (a[j].id==a[i].id){
                    check[j]=1;
                    sum+=a[j].value;
                }
            cout<<a[i].id<<' '<<a[i].name<<' '<<sum<<'\n';
        }
    in.close();
}
int main()
{
    createBINfile();
    readAndShow("COMPANY.BIN");
    return 0;
}
