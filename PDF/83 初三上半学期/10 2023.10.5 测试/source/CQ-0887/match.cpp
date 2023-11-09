/*
A match
它只有两组数据还不好妄下定论，但是这个限制非常严苛注定了其性质的独特
准确来说，在这样的限制下，所谓“皮配”很可能只有两种情况：
1.菊花形，即一个点连了若干个点，此时答案即为度数最大的点的度数
2.三角形，即三元环，此时答案一定为 $3$，可以通过DFS轻松判断
那么这道题就解决了
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
struct edge{int v,nex;};
edge e[N];
int fir[N],ent;
inline void add(int u,int v)
{
	e[++ent]={v,fir[u]};
	fir[u]=ent;
	return;
}
int deg[N],fa[N],dep[N],ans;
void DFS(int u)
{
	if(ans>2)return;
	for(int i=fir[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa[u])continue;
		if(dep[v]){if(fa[fa[u]]==v||(fa[u]==fa[v]&&fa[u]))ans=3,printf("%d %d %d\n",u,v,fa[u]);return;}
		fa[v]=u,dep[v]=dep[u]+1,DFS(v);
	}
	return;
}
inline void INIT(int n){for(int i=1;i<=n;i++)fir[i]=deg[i]=fa[i]=dep[i]=0;ent=0;return;}//小心多测！清空不能memset！
inline void solve()
{
	int n,m;
	scanf("%d%d",&n,&m);INIT(n);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		deg[u]++,deg[v]++;
		add(u,v),add(v,u);
	}
	ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,deg[i]);
	if(ans<3)for(int i=1;i<=n;i++)if(!dep[i])dep[i]=1,DFS(i);
	printf("%d\n",ans);
	return;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}