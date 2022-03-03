#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int vote[1000],id=0,themax=0,n,sum=0;
    string name[1000];
    cout<<"Nhap so ung cu vien: ";
    cin>>n;
    for (int i=1;i<=n;i++){
        cout<<"Nhap ten cua ung cu vien so "<<i<<": ";
        cin>>name[i];
        cout<<"Nhap so vote cua ung cu vien so "<<i<<": ";
        cin>>vote[i];
        sum+=vote[i];
        if (themax<=vote[i]){
            id=i;
            themax=vote[i];
        }
    }
    cout<<setw(10)<<"Candidate"<<setw(20)<<"Votes"<<setw(30)<<"Recieved % of Total Votes\n";
    for (int i=1;i<=n;i++){
        double percent = (double)vote[i]/(double)sum * 100;
        cout<<setw(10)<<name[i];
        cout<<setw(20)<<vote[i];
        cout<<setw(30)<<fixed<<setprecision(2)<<percent<<'\n';
    }
    cout<<"\nTotal "<<setw(20)<<sum<<'\n';
    cout<<"The Winner of the Election is "<<name[id]<<".";
    return 0;
}
