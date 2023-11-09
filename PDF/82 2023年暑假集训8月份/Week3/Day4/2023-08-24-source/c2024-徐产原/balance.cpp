#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int> G[300005];
int n,u[300005],v[300005],ans[300005],size[300005];
int check(){
	int f;
	
	f=true;
	for(int i=1;i<n;i++)if(u[i]!=1||v[i]!=i){f=false;break;}
	if(f)return 1;
	
	f=true;
	for(int i=1;i<n;i++)if(u[i]!=i||v[i]!=i+1){f=false;break;}
	if(f)return 2;
	
	if(n<=5000)return 3;
	
	return 4;
}
void dfs(int u,int fa){
	size[u]=1;
	for(int v:G[u])if(v!=fa)
		dfs(v,u),size[u]+=size[v];
}
pair<int,int> dfs3(int u,int fa,int all){
	int maxn=0;
	pair<int,int> ans={0x3f3f3f3f,0};
	for(int v:G[u])if(v!=fa){
		ans=min(dfs3(v,u,all),ans);
		maxn=max(maxn,size[v]);
	}
	maxn=max(maxn,all-size[u]);
	return min(make_pair(maxn,u),ans);
}
void dfs2(int u,int fa){
	int son=0;
	for(int v:G[u])if(size[v]>size[son])
		son=v;
	ans[u]=dfs3(son,u,size[son]).second;
	for(int v:G[u])if(v!=fa){
		size[u]-=size[v];
		size[v]+=size[u];
		dfs2(v,u);
		size[v]-=size[u];
		size[u]+=size[v];
	}
}
void Freopen(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d%d",&u[i],&v[i]);
	int flag=check();
	if(flag==1){
		puts("2");
		for(int i=2;i<=n;i++)
			puts("1");
	}
	else if(flag==2){
		for(int i=1;i<=n;i++){
			printf("%d\n",i<=n/2?(i+1+n)/2:i/2);
		}
	}
	else{
		for(int i=1;i<n;i++)
			G[u[i]].push_back(v[i]),G[v[i]].push_back(u[i]);
		dfs(1,0);
		dfs2(1,0);
		for(int i=1;i<=n;i++)
			printf("%d\n",ans[i]);
	}
}
