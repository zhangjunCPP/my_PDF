#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
const int maxn=1e5+5;
int vis[501][maxn-4];
bool flag;
int n,m,Q; 
inline void dfs(int x,int p){
	if(p>m)return;
	if(x==0){
		if(p==m)flag=1;
		vis[n][p]=2;
		return;
	}
	for(int i=1;i<=x;++i){
		if(flag)return;
		dfs(x-i,p+(x-i)*i);
		if(flag)return;
	}
}
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	Q=read();
	while(Q--){
		n=read(),m=read();
		if(m>(n-1)*n/2){puts("0");continue;}
		if(m==0||m==(n-1)*n/2||m==n-1){puts("1");continue;}
		if(vis[n][m]==1){puts("0");continue;}
		if(vis[n][m]==2){puts("1");continue;}
		flag=0;
		dfs(n,0);
		if(flag) puts("1");
		else puts("0"),vis[n][m]=1;
	}
}
