/*
抽象!(感叹词,非动词)
如果是全局询问会怎么样捏?
发现就是 +max卷积merge上去(?)
try一try
首先如果这个虚树包含1那出题人___了
+max卷积...?感觉不靠谱又不知道哪里不靠谱
ooo,在外面的叶子都是-inf
在这个树内还需要点×,我说怎么不对... 
欸...好像想得有点问题
应该选择若干个叶子.
欸....还是有问题
最小虚树啊?哦好像又没问题
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using poly=vector<ll>;
struct edge{int v;ll w;};
int testop,n,m,k,p[200010],pos[200010];
auto readq=[](int&l,int&r,int&k,ll ans){
	ans%=19260817;
	scanf("%d%d%d",&l,&r,&k);
	if(testop){
		l^=ans;l=(l%n+n)%n+1;
		r^=ans;r=(r%n+n)%n+1;
		if(l>r)swap(l,r);
		k^=ans;k=k%min(r-l+1,100)+1;
	}
};
basic_string<edge>G[200010],vt[200010];
ll wdep[200010];
int dep[200010],fa[200010][25],dfn[200010],tot;
void dfs(int u,int dad){
	dfn[u]=++tot;
	for(int i=1;i<=20;i++)
	fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto e:G[u])if(e.v!=dad)
	dep[e.v]=dep[u]+1,wdep[e.v]=wdep[u]+e.w,fa[e.v][0]=u,
	dfs(e.v,u);
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=20;i>=0;i--)
	if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
	if(u==v)return u;
	for(int i=20;i>=0;i--)
	if(fa[u][i]!=fa[v][i])
	u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
ll ans;
poly solve(int u){
	poly res(k+5,-1e18);res[0]=0;
	if(vt[u].empty())return res[1]=0,res;
	for(auto e:vt[u]){
		auto tmp=solve(e.v);
		for(ll&x:tmp)x+=e.w;
		for(int i=1;i<k;i++)
		ans=max(ans,res[i]+tmp[k-i]);
		poly a(k+5,-1e18);
		for(int i=0;i<=k;i++)
		for(int j=0;i+j<=k;j++)
		a[i+j]=max(a[i+j],res[i]+tmp[j]);
		res=a;
	}return res;
}
int main(){
	freopen("voidtree.in","r",stdin);
	freopen("voidtree.out","w",stdout);
	scanf("%*d%d%d",&testop,&n);
	for(int i=1,u,v,w;i<n;i++)
	scanf("%d%d%d",&u,&v,&w),G[u]+={v,w},G[v]+={u,w};
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	dfs(1,0),cin>>m;
	for(int l,r;m--;){
		scanf("%d%d%d",&l,&r,&k);
		if(k==1){puts("0");continue;}
		ans=-1e18;
		basic_string<int>ver;
		for(int i=l;i<=r;i++)ver+=p[i];
		auto cmp=[](int u,int v){return dfn[u]<dfn[v];};
		sort(begin(ver),end(ver),cmp);
		for(int i=0;i<r-l;i++)
		ver+=lca(ver[i],ver[i+1]);
		sort(begin(ver),end(ver),cmp);
		ver.erase(unique(begin(ver),end(ver)),end(ver));
		for(int i=0;i+1<ver.size();i++){
			int qwq=lca(ver[i],ver[i+1]);
			vt[qwq]+={ver[i+1],wdep[ver[i+1]]-wdep[qwq]};
		}solve(ver[0]);
		cout<<ans<<endl;
		for(int u:ver)vt[u]={};
	}
	return 0;
}
