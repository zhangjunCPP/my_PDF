//8:48来了
//题意:进行最小次数的合并使得某个col形成连通块
//想一下吧,总数一定,n=2e5(根号能过),有无可能根号分治?
//换句话说要找到一个连通块,使其包含最小的col数(且要包含完每种col) 
//二分能行吗
//不过是不是可以这样啊:对每种col在他的内部的异色都连接起来
//然后不就是算最小连通块吗
//不对应该是算它能到达几个点 
//首先连边就没法连...
//更别说缩点了...
//缩点后是只用关注无出边的块?
//怎么缩点捏... 
//若一个colA被完全包含在B中,为什么不用colA?
//若一个colA被不完全包含在B中,就可以缩了!
//好像不咋会做,先写个暴力(9:11)
//好像有个性质:只用将不完全包含的merge起来就能得到scc
//9:41暴力过了样例 
//不过那个性质能不能证一下
//算了先来写下sub3:链
//链的部分分应该很关键吧
//emm...
//考虑这样一件事情
//算了先跑去T3(9:46)
//回来了(10:43)
//回顾一下那个性质:应该是因为若a->b,b->c,c->a,则b包含a,c包含b,而a包含c,这时中间肯定有其它边
//如何判断两个col是否相互包含呢?
//直接用点神奇数据结构
//在链上不是只需要判端点用lowerbound吗?
//那么我只需要O(nlogn)就可以在链上求出一个dsu
//我在这样的过程中要么就排除了它整个集合,要么就知道它是待选项 
//时间全花在了找在自己里面的且没在自己集合里的有什么上
//如何优化这个?
//不会是这个用根号分治吧/jk
//大于根号暴力搜整棵树都行 
//小于的呢?小于的如何跳必要的点呢?
//用并查集维护到上面应该是什么? 
//不对啊用并查集维护到上面应该是什么不是都适用吗!!!!
//开!写!
//不对直接排除是错的
//但是现在无论如何都有了一个记录vis的方式
//这么搞应该...是对的?
//有问题,还要跳过被自己完全包含的吧
//emm...好像不是很好整
//又回到根号分治?
//或许从大到小排就可以啦?
//试一试吧,试一试
//但是判相互包含很麻烦吧(11:23)
//这点时间没法写
//试着写链!
//但是链也避免不了访问被完全包含的啊...
//哦哦哦,不是要相互包含吗,我找r最远的来merge!( 1 1 : 3 8 )
//好像也不对啊....
//哦哦哦,倍增一下来搞左右端点然后查有几个?(  1  1  :  4  8) 
//emm...其实也用不上倍增 
//欸还是不对,应用区间修改线段树 
//好像也不对,但是only 10min!!!!
//欸之前的好像是对的 
#include<bits/stdc++.h>
using namespace std;
int n,k,col[200010];
vector<int>G[200010];
namespace task12{
	int sum[1010],in[1010],out[1010],tot;
	int bein[1010][1010],fa[1010],gd[1010],sz[1010];//i是否在j中
	int fr(int x){return x==fa[x]?x:fa[x]=fr(fa[x]);}
	void dfs_dfn(int u,int fa){
		in[u]=++tot;
		for(int v:G[u])if(v!=fa)dfs_dfn(v,u);
		out[u]=tot;
	}
	void make_bein(int curcol){
		for(int i=1;i<=n;i++)
		sum[in[i]]=col[i]==curcol;
		for(int i=1;i<=n;i++)
		sum[i]+=sum[i-1];
		for(int i=1;i<=n;i++){
			int cnt=sum[n]-(sum[out[i]]-sum[in[i]-1])>0;
			for(int v:G[i])if(in[v]>in[i])cnt+=sum[out[v]]-sum[in[v]-1]>0;
			if(col[i]!=curcol&&cnt>1)bein[col[i]][curcol]=1;
		}
	}
	void solve(){
		dfs_dfn(1,0);
		for(int i=1;i<=k;i++)make_bein(i),gd[i]=1,fa[i]=i,sz[i]=1;
		for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
		if(bein[i][j]&&bein[j][i]){
			int a=fr(i),b=fr(j);
			if(a!=b)sz[a]+=sz[b],fa[b]=a;
		}
		for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
		if(bein[i][j]&&fr(i)!=fr(j))gd[fr(j)]=0;
		int ans=1e9;
		for(int i=1;i<=k;i++)if(fa[i]==i&&gd[i])ans=min(ans,sz[i]-1);
		cout<<ans;
	}
}
//namespace solveitbyluck{
//	struct dsu_t{
//		int fa[200010];
//		int fr(int x){return fa[x]?fa[x]=fr(fa[x]):x;}
//		void merge(int x,int y){
//			if((x=fr(x))!=(y=fr(y)))
//			fa[x]=y;
//		}
//	}jp,blk;
//	vector<int>node[200010];
//	int treefa[200010],vis[200010],ans=1e9;
//	void del(int c){
//		for(int x:node[c])
//		jp.merge(x,treefa[x]);
//	}
//	void dfs(int u){for(int v:G[u])if(v!=treefa[u])treefa[v]=u,dfs(v);} 
//	void trylink(int u){
//		queue<int>q;
//		
//	}
//	void solve(){
//		treefa[1]=n+1,dfs(1);
//		for(int i=1;i<=n;i++)
//		node[col[i]].push_back(i);
//		
//	}
//}
//namespace task3{
//	using pii=pair<int,int>;
//	vector<int>pos[200010];
//	pii mi[200010<<2],mx[200010<<2];int N;
//	void upd(int p,pii x){for(p+=N,mi[p]=mx[p]=x;p>>=1;mx[p]=max(mx[p<<1],mx[p<<1|1]),mi[p]=min(mi[p<<1],mi[p<<1|1]));}
//	pii querymx(int l,int r){
//		pii ret{};
//		for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1){
//			if(~l&1)ret=max(ret,mx[l^1]);
//			if(r&1)ret=max(ret,mx[r^1]);
//		}return ret;
//	}
//	pii querymi(int l,int r){
//		pii ret{};
//		for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1){
//			if(~l&1)ret=min(ret,mi[l^1]);
//			if(r&1)ret=min(ret,mi[r^1]);
//		}return ret;
//	}
//	void putto(){
//		vector<int>tmp(n+5);
//		for(int i=1;i<=n;i++)
//		if(G[i].size()==1){
//			for(int u=i,las=0,p=1;u;u=G[u][0]^G[u][1]^las,p++)tmp[p]=col[u];
//			break;
//		}copy_n(begin(tmp)+1,n,col+1);
//	}
//	int vis[200010],fa[200010],sz[200010],mxr[200010],mil[200010];
//	int fr(int x){return fa[x]?fa[x]=fr(fa[x]):x;}
//	void merge(int x,int y){
//		if((x=fr(x))!=(y=fr(y)))
//		fa[y]=x,sz[x]+=sz[y];
//	}
//	struct node_t{int l,r,id;};
//	void solve(){
//		fill_n(mi+1,mi+n*4+1,pii{1e9,0});
//		putto();
//		for(int i=1;i<=n;i++)pos[col[i]].push_back(i);
//		for(int i=1;i<=k;i++)sz[i]=1;
//		vector<node_t>qwq;
//		for(int i=1;i<=k;i++)upd(pos[newl]);
//		for(int i=1;i<=k;i++)
//		if(!pos[i].empty())qwq.push_back({pos[i].front(),pos[i].back(),i});
//		sort(begin(qwq),end(qwq),[](const node_t&x,const node_t&y){return x.l<y.l;});
//		for(auto x:qwq)if(!vis[x.id]){
//			int newl=querymi(x.l,x.r).second;
//			if(!newl||pos[newl])mil[x.id]=;
//		}
//	}
//}
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++)
	scanf("%d%d",&u,&v),G[u].push_back(v),G[v].push_back(u);
	for(int i=1;i<=n;i++)scanf("%d",&col[i]);
	if(n<=1000){task12::solve();return 0;}
	return 0;
}
