#include <bits/stdc++.h>
#define maxn 1010
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
int n;
pii a[maxn],cox[maxn],coy[maxn];
map<int,vector<int> >cheo;
void Input()
{
    int x,y;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>x>>y;
        a[i]=pii(x,y);
        cox[i]=pii(x,i);
        coy[i]=pii(y,i);
        cheo[x+y].pb(i);
    }
}
int findLower(int x, pii arr[])
{
    int l=1, r=n, ans=0;
    while (l<=r){
        int mid = (l+r)/2;
        if (arr[mid].first>=x) r=mid-1;
        else {
            l=mid;
            ans=max(ans,mid);
        }
    }
    return ans;
}
int findHigher(int x, pii arr[])
{
    int l=1, r=n, ans=n+1;
    while (l<=r){
        int mid = (l+r)/2;
        if (arr[mid].first<=x) l=mid+1;
        else {
            r=mid;
            ans=min(ans,mid);
        }
    }
    return ans;
}
void Solution()
{
    sort(cox+1,cox+1+n);
    sort(coy+1,coy+1+n);
    for (auto e:cheo)
        sort(e.second.begin(),e.second.end());

    int x,y, Left, Right, Top, Bottom;
    for (int i=1;i<=n;i++){
        x=a[i].first;
        y=a[i].second;
        Left = findLower(x,cox);
        Right = findHigher(x,cox);
        Top = findHigher(y,coy);
        Bottom = findHigher(y,coy);
    }
}
int main()
{
    Input();
    Solution();
    return 0;
}
