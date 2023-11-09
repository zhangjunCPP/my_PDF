#include<bits/stdc++.h>
using namespace std;
const int N=503, M=1e5+3;
bool f[N][M], vis[N];
int n, m, a[N];
void solve(int now, int x, int l){
    if(now==x){
        a[now]=l;
        long long ans=0;
        for(int i=1;i<=x;++i)
            ans+=a[i]*(n-a[i]);
        ans/=2;
        f[n][ans]=1;
        return ;
    }
    for(int i=a[now-1]; i*(x-now+1)<=l ;++i)
        a[now]=i, solve(now+1, x, l-i);
}
int main(){
    freopen("stick.in", "r", stdin);
    freopen("stick.out", "w", stdout);
    int q;
    scanf("%d", &q);
    while(q--){
        scanf("%d%d", &n, &m);
        if(vis[n]) printf("%d\n", f[n][m]);
        else{
            vis[n]=1;
            for(int i=1;i<=n;++i)
                memset(a, 0, sizeof(a)), a[0]=1, solve(1, i, n);
            printf("%d\n", f[n][m]);
        }
    }
    return 0;
}
