#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100+5;
const int UN=(1<<12)+5;
const ll mod=1e9+7;
ll n,m,K;
ll df[N][N],sa[N][N];
bool ins[N],con[N][N];
ll f[N];
void adde(int u,int v,ll w1,ll w2){
	df[u][v]*=w1;
	sa[u][v]*=w2;
	con[u][v]=1;
	return ;
}
void dfs(int k,int fa){
	f[k]=-1;
	ins[k]=true;
	int stp=0;
	for(int to=1;to<=n;to++){
		if(!con[k][to]) continue;
		if(to==fa) continue;
		if(!ins[to]) dfs(to,k);
		stp|=(1<<to-1);
	}
	for(int u=stp;u;u=(u-1)&stp){
		ll rs1=0,rs2=0;
		for(int i=1;i<=n;i++)
			if((u>>i-1)&1)
				(rs1+=(f[i]==-1?1:f[i])*sa[k][i]%mod)%=mod;
			else
				(rs2+=(f[i]==-1?1:f[i])*df[k][i]%mod)%=mod;
		f[k]=(rs1*K%mod+rs2*K*K%mod)%mod;
	}
	return ;
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>K;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				df[i][j]=sa[i][j]=1,
				con[i][j]=ins[j]=0;
		for(int i=1;i<=m;i++){
			int u,v,w1,w2;
			cin>>u>>v>>w1>>w2;
			adde(u,v,w1,w2),adde(v,u,w1,w2);
		}
//		cout<<sa[1][2]<<'\n';
		dfs(1,0);
		cout<<f[1]<<'\n';
	}
	return 0;
}
/*
1
2 2 3
2 1 1 1
2 1 2 2
*/

