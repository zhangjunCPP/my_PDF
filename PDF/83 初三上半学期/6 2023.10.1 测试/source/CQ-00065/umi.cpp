#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+10;
const int MAXM=1e6+10;
const int mod=998244353;
//template <typename T>
//inline void read(T &x){
//	bool f=0; x=0; char ch=getchar();
//	while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
//	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
//	x=f?-x:x;
//}
//template <typename T,typename ...Args>
//inline void read(T &x,Args &...args){read(x); read(args...);}
int n,m,id,len;
bool win[MAXN],mine[MAXN];
int fa[MAXN];
vector<int> G[MAXN<<1];
bool flag=false;
void Find(int u,int father,const int sta,const int end){
	if(flag) return ;
	fa[u]=father;
	if(u==end){
		flag=true;
		int uu=u; 
		while(uu!=sta){
			mine[++len]=win[uu];
			uu=fa[uu];
		}
		mine[++len]=win[sta];
		return ;
	}
	for(auto v:G[u]){
		if(v==father) continue;
		Find(v,u,sta,end);
		if(flag) return ;
	}
}
int ans=0; bool vis[MAXN];
void dfs(int k,int sum,int last){
	if(k==len+1){ans=(ans+sum)%mod; return ;}
	for(int i=last+1;i<=m;i++){
		if(vis[i]) continue;
		vis[i]=true;
		if(mine[k]==0) dfs(k+1,sum*(m-i),i);
		else dfs(k+1,sum*(i-1),i); 
		vis[i]=false;
	}
}
signed main(){
	freopen("umi.in","r",stdin);
	freopen("umi.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&id);
	for(int i=1;i<=n;i++) scanf("%d",&win[i]);
	for(int i=1;i<=n-1;i++){
		int u,v; scanf("%lld%lld",&u,&v);
		G[u].push_back(v); G[v].push_back(u);
	}
	int q; scanf("%lld",&q);
	while(q--){
		len=0; flag=false;
		memset(mine,0,sizeof(mine)); 
		memset(fa,0,sizeof(fa));
		int a,b; scanf("%lld%lld",&a,&b);
		Find(a,0,a,b);
		reverse(mine+1,mine+len+1);
		dfs(1,1,0);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
5 6 0
1 1 1 1 1
1 2
1 3
2 4
3 5
*/
