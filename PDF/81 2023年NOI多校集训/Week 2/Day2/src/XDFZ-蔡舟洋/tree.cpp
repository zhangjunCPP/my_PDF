#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;
const int N=2e5+5; 
int n;
vector<int> E[N];
int ans,dis[11][11];
void dfs(int k,int key){
	if(k==n+1){
		int maxn=0;
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(((key>>(i-1))&1)==((key>>(j-1))&1))maxn=max(maxn,dis[i][j]);
		ans+=maxn;
		return;
	}
	dfs(k+1,key<<1),dfs(k+1,key<<1|1); 
}
void solve1(){
	memset(dis,63,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		E[u].push_back(v),E[v].push_back(u);
		dis[u][v]=dis[v][u]=1;
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	dfs(1,0);
	printf("%d",ans);
}
ll ksm(ll a,ll b){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
ll jc[N],inv[N];
ll C(ll a,ll b){return jc[a]*inv[b]%mod*inv[a-b]%mod;}
void solve2(){
	jc[0]=1,inv[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]%mod,inv[i]=ksm(jc[i],mod-2);
	ll ans=n/2*2;
//	if(n&1)ans=(ans*2)%mod;
	for(int i=n/2+1;i<n;i++){
		ans=(ans+2*ksm(2,(i-n/2)*2-1));
	}
	printf("%lld",ans);
}
void solve3(){
	if(n==3)puts("12");
	else if(n==2)puts("2");
	else printf("%lld",ksm(2,n+1));
}
int c[N];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	if(n<=10)return solve1(),0;
	int f1=1,f2=1;
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),f1&=(u==i&&v==i+1),c[u]++,c[v]++;
	if(c[1]==n-1)return solve3(),0; 
	if(f1)return solve2(),0;
	return 0;
}
/*
5
1 2
2 3
3 4
4 5
*/
