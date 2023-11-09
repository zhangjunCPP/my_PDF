#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int n,m,u,v,q,id,a[100001],st[100001][21],val[100001][21],dep[100001];
long long pre[200001],inv[200001];
vector <int> G[100001];
const int mod=998244353;
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	st[x][0]=f;
	val[x][0]=(a[x]^1);
	for(int i=1;i<=20;i++) st[x][i]=st[st[x][i-1]][i-1],val[x][i]=val[x][i-1]+val[st[x][i-1]][i-1];
	for(auto y:G[x]) if(y!=f) dfs(y,x);
}
long long power(long long a,long long b){
	long long res=1;
	for(;b;b>>=1){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
	}
	return res;
}
long long C(int n,int m){
	if(n<0||m<0||m>n) return 0;
	else return pre[n]*inv[m]%mod*inv[n-m]%mod;
}
PII lca(int u,int v){
	int r1=0,r2=0;
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;i--) if(dep[st[u][i]]>=dep[v]) r1+=(1<<i),r2+=val[u][i],u=st[u][i];
	if(u==v) return {r1+1,r2+(a[v]^1)};
	for(int i=20;i>=0;i--) if(st[u][i]!=st[v][i]) r1+=2*(1<<i),r2+=val[u][i]+val[v][i],u=st[u][i],v=st[v][i];
	return {r1+3,r2+(a[st[u][0]]^1)+(a[u]^1)+(a[v]^1)};
}
int main(){
	freopen("umi.in","r",stdin);
	freopen("umi.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&id);
	pre[0]=inv[0]=1;
	for(int i=1;i<=m;i++) pre[i]=1ll*i*pre[i-1]%mod;
	for(int i=1;i<=m;i++) inv[i]=power(pre[i],mod-2);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=2;i<=n;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&u,&v);
		PII now=lca(u,v);
//		cout<<C(m,now.first)<<" "<<now.first<<" "<<now.second<<endl;
		printf("%lld\n",C(m,now.first*2));
//		if(now.second==0||now.second==now.first) printf("%lld\n",1ll*C(m,now.first*2)*(max(1,2*max(now.second,now.first-now.second)-2*min(now.second,now.first-now.second)-))%mod);
//		else printf("%lld\n",1ll*C(m,now.first*2)*(max(1,2*max(now.second,now.first-now.second)-2*min(now.second,now.first-now.second)-1))%mod);
	}
	return 0;
}
