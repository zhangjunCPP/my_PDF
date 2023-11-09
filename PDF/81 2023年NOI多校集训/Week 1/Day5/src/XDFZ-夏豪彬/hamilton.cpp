#include<bits/stdc++.h> 
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;inline int read(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
inline void FRE(){
	freopen("hamilton.in","r",stdin);
	freopen("hamilton.out","w",stdout);
}
const int maxn=1e5+5;
int n,m,cnt;
bool vis[maxn];
int flag;
vector<int> ans[maxn];
int fa[maxn],col[maxn],group[maxn],del[maxn],siz[maxn];
vector<int> a[maxn];
inline int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
inline void add(int u,int v){a[u].push_back(v);}
inline void dfs(int u,int dep,int FA,int id){
	if(dep==siz[id]+1&&FA==u){
		ans[id].push_back(siz[id]);
		for(int i=1;i<=siz[id];++i)ans[id].push_back(col[i]);
		flag++;
		return;
	}
	if(flag==id)return;
	for(int v:a[u]){
		if(flag==id)return;
		if(vis[v])continue;
		vis[v]=1;
		col[dep]=v;
		dfs(v,dep+1,FA,id);
		if(flag==id)return;
		vis[v]=0;
		col[dep]=0;
	}
	if(flag==id)return;
}
int main(){
	FRE(); 
	n=read(),m=read();
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		add(u,v);
		fa[u]=find(fa[v]);
	}
	for(int i=1;i<=n;++i){
		if(i==fa[i]){
			group[++cnt]=i;
			siz[cnt]=1;
			del[i]=cnt;
		}
	}
	for(int i=1;i<=n;++i){
		if(i!=fa[i]){
			int ff=find(i);
			siz[del[ff]]++;
		}
	}
	for(int i=1;i<=cnt;++i){
		dfs(group[i],1,group[i],i);
		if(flag!=i){
			puts("NO");
			exit(0);
		}
	}
	puts("YES");
	for(int i=1;i<=cnt;++i){
		for(int v:ans[i])printf("%d ",v);
		puts("");
	}
}
