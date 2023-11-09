#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=101;
int n,m,k;using ll=long long;
const ll mod=1e9+7;
ll dp[N][5005],sum[N];
ll sm[N][N],df[N][N];
int vis[N][N];
void dfs1(int u,int dad){
	for(int j=1;j<=k;j++)dp[u][j]=1;
	for(int v=1;v<=n;v++){
		if(v==u||v==dad||vis[u][v]==0)continue;
		dfs1(v,u);
		for(int j=1;j<=k;j++)
		dp[u][j]=
		dp[u][j]*(((sum[v]-dp[v][j]+mod)%mod*df[u][v]%mod+dp[v][j]*sm[u][v]%mod)%mod)%mod;
	}
	for(int j=1;j<=k;j++)sum[u]=(sum[u]+dp[u][j])%mod;
}
int p[N];
ll ans1;
void dfs2(int x){
	if(x==n+1){
		ll pi=1;
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(vis[i][j]){
			pi*=sm[i][j]*(p[i]==p[j])+df[i][j]*(p[i]!=p[j]);
			pi%=mod;
		}ans1=(ans1+pi)%mod;
		return;
	}for(int i=1;i<=k;i++)p[x]=i,dfs2(x+1);
}
void solve(){
	n=rd(),m=rd(),k=rd();
	if(n==2){
		ll sm=1,df=1;
		for(int i=1;i<=m;i++){
			int u=rd(),v=rd();
			df=df*rd()%mod;sm=sm*rd()%mod;
		}
		ll ans=0;
		ans=(ans+sm*k%mod+df*k%mod*(k-1)%mod)%mod;
		printf("%lld\n",ans);
		return;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)sm[i][j]=df[i][j]=1,vis[i][j]=0;
	for(int i=1;i<=m;i++){
		int u=rd(),v=rd();
		int d=rd(),s=rd();
		vis[u][v]=vis[v][u]=1;
		df[u][v]*=d,df[v][u]*=d;sm[u][v]*=s,sm[v][u]*=s;
	}
	if(m==n-1){
		dfs1(1,0);
		printf("%lld\n",sum[1]);
		return;
	}if(k<=9){
		ans1=0;dfs2(1);
		printf("%lld\n",ans1);
		return;
	}
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	int t=rd();
	while(t--)solve(); 
	return 0;
}/*
1
5 17 9
3 2 2 4
3 2 7 7
4 3 6 2
4 5 8 8
2 3 7 0
4 1 2 0
3 5 0 8
4 2 0 8
3 4 4 4
3 5 8 7
1 2 3 6
3 1 1 3
3 5 6 4
3 1 8 1
3 4 1 7
4 2 2 8
4 2 4 6

*/
