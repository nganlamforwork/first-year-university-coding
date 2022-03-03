#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int n;
long long a[maxn], f[maxn], ans;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    //Init
    for (int i=1;i<=4;i++)
        f[i]=a[i];
    //DP
    for (int i=5;i<=n;i++){
        f[i]=a[i]+f[i-4];
        f[i]=min(f[i],a[i]+f[i-3]);
        f[i]=min(f[i],a[i]+f[i-2]);
        f[i]=min(f[i],a[i]+f[i-1]);
    }
    //Answer
    ans=f[n];
    for (int i=n;i>=n-3;i--)
        ans=min(ans,f[i]);
    cout<<ans;
    return 0;
}
