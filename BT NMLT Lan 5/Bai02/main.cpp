#include <iostream>

using namespace std;
double getData(double a[13][2], int x, int y){
    return a[x][y];
}
double averageHigh(int a[13][2]){
    double sum=0;
    for (int i=1;i<=12;i++)
        sum+=a[i][1];
    return sum/12;
}
double averageLow(int a[13][2]){
    double sum=0;
    for (int i=1;i<=12;i++)
        sum+=a[i][0];
    return sum/12;
}
int indexHighTemp(int a[13][2]){
    double Max=a[1][1];
    int id=1;
    for (int i=2;i<=12;i++)
        if (Max<a[i][1]){
            Max=a[i][1];
            id=i;
        }
    return id;
}
int indexLowTemp(int a[13][2]){
    double Min=a[1][1];
    int id=1;
    for (int i=2;i<=12;i++)
        if (Min>a[i][1]){
            Min=a[i][1];
            id=i;
        }
    return id;
}
int main()
{
    double a[13][2];
    for (int i=1;i<=12;i++){
        cout<<"Nhap nhiet do cao nhat cua thang "<<i<<": ";
        cin>>a[i][1];
        cout<<"Nhap nhiet do thap nhat cua thang "<<i<<": ";
        cin>>a[i][0];
    }

    return 0;
}
