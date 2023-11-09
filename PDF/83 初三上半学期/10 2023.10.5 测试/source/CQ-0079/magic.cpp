#include<bits/stdc++.h>
using namespace std;
const int N=1024;
int n;
struct node { int l,r,c; }a[N];
int tim[N],num[N];
bool vis[N];
void dfs(int &ans,int now) {
	if(now>n) { int ant=0;
		for(int i=1;i<=n;i++) num[i]=0;
		for(int i=1;i<=n;i++) {
			int x=tim[i]; ant+=num[x];
			for(int j=a[x].l;j<=a[x].r;j++) num[j]+=a[x].c;
		} ans=max(ans,ant); return ;
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]){
			tim[now]=i; vis[i]=true;
			dfs(ans,now+1); vis[i]=false;
		}
	}
}

int f[N],cnt=0;
struct edge { int v,w,net; } eg[N<<6];
void add(int uu,int vv,int ww) { eg[++cnt]=(edge) { vv,ww,f[uu] }, f[uu]=cnt; }
int ip[N]; 
#define ppt pair<int,int>
#define mmp make_pair
priority_queue< ppt,vector<ppt>,greater<ppt> > q;
void tx() {
	int ans=0;
	for(int i=1;i<=n;i++) for(int j=a[i].l;j<=a[i].r;j++) add(i,j,a[i].c), ip[j]+=a[i].c;
	for(int i=1;i<=n;i++) q.push( mmp(ip[i],i) );
	while(!q.empty()) {
		int u=q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=f[u];i;i=eg[i].net) {
			int v=eg[i].v;
			if(!vis[v]) {
				num[v]+=eg[i].w;
				ip[v]-=eg[i].w;
				q.push( mmp(ip[v],v) );
			}
		}
	} for(int i=1;i<=n;i++) ans+=num[i];
	printf("%d",ans);
}
signed main() {
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n); bool fbi=true;
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].c), fbi&=( a[i].l=a[i].r && a[i].l==i );
	if(fbi) { puts("0"); return 0; }
	if(n<=10) { int ans=0; dfs(ans,1); printf("%d",ans); return 0; }
	tx();
	return 0;
}
/*
5
1 2 1
2 2 3
2 4 7
3 5 4
3 5 5
*/
