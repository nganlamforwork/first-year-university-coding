#include <iostream>

using namespace std;
struct SinhVien{
    int ID;
    string name;
    float Toan,Ly,Hoa;
    float Sum;
};
void input(SinhVien &x){
    cout<<"Nhap ID: ";
    cin>>x.ID;
    cout<<"Nhap ten: ";
    cin>>x.name;
    cout<<"Nhap diem Toan: ";
    cin>>x.Toan;
    cout<<"Nhap diem Ly: ";
    cin>>x.Ly;
    cout<<"Nhap diem Hoa: ";
    cin>>x.Hoa;
    x.Sum=x.Toan+x.Hoa+x.Ly;
}
bool isMin(SinhVien x, SinhVien y)
{
    return(y.Sum < x.Sum);
}
bool isMax(SinhVien x, SinhVien y)
{
    return(y.Sum > x.Sum);
}
int main()
{
    SinhVien a[100],themin,themax;
    int n;
    cout << "Nhap n: ";
    cin>>n;

    for (int i=1;i<=n;i++) input(a[i]);

    themin=a[1];themax=a[1];
    for (int i=2;i<=n;i++){
        if (isMin(themin,a[i]))
            themin=a[i];
        if (isMax(themax,a[i]))
            themax=a[i];
    }

    cout<<"ID cua cac sinh vien co diem trung binh thap nhat: ";
    for (int i=1;i<=n;i++)
        if (themin.Sum==a[i].Sum)
            cout<<a[i].ID<<' ';
    cout<<"\nID cua cac sinh vien co diem trung binh cao nhat: ";
    for (int i=1;i<=n;i++)
        if (themax.Sum==a[i].Sum)
            cout<<a[i].ID<<' ';
    return 0;
}
