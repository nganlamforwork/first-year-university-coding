#include <iostream>

using namespace std;
int n=0;
struct carType{
    string carMake;
    string carModel;
    int yearModel;
    double cost;
    int quantity;
    int sold;
    bool del;
};
void input(carType &x){
    cout<<"Nhap carMake: ";
    cin>>x.carMake;
    cout<<"Nhap carModel: ";
    cin>>x.carModel;
    cout<<"Nhap yearModel: ";
    cin>>x.yearModel;
    cout<<"Nhap cost: ";
    cin>>x.cost;
    cout<<"Nhap quantity: ";
    cin>>x.quantity;
    x.sold=0;
    x.del=0;
}
void outputAll(carType x[]){
    cout<<"Make \t Model \t Year \t Cost \t Quantity\n";
    for (int i=1; i<=n; i++){
        cout<<x[i].carMake<<'\t';
        cout<<x[i].carModel<<'\t';
        cout<<x[i].yearModel<<'\t';
        cout<<x[i].cost<<'\t';
        cout<<x[i].quantity<<'\t';
        cout<<'\n';
    }
}
void soldCar(carType x[]){
    string make;
    int num;
    cout<<"Nhap carMake cua xe ban muon mua: ";
    cin>>make;
    cout<<"Nhap so luong xe ban muon mua: ";
    cin>>num;

    for (int i=1;i<=n;i++)
        if (x[i].carMake==make){
            if (x[i].quantity-x[i].sold>=num){
                x[i].sold+=num;
                cout<<"Ban da mua thanh cong xe!\n";
                return;
            }
            else{
                cout<<"Khong du so luong de ban!\n";
                return;
            }
        }
    cout<<"Khong co loai xe ban muon mua!\n";
}
void thuHoi(carType x[]){
    int id;
    cout<<"Nhap id xe muon thu hoi: ";
    cin>>id;
    x[id].del=1;
}
void yeuCau5(carType x[]){
    float sum=0;
    for (int i=1;i<=n;i++)
        if (x[i].sold!=0){
            cout<<"Xe "<<x[i].carMake<<" da ban duoc "<<x[i].sold<<" chiec.\n";
            sum+=x[i].sold*x[i].cost;
        }
    cout<<"Tong cong ban duoc $"<<sum;
}
int main()
{
    carType a[1000];
    int t;
    char t2;
    while (true){
        cout<<"Ban muon thuc hien hanh dong nao? (1,2,3,4,5)\n";
        cin>>t;
        if (t==1) outputAll(a);
        else if (t==2) input(a[++n]);
        else if (t==3) soldCar(a);
        else if (t==4) thuHoi(a);
        else yeuCau5(a);
        cout<<"Ban co muon tiep tuc chuong trinh khong? (y/n)\n";
        cin>>t2;
        if (t2=='n') break;
    }
    return 0;
}
