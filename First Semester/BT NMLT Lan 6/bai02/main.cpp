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
int GCD(int A, int B) {
    if (B == 0) return A;
    else return GCD(B, A % B);
}
pso add (pso x, pso y)
{
    pso ans;
    ans.tu=x.tu*y.mau+y.tu*x.mau;
    ans.mau=x.mau*y.mau;
    int tmp=GCD(ans.tu,ans.mau);
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
    if (ans.mau!=1)
        cout<<ans.tu<<'/'<<ans.mau;
    else cout<<ans.tu;
    return 0;
}
