#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
const int mod=1e9+7;
int x[N],y[N],diff[N],same[N];
int n,m,k;
int country[N];
int ans;
void dfs(int now){
    if(now>n) {
        int tmp=1;
        for(int i=1;i<=m;i++) {
            if(country[x[i]]==country[y[i]]) tmp=(tmp*same[i])%mod;
            else tmp=(tmp*diff[i])%mod;
        }
        ans=(ans+tmp)%mod;
        return;
    }
    for(int i=1;i<=k;i++) {
        country[now]=i;
        dfs(now+1);
    }
    return;
}
void solve(){
    ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>x[i]>>y[i]>>diff[i]>>same[i];
	if(n==2){
        int ans1=1,ans2=1;
        for(int i=1;i<=m;i++) {
            ans1=ans1*same[i]%mod;
            ans2=ans2*diff[i]%mod;
        }
        ans=(k*ans1)%mod;
        ans=(ans+k*(k-1)%mod*ans2%mod)%mod;
        cout<<ans<<"\n";
        return;
	}
	else {
        dfs(1);
        cout<<ans<<"\n";
    }
}
signed main(){
    freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
}
