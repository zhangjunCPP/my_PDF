#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353, N=2e3+3;
int a[N], n;
bool f[N];
long long ans;
void solve(int x, int pre){
    if(x>n){
        ans=(ans+1)%Mod;
        return ;
    }
    if(a[x]!=1){
        int u;
        for(int i=1;i+a[x]<=n+1;++i){
            if(!f[i]){
                for(int j=i;j<=i+a[x]-1;++j)
                    if(f[j]){
                        i=j;
                        goto ed;
                    }
                for(int k=i;k<=i+a[x]-1;++k)
                    f[k]=1;
                u=i;
                goto st;
            }
            ed:;
        }
        return ;
        st:
        if(u!=pre) solve(x+a[x], u+a[x]);
        if(u+a[x]!=pre) solve(x+a[x], u-1);
    }else{
        for(int i=1;i<=n;++i){
            if(i==pre) continue;
            if(!f[i]) f[i]=1, solve(x+1, i+1), solve(x+1, i-1), f[i]=0;
        }
    }
}
int main(){
    freopen("gap.in", "r", stdin);
    freopen("gap.out", "w", stdout);
    scanf("%d", &n);
    for(int i=1;i<=n;++i)
        scanf("%d", &a[i]);
    solve(1, 0);
    cout<<ans;
    return 0;
}
