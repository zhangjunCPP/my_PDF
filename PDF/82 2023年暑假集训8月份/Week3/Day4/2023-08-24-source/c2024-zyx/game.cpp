#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,int> PII;
int n,m,v[200001],ago[200001],now[200001],fr[200001],vis[200001];
long long dp[200001];
struct line{
	long long b,k;
	long long operator()(long long d){
		return b*d+k;
	}
}f[200001];
struct tree{
	int id[800001];
	void update(int rt,int l,int r,int k){
		if(!id[rt]){
			id[rt]=k;
			return;
		}
		int mid=(l+r)>>1;
		if(f[id[rt]](ago[mid])<f[k](ago[mid])) swap(id[rt],k);
		if(f[id[rt]](ago[l])<f[k](ago[l])) update(rt*2,l,mid,k);
		if(f[id[rt]](ago[r])<f[k](ago[r])) update(rt*2+1,mid+1,r,k);
	}
	PII query(int rt,int l,int r,int x){
		PII res={-1e16,-1e16};
		int mid=(l+r)>>1;
		if(id[rt]) res={f[id[rt]](ago[x]),-f[id[rt]].b};
		if(l==r) return res;
		if(x<=mid) res=max(res,query(rt*2,l,mid,x));
		else res=max(res,query(rt*2+1,mid+1,r,x));
		return res;
	}
}t;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&v[i]),ago[i]=v[i];
	reverse(v+1,v+1+n);
	sort(ago+1,ago+1+n);
	m=unique(ago+1,ago+1+n)-ago-1;
	for(int i=1;i<=n;i++) now[i]=lower_bound(ago+1,ago+1+m,v[i])-ago;
	f[1]={-1,0};
	t.update(1,1,m,1);
	for(int i=2;i<=n;i++){
		PII res=t.query(1,1,m,now[i]);
		dp[i]=1ll*v[i]*i+res.first;
		fr[i]=res.second;
		f[i]={-i,dp[i]};
		t.update(1,1,m,i);
	}
	printf("%lld\n",dp[n]);
	int x=n;
	while(x) vis[x]=1,x=fr[x];
	for(int i=n;i>=1;i--) if(!vis[i]) printf("%d ",n-i+1);
	for(int i=1;i<=n;i++) if(vis[i]) printf("%d ",n-i+1);
	return 0;
}
