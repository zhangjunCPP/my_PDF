#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int s=0,w=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
    return s*w;
}
inline void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
inline void FRE(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
}
const int maxn=3e5+5;
bool flag1=1,flag2=1;
int n,son,fat;
int ans[maxn],sum[maxn];
int siz[maxn],f[maxn];
vector<int> a[maxn];
inline void add(int u,int v){
	a[u].push_back(v);
}
inline void DFS(int u,int FA){
	sum[u]=1;
	for(int v:a[u]){
		if(v==FA)continue;
		DFS(v,u);sum[u]+=sum[v];
	}
} 
inline void df(int u,int FA,int SUM){
	siz[u]=1;
	f[u]=0;
	for(int v:a[u]){
		if(v==FA)continue;
		df(v,u,SUM);siz[u]+=siz[v];
		f[u]=max(f[u],siz[v]);
	}
	f[u]=max(f[u],SUM-siz[u]);
	if(f[u]<f[son])son=u;
}
inline void dfs(int u,int FA){
	sum[FA]=n-sum[u];
	int xhb=-1,zy=0;
	for(int v:a[u]){
		son=0;fat=u;
		df(v,u,sum[v]);
		if(f[son]>xhb){
			xhb=f[son];
			zy=son;
		}
	}
	ans[u]=zy;
	for(int v:a[u]){
		if(v==FA)continue;
		dfs(v,u);
	}
}
int main(){
	FRE();
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v);add(v,u);
		if(u!=i||v!=i+1)flag1=0;
		if(u!=1||v!=i+1)flag2=0;
	}
	if(flag1){
		for(int i=1;i<=n;++i){
			int ls=i-1,rs=n-i;
			if(ls<rs){
				printf("%d\n",i+rs/2+1);
			}
			else{
				printf("%d\n",i-ls/2-1);
			}
		}
		return 0;
	}
	if(flag2){
		printf("2\n");
		for(int i=2;i<=n;++i)printf("1\n");
		return 0;
	}
	f[0]=maxn;
	DFS(1,0); 
	dfs(1,0);
	for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
	return 0;
}

