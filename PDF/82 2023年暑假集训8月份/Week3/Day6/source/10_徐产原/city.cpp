#include<bits/stdc++.h>
using namespace std; 
//计算空间 计算空间 计算空间 计算空间 计算空间 计算空间 计算空间 计算空间 计算空间 计算空间 计算空间 计算空间 计算空间 计算空间 
#define ls rt<<1
#define rs rt<<1|1
int n,k;
//线段树2n个点，城镇n个点，3n个点
 
vector<int> G[200005],E[600005],city[200005];
struct BIT{
	int tr[200005],a[200005],b[200005],top;
	void add(int i,int x){a[++top]=i,b[top]=x;for(;i<=n;i+=(i&-i))tr[i]+=x;}
	void add1(int i,int x){for(;i<=n;i+=(i&-i))tr[i]+=x;}
	int ask(int i){int ans=0;for(;i;i-=(i&-i))ans+=tr[i];return ans;}
	void init(){while(top)add1(a[top],-b[top]),--top;}
}siz,gone;//是否存在？ 是否 

int size[200005],dis[200005],son[200005],dad[200005],cnt;
int dfn[200005],rnk[200005],top[200005],go[200005][20];//18
void dfs1(int u,int fa){
	size[u]=1;
	dad[u]=fa;
	go[u][0]=fa;
	dis[u]=dis[fa]+1;
	for(int i=1;i<=18;i++)go[u][i]=go[go[u][i-1]][i-1];
	for(int v:G[u])if(v!=fa){
		dfs1(v,u);
		size[u]+=size[v];
		if(size[v]>size[son[u]])son[u]=v;
	}
}
void dfs2(int u,int t){
	top[u]=t;
	dfn[u]=++cnt;
	rnk[cnt]=u;
	if(son[u]){
		dfs2(son[u],t);
		for(int v:G[u])if(v!=dad[u]&&v!=son[u])
			dfs2(v,v);
	}
}

int ID[200005],cid[200005],tr[800005],tot;//注意，在线段树上的编号是DFN序 
void build(int rt,int l,int r){
	if(l==r){
		ID[rnk[l]]=tr[rt]=++tot;
		return;
	}
	tr[rt]=++tot;
	int m=(l+r)>>1;
	build(ls,l,m),build(rs,m+1,r);
	E[tr[rt]].push_back(tr[ls]);
	E[tr[rt]].push_back(tr[rs]);
	//printf("%d %d\n",tr[rt],tr[ls]);
	//printf("%d %d\n",tr[rt],tr[rs]);
}
void add_edge(int rt,int l,int r,int L,int R,int x){
	if(L<=l&&r<=R)
		return E[x].push_back(tr[rt]),void();//printf("%d %d\n",x,tr[rt]),void();
	int m=(l+r)>>1;
	if(m>=L)add_edge(ls,l,m,L,R,x);
	if(m<R)add_edge(rs,m+1,r,L,R,x);
}

void work(int k){
	siz.init(),gone.init();
	//printf("%d\n",k);
	for(int p:city[k]){//沿着根 
		while(p){
			siz.add(dfn[top[p]],1);
			siz.add(dfn[p]+1,-1);
			p=dad[top[p]];
		}
	}
	for(int p:city[k]){
		int all=city[k].size();//所有的个数 
		if(gone.ask(p))continue;//已经走过 
		//cout<<dfn[top[p]]<<" "<<dfn[top[p]]<<endl;
		while(p&&!gone.ask(dfn[top[p]])&&siz.ask(dfn[top[p]])!=all){//没走过，没包含所有点 
		//	cout<<top[p]<<"     "<<p<<endl;
			add_edge(1,1,n,dfn[top[p]],dfn[p],cid[k]);
			gone.add(dfn[top[p]],1);
			gone.add(dfn[p]+1,-1);
			p=dad[top[p]];
		}
		if(!p)continue;
		int q=p;//从q走，走到第一个没走过或者包含所有点的点 
		for(int i=18;i>=0;i--)if(go[q][i]&&siz.ask(dfn[go[q][i]])!=all&&!gone.ask(dfn[go[q][i]]))q=go[q][i];
		if(siz.ask(dfn[q])!=all)q=dad[q];
		add_edge(1,1,n,dfn[q],dfn[p],cid[k]);
		gone.add(dfn[q],1);
		gone.add(dfn[p]+1,-1);
	}
}

int low[600005],in[600005],st[600005],aff[600005],value[600005],tp,num,col;
void tarjan(int u){
	in[u]=1;
	st[++tp]=u;
	dfn[u]=low[u]=++num;
	for(int v:E[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(in[v])low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		int v;
		++col;
		//printf("%d\n",col);
		do{
			v=st[tp--];
			//printf("%d ",v);
			in[v]=0;
			value[col]+=(cid[1]<=v&&v<=cid[k]);
			aff[v]=col;
		}while(v!=u);
		//puts("");
	}
}
void Freopen(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;i++)
		scanf("%d%d",&u,&v),
		G[u].push_back(v),
		G[v].push_back(u);
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=k;i++)cid[i]=++tot;
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		E[ID[i]].push_back(cid[x]);
		city[x].push_back(i);
	}
	for(int i=1;i<=k;i++)work(i);
	for(int i=1;i<=tot;i++)dfn[i]=low[i]=0;
	for(int i=1;i<=tot;i++)if(!dfn[i])tarjan(i);
	for(int u=1;u<=tot;u++)for(int v:E[u])if(aff[u]!=aff[v])
		++in[aff[u]];//printf("%d %d\n",aff[u],aff[v]);//其实是出度 
	int ans=0x3f3f3f3f;
	for(int u=1;u<=col;u++)if(!in[u])ans=min(ans,value[u]);
	printf("%d\n",ans-1);
}
/*
8 4
1 2
2 3
3 4
4 5
5 6
6 7
7 8
1
2
3
4
1
2
3
4
*/
