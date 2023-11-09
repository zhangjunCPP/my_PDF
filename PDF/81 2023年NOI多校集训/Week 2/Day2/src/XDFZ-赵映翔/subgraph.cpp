#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],b[100001],v[100001],ind[100001];
long long ansk=-1e16,ansv=-1e16,M,N,B;
void dfs(int pos,int k){
	if(pos==n+1){
		long long ng=0,mg=0,bg=0;
		for(int i=1;i<=n;i++) if(v[i]) ng++;
		for(int i=1;i<=m;i++){
			if(v[a[i]]&&v[b[i]]) mg++,ind[a[i]]++,ind[b[i]]++;
			else if(v[a[i]]) bg++,ind[a[i]]++;
			else if(v[b[i]]) bg++,ind[b[i]]++;
			else ind[a[i]]++,ind[b[i]]++;
		}
		for(int i=1;i<=n;i++){
			if(v[i]&&ind[i]<k) return;
			if(!v[i]&&ind[i]>=k) return;
		}
		long long now=M*mg-N*ng+B*bg;
		if(now>ansv) ansv=now,ansk=k;
		else if(now==ansv) ansk=max(ansk,1ll*k);
		return;
	}
	v[pos]=1;
	dfs(pos+1,k);
	v[pos]=0;
	dfs(pos+1,k);
}
int main(){
	freopen("subgraph.in","r",stdin);
	freopen("subgraph.out","w",stdout);
	
	scanf("%d%d%lld%lld%lld",&n,&m,&M,&N,&B);
	for(int i=1;i<=m;i++) scanf("%d%d",&a[i],&b[i]);
	for(int k=1;k<n;k++) dfs(1,k);
	printf("%lld %lld",ansk,ansv);
	return 0;
}
