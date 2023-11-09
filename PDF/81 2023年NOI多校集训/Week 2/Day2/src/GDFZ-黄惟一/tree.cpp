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
const int N=2e6+7,M=-1,inf=0x3f3f3f3f,mod=1e9+7;
int n,m,dep[N],pw[N];
pii dis[N<<1];
bool vis[N];
int tot,head[N];
struct node{
	int to,nxt;
}e[N<<1];
vector<int> g;
inline void add(int u,int v){
	e[++tot]={v,head[u]};
	head[u]=tot;
}
int rt,st=-1;
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	if(dep[u]>dep[rt])
		rt=u;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==f||i==st||i==st+1)
			continue;
		dfs(v,u);
	}
}
bool flag=false;
void find(int u,int f){
	g.eb(u);
	if(u==rt){
		flag=true;
		return;
	}
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==f)
			continue;
		find(v,u);
		if(flag)
			return;
	}
	g.pop_back();
}
void calc(int u,int f,int op){
	dis[u+op*n].se=u;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==f)
			continue;
		dis[v+op*n].fi=dis[u+op*n].fi+1;
		calc(v,u,op);
	}
}
inline int qpow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)
			ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ret;
}
void solve(){
	scanf("%d",&n);
	if(n==2){
		puts("1");
		return;
	}
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	int s=rt;
	rt=0;
	dfs(s,0);
	m=dep[rt];
	find(s,0);
	bool sp=false;
	if(g.size()%2==0){
		n++,sp=true;
		int a=g[g.size()/2],b=g[g.size()/2-1];
		if(a>b)
			swap(a,b);
		add(n,a);
		add(n,b);
		for(int i=1;i<=tot;i+=2){
			int u=e[i].to,v=e[i+1].to;
			if(u>v)
				swap(u,v);
			if(u==a&&v==b){
				st=i;
				break;
			}
		}
		s=n;
	}else 
		s=g[g.size()/2];
	calc(*g.begin(),0,0);
	calc(g.back(),0,1);
	sort(dis+1,dis+2*n+1,greater<pii>());
	pw[0]=1;
	for(int i=1;i<=n;i++)
		pw[i]=pw[i-1]*2ll%mod;
	n-=sp;
	int ans=pw[n-1]*(g.size()-1)%mod;
	for(int i=3;i<=n*2;i++){
		if(dis[i].se==n+1)
			continue;
		if(vis[dis[i].se]){
			ans=(ans+1ll*pw[n-i+2]*dis[i].fi%mod)%mod;
			break;
		}
		ans=(ans+1ll*pw[n-i+1]*dis[i].fi%mod)%mod;
		vis[dis[i].se]=true;
	}
	printf("%d\n",ans);
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t=1;
	//	scanf("%d",&t);
	while(t--)
		solve();
}

