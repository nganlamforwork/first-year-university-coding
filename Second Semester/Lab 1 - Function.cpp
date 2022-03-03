#include <iostream>
#include <math.h>

using namespace std;
void LinearEquation(int a, int b)
{
    //ax + b = 0;
    double x = (double) -b / a;
    cout<<"x = "<<x<<'\n';
}
void QuadraticEquation(int a, int b, int c)
{
    //ax2 + bx + c = 0
    double delta = b*b - 4*a*c;
    if (delta<0) cout<<"Vo nghiem\n";
    else if (delta==0){
        double x = (double) -b / (2*a);
        cout<<"x = "<<x<<'\n';
    }
    else{
        double x1 = (double) (-b + sqrt(delta)) / (2*a);
        double x2 = (double) (-b - sqrt(delta)) / (2*a);
        cout<<"x1 = "<<x1<<'\n';
        cout<<"x2 = "<<x2<<'\n';
    }
}
bool isPrime(int a)
{
    if (a<2) return 0;
    for (int i=2;i<=(int)sqrt(a);i++)
        if (a%i==0) return 0;
    return 1;
}
int countPrime(int a, int b)
{
    int ans=0;
    for (int i=a;i<=b;i++)
        if (isPrime(i))
            ans++;
    return ans;
}
int sumDigits(int n)
{
    int ans=0;
    while (n!=0){
        ans+=n%10;
        n/=10;
    }
    return ans;
}
int countInteger(int N, int k)
{
    int ans = N/k;
    return ans;
}
void Triangle(float a, float b, float c)
{
    if (a+b<c || a+c<b || b+c<a){
        cout<<"Not a triangle\n";
        return;
    }
    if (a==b && b==c & a==c) {
        cout<<"Isosceles triangle\n";
        return;
    }
    if (a==b || b==c || a==c){
        if (a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b){
            cout<<"Right isosceles triangle\n";
            return;
        }
        cout<<"Equilateral triangle\n";
        return;
    }
    if (a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b){
        cout<<"Right triangle\n";
        return;
    }
    cout<<"Normal triangle\n";
}
int main()
{
    return 0;
}
