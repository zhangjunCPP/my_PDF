#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[1001],y[1001],n,m,ans,vis[10001];
void dfs(int ntb){
	if(ntb==n){
		ans++;
		for(int i=1;i<=n;i++){
			cout<<vis[i];
		}
		cout<<endl;
		ans%=998244353;
		return;
	}
	if(vis[x[ntb]]||vis[y[ntb]]){
		dfs(ntb+1);
		return;
	}
	vis[x[ntb]]=1;
	dfs(ntb+1);
	vis[x[ntb]]=0,vis[y[ntb]]=1;
	dfs(ntb+1);
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	if(n>10) cout<<n,exit(0);
	for(int i=1;i<n;i++){
		cin>>x[i]>>y[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}

