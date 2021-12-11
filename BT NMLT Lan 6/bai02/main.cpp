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
pso add (pso x, pso y)
{
    pso ans;
    ans.tu=x.tu*y.mau+y.tu*x.mau;
    ans.mau=x.mau*y.mau;
    int tmp=__gcd(ans.tu,ans.mau);
    ans.tu/=tmp;
    ans.mau/=tmp;
    return ans;
}
int main()
{
    pso a,b;
    cout << "Nhap phan so 1: \n";
    input(a);
    cout << "Nhap phan so 2: \n";
    input(b);
    pso ans=add(a,b);
    cout<<ans.tu<<'/'<<ans.mau;
    return 0;
}
