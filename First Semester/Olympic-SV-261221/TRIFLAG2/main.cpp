#include <bits/stdc++.h>
#define maxn 1010
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
int n;
pii a[maxn];
map<int,vector<pii> >cheo,doc,ngang;
set<pii> Point;
void Input()
{
    int x,y;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>x>>y;
        a[i]=pii(x,y);
        cheo[x+y].pb(pii(x,y));
        doc[x].pb(pii(x,y));
        ngang[y].pb(pii(x,y));
        Point.insert(pii(x,y));
    }
}
bool checkNgang(pii fi, pii se)
{
    auto it1=Point.find(fi);
    auto it2=Point.find(se);
    auto tmp = &it1-&it2;
    return abs(tmp)==1;
}
void Solution()
{
    int x,y, Left, Right, Top, Bottom;
    int ans=0;
    for (auto e:cheo){
        int val = e.first;
        vector<pii> arr = e.second;
        sort(arr.begin(),arr.end());
        for (int i=0;i<(int)arr.size()-1;i++){
            int xOne = arr[i+1].first;
            int yOne = arr[i].second;
            if (Point.find(pii(xOne,yOne))!=Point.end())
                ans+=checkNgang(arr[i],pii(xOne,yOne));

            int xTwo = arr[i].first;
            int yTwo = arr[i+1].second;
            if (Point.find(pii(xTwo,yTwo))!=Point.end())
                ans+=checkNgang(arr[i+1],pii(xTwo,yTwo));
        }
    }
    for (auto e:doc){
        vector<pii> arr = e.second;
        sort(arr.begin(),arr.end());
        for (int i=0;i<(int)arr.size()-1;i++){
            if((arr[i].second+arr[i+1].second)%2!=0) continue;

            int yOne = (arr[i].second+arr[i+1].second)/2;
            int xOne = arr[i].first + abs(arr[i].second-arr[i+1].second)/2;

            if (Point.find(pii(xOne,yOne))!=Point.end()) ans++;

            xOne = arr[i].first - abs(arr[i].second-arr[i+1].second)/2;

            if (Point.find(pii(xOne,yOne))!=Point.end()) ans++;
        }
    }
    for (auto e:ngang){
        vector<pii> arr = e.second;
        sort(arr.begin(),arr.end());
        for (int i=0;i<(int)arr.size()-1;i++){
            if((arr[i].first+arr[i+1].first)%2!=0) continue;

            int xOne = (arr[i].first+arr[i+1].first)/2;
            int yOne = arr[i].second + abs(arr[i].first-arr[i+1].first)/2;

            if (Point.find(pii(xOne,yOne))!=Point.end()) ans++;

            xOne = arr[i].first - abs(arr[i].first-arr[i+1].first)/2;

            if (Point.find(pii(xOne,yOne))!=Point.end()) ans++;
        }
    }
    cout<<ans;
}
int main()
{
    Input();
    Solution();
    return 0;
}
