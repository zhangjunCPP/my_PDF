#include<bits/stdc++.h>
using namespace std;
namespace my_std{
#define mems(x,y) memset(x,y,sizeof x)
#define Mp make_pair
#define eb emplace_back
#define gc getchar
#define pc putchar
#define fi first
#define se second
	typedef long long ll;
	typedef pair<int,int> pii;
	inline int read(){
		int x=0,f=1;
		char c=gc();
		while(!isdigit(c)){
			if(c=='-')
				f=-1;
			c=gc();
		}
		while(isdigit(c)){
			x=x*10+c-48;
			c=gc();
		}
		return x*f;
	}
}
using namespace my_std;
const int N=4e3+7,M=-1,inf=0x3f3f3f3f,mod=0;
int n,m,c[N],dp[N][N];
int tot,head[N];
struct node{
	int to,nxt;
}e[N<<1];
vector<int> g,h[N];
inline void add(int u,int v){
	e[++tot]={v,head[u]};
	head[u]=tot;
}
void dfs(int u,int f,int rt){
	dp[u][rt]=1;
	for(int i:g){
		if(c[i]<c[u])
			dp[u][rt]=max(dp[u][rt],dp[i][rt]+1);
	}
	g.eb(u);
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==f)
			continue;
		dfs(v,u,rt);
	}
	g.pop_back();
}
void find(int u,int f){
	g.eb(u);
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==f)
			continue;
		find(v,u);
	}
}
void solve(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
		dfs(i,0,i);
	int ans=inf;
	for(int u=1;u<=n;u++){
		int res=0;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			g.clear();
			find(v,u);
			for(int j:g){
				for(int k:g)
					res=max(res,dp[j][k]);
			}
		}
		ans=min(ans,res);
	}
	printf("%d\n",ans);
}
signed main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	int t=1;
	//	scanf("%d",&t);
	while(t--)
		solve();
}

