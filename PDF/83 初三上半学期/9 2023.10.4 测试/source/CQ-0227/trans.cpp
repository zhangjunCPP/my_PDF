#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7,N=110;
ll pw(ll x,int cnt){
	ll ans=1;
	while(cnt){
		if(cnt&1)ans=ans*x%mod;
		x=x*x%mod;
		cnt>>=1;
	}
	return ans;
}
ll C(int n,int m){
	if(n<m)return 0;
	ll ans=1;
	for(int i=n;i>n-m;i--)ans=ans*i%mod;
	ll s=1;
	for(int i=1;i<=m;i++)s=s*i%mod;
	return ans*pw(s,mod-2)%mod;
}
struct node{
	int to,nxt,w1,w2;
}e[N<<1];
int cnt,head[N];
void add(int u,int v,int w1,int w2){
	e[++cnt]={v,head[u],w1,w2};
	//cout<<u<<" "<<v<<" "<<w1<<" "<<w2<<"*\n";
	head[u]=cnt;
}
int n,m,vis[N];
ll dp[N][N],s[N][N];
ll sol(int k){
	memset(dp,0,sizeof(dp));memset(s,0,sizeof(s));memset(vis,0,sizeof(vis));
	for(int i=1;i<=k;i++)dp[1][i]=1,s[1][i]=i;
	queue<int>q;q.push(1);
	int las=0;
	while(!q.empty()){
		int x=q.front();q.pop();if(vis[x])continue;
		vis[x]=1;las=x;
		for(int i=1;i<=k;++i){
			for(int j=head[x];j;j=e[j].nxt){
				int v=e[j].to,w1=e[j].w1,w2=e[j].w2;
				if(vis[v])continue;
				dp[v][i]+=(s[x][k]-dp[x][i]+mod)%mod*w1%mod+dp[x][i]*w2%mod;
				dp[v][i]=dp[v][i]%mod;
				s[v][i]=(s[v][i-1]+dp[v][i])%mod;
				q.push(v);
			}
		}
	}
	return s[las][k];
}
ll b[N][N],b2[N][N];
int ve[N][N];
void solve(){
	int k;
	scanf("%d%d%d",&n,&m,&k);
	memset(b,0,sizeof(b));
	ll ans=0;memset(head,0,sizeof(head));cnt=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)b[i][j]=b2[i][j]=1,ve[i][j]=0;
	for(int i=1;i<=m;i++){
		int x,y,w1,w2;scanf("%d%d%d%d",&x,&y,&w1,&w2);
		ve[x][y]=ve[y][x]=1;
		b[y][x]=b[x][y]=b[x][y]*w1%mod;
		b2[y][x]=b2[x][y]=b2[x][y]*w2%mod;
		
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(ve[i][j])add(i,j,b[i][j],b2[i][j]);
	ll sta=0;
	for(int i=1;i<=min(k,n);i++){
		sta=mod-sta;
		ll now=sol(i);sta=(sta+now)%mod;
		//cout<<sta<<"\n";
		ans=(ans+sta%mod*C(k,i)%mod)%mod;
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	int T;scanf("%d",&T);
	
	while(T--)solve();
	return 0;
}
