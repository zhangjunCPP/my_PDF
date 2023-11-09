#include<bits/stdc++.h>
using namespace std;
const int N=1e7+3;
typedef unsigned long long LL;
int a[N], b[N];
int n, mod;
bool f[N];
LL ans, r[N];
int idx;
void solve(int x, int ed){
    if(x>ed){
        for(int i=1;i<=ed;++i)
            b[a[i]]=i;
        for(int i=1;i<=ed;++i)
            if(b[i]>a[i]){
                r[idx]=(r[idx]+1)%mod;
                return ;
            }else if(a[i]>b[i]) return ;
        return ;
    }
    for(int i=1;i<=ed;++i)
        if(!f[i]) a[x]=i, f[i]=1, solve(x+1, ed), f[i]=0;
}
int main(){
    freopen("perm.in", "r", stdin);
    freopen("perm.out", "w", stdout);
    cin>>n>>mod;
    for(int i=3;i<=n;++i)
        ++idx, solve(1, i);
    for(int i=1;i<=idx;++i)
        ans^=r[i];
    cout<<ans;
    return 0;
}
