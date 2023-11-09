#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=3e5+10;
int n,head[N],cnt,dep[N],siz[N],son[N],cson[N],ans[N],st[N][20],flag1,flag2;
struct node{
	int to,next;
}e[N<<1];
void add(int u,int v){e[++cnt].to=v,e[cnt].next=head[u],head[u]=cnt;}
void dfs(int u,int f){
	dep[u]=dep[f]+1,siz[u]=1,st[u][0]=f;
	for(int i=1;i<20;++i)st[u][i]=st[st[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==f)continue;
		dfs(v,u),siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])cson[u]=son[u],son[u]=v;
	}
}
int get(int u,int k){
	for(int i=19;~i;--i)
		if(dep[st[u][i]]>=k)u=st[u][i];
	return u;
}
int LCA(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	v=get(v,dep[u]);
	if(u==v)return u;
	for(int i=19;~i;--i)
		if(st[u][i]!=st[v][i])u=st[u][i],v=st[v][i];
	return st[u][0];
}
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	n=read(),flag1=flag2=1;
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v),add(v,u);
		if(u!=i||v!=i+1)flag1=0;
		if(u!=1||v!=i+1)flag2=0;
	}
	dfs(1,0);
	if(n<=5000){
		for(int i=1;i<=n;++i){
			int res=0x3f3f3f3f;
			for(int j=1;j<=n;++j){
				if(i==j)continue;
				int lca=LCA(i,j);
				if(lca==i){
					int tmp=max(n-siz[i],siz[son[j]]);
					if(LCA(son[i],j)==son[i])tmp=max(tmp,max(siz[cson[i]],siz[son[i]]-siz[j]));
					else tmp=max(tmp,siz[son[i]]);
					if(tmp<res)res=tmp,ans[i]=j;
				}else if(lca==j){
					int tmp=max(n-siz[j],siz[son[i]]);
					if(LCA(son[j],i)==son[j])tmp=max(tmp,max(siz[cson[j]],siz[son[j]]-siz[i]));
					else tmp=max(tmp,siz[son[j]]);
					if(tmp<res)res=tmp,ans[i]=j;
				}else{
					int tmp=max(siz[son[i]],max(siz[son[j]],n-siz[i]-siz[j]));
					if(tmp<res)res=tmp,ans[i]=j;
				}
			}
		}
		for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
	}else if(flag1){
		for(int i=1;i<=n;++i){
			if(i<=n/2)printf("%d\n",(i+n)/2);
			else printf("%d\n",(1+i)/2);
		}
	}else if(flag2){
		for(int i=1;i<=n;++i){
			if(i==1){printf("2\n");continue;}
			printf("1\n");
		}
	}else{
		
	}
	return 0;
}
/*
10
9 8
7 6
6 5
2 1
3 10
3 7
2 9
4 2
9 3
*/
