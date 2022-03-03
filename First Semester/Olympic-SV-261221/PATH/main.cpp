#include <bits/stdc++.h>

#define maxn 1005
#define fi first
#define se second
#define pb push_back

using namespace std;

const int inf = 1e9-1;

typedef pair<int,bool> pii;
typedef pair<int,pii> tii;

vector<tii> a[maxn];

int d[maxn];
int n,m;

void Input()
{
    int k,u,v;
    bool c;
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        cin>>u>>v>>k;
        cin>>c;
        a[u].pb(tii(v,pii(k,c)));
        a[v].pb(tii(u,pii(k,c)));
    }
}
int dijkstra()
{
    priority_queue<tii, vector<tii>, greater<tii> > q;
    int u, du, v, uv;
    bool tu, tv;   //tu = type of u - tv = type of v

    //Init
    for (int i=1;i<=n;i++)
        d[i] = inf;
    d[1]=0;
    for (int i=0;i<(int)a[1].size();i++){
        v = a[1][i].fi;
        uv = a[1][i].se.fi;
        tv = a[1][i].se.se;
        q.push(tii(uv,pii(v,tv)));
    }

    //Main solution
    while(!q.empty()){
        u = q.top().se.fi;
        du = q.top().fi;
        tu = q.top().se.se;
        q.pop();
        for (int i=0;i<(int)a[u].size();i++){
            v = a[u][i].fi;
            uv = a[u][i].se.fi;
            tv = a[u][i].se.se;
            if ((tu^tv) && d[v]>du+uv){
                d[v]=du+uv;
                q.push(tii(d[v],pii(v,tv)));
            }
        }
    }
    if (d[n]==inf) d[n]=-1;
    return d[n];
}
int main()
{
    Input();
    cout<<dijkstra();
    return 0;
}
