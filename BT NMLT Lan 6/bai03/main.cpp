#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
struct pso{
    int tu, mau;
};
void input(pso &x)
{
    cout<<"Nhap tu so: ";
    cin>>x.tu;
    cout<<"Nhap mau so: ";
    cin>>x.mau;
}
bool isMin(pso x, pso y)
{
    return(y.tu*x.mau < x.tu*y.mau);
}
int main()
{
    pso a[1000],themin;
    int n;
    cout << "Nhap n: ";
    cin>>n;
    for (int i=1;i<=n;i++){
        cout<<"Nhap phan so "<<i<<":\n";
        input(a[i]);
    }
    themin=a[1];
    for (int i=2;i<=n;i++){
        if (isMin(themin,a[i]))
            themin=a[i];
    }
    cout<<themin.tu<<'/'<<themin.mau;
    return 0;
}
