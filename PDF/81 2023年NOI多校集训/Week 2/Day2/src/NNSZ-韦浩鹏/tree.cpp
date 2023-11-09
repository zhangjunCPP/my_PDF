#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3, Mod=1e9+7;
vector <int> v[N];
void add(int x, int y){
    v[x].push_back(y);
    v[y].push_back(x);
}
int d[N], dmax, cnt[2], node;
void dfs(int x, int fa, bool f){
    d[x]=d[fa]+1;
    if(d[x]>dmax) dmax=d[x], cnt[f]=1, node=x;
    else if(d[x]==dmax) ++cnt[f];
    for(int i=0;i<(int)v[x].size();++i){
        int y=v[x][i];
        if(y==fa) continue;
        dfs(y, x, f);
    }
}

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i=1;i<n;++i){
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    d[0]=-1, dfs(1, 0, 0), dmax=0;
    memset(d, 0, sizeof d);
    d[node]=-1, dfs(node, node, 1);
    if(cnt[0]+cnt[1]>2){
        long long ans=dmax;
        for(int i=1;i<=n;++i)
            ans=ans*2%Mod;
        printf("%lld", ans);
    }else if(cnt[0]==1&&cnt[1]==1){
        long long ans=dmax;
        int r=dmax, p=r+1;
        for(int i=1;i<=n-2;++i)
            ans=ans*2%Mod;
        printf("%d", ans);

    }

    return 0;
}
