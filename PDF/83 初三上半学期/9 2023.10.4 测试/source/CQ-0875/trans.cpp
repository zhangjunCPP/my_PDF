#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int MOD=1e9+7,N=105;
int n,m,k;
int ad(int x,int y){ x+=y; if(x>=MOD) x-=MOD; if(x<0) x+=MOD; return x; }
void addd(int &x,int y){ x+=y; if(x>=MOD) x-=MOD; }
struct node{
	int u,v,d,s;
}cn[N];
int bel[15],ans;
vector<int> diff[15];
void dfs(int now){
	if(now==n+1){
		++ans;
		return;
	}
	for(int i=1;i<=k;++i){
		for(auto x:diff[now]) if(x<=now&&bel[x]==i) continue;
		bel[now]=i;
		dfs(now+1);
	}
}
int cnt=0,head[N];
struct use{
	int nxt,v,d,s;
}tree[N<<1];
void add(int u,int v,int d,int s){
	tree[++cnt]={head[u],v,d,s},head[u]=cnt;
	tree[++cnt]={head[v],u,d,s},head[v]=cnt;
}
int dp[N][5005],sum[N];
void dfs1(int x,int fa){
	sum[x]=0; for(int i=1;i<=k;++i) dp[x][i]=1; 
	for(int i=head[x],y;i;i=tree[i].nxt) if((y=tree[i].v)!=fa){
		dfs1(y,x);
		for(int col=1;col<=k;++col) dp[x][col]=1ll*dp[x][col]*ad(1ll*tree[i].d*ad(sum[y],-dp[y][col])%MOD,1ll*tree[i].s*dp[y][col]%MOD)%MOD;
	}
	for(int col=1;col<=k;++col) addd(sum[x],dp[x][col]);//,cout<<x<<" "<<col<<": "<<dp[x][col]<<endl;
}
void Init(){
	ans=0;
	if(n<=10) for(int i=1;i<=n;++i) diff[i].clear();
	if(n>10){
		cnt=0;
		for(int i=1;i<=n;++i) head[i]=0;
	}
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);	
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		Init();
		if(n==2){
			int ans1=1,ans2=1;
			for(int i=1,u,v,d,s;i<=m;++i) scanf("%d%d%d%d",&u,&v,&d,&s),ans2=1ll*ans2*d%MOD,ans1=1ll*ans1*s%MOD;
			ans1=1ll*ans1*k%MOD,ans2=1ll*ans2*k%MOD*(k-1)%MOD;
			printf("%d\n",ad(ans1,ans2));
			continue;
		}
		bool flag=false;
		for(int i=1;i<=m;++i) scanf("%d%d%d%d",&cn[i].u,&cn[i].v,&cn[i].d,&cn[i].s),flag|=(cn[i].d!=1||cn[i].s!=0);
		if(!flag){
			for(int i=1;i<=m;++i) diff[cn[i].u].pb(cn[i].v),diff[cn[i].v].pb(cn[i].u);
			dfs(1);
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=m;++i) add(cn[i].u,cn[i].v,cn[i].d,cn[i].s);
		dfs1(1,0);
		printf("%d\n",sum[1]);
	}
	
	return 0;
}
