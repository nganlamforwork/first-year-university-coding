#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
long long a[maxn];
long long ans;
int n,k;
int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,greater<long long>() );
    for (int i=1;i<=k;i++)
        ans+=a[i];
    cout<<ans;
    return 0;
}
