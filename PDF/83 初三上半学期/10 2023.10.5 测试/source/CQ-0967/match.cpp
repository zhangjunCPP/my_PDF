#include<bits/stdc++.h>
const int QWQ=1e6+5;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	return x*f;
} int Sagiri,bl; bool vism[25],ff,f3;
struct line{ int u,v; } e[25];
struct node{ int to,next; } E[QWQ<<1];
int t,n,m,cnt,head[QWQ],out[QWQ]; bool vis[QWQ];
inline void append(int x,int y){
	E[++cnt].to=y;
	E[cnt].next=head[x];
	head[x]=cnt;
}
void dfs(int k,int s){
	if (k>m){
		for (int i=1;i<m;i++)
		if (vism[i])
		for (int j=i+1;j<=m;j++)
		if (vism[j])
			if (e[i].u!=e[j].v&&e[i].u!=e[j].u&&e[i].v!=e[j].u&&e[i].v!=e[j].v)
				return ;
		Sagiri=max(Sagiri,s);
		return ;
	}
	vism[k]=1;
	dfs(k+1,s+1);
	vism[k]=0;
	dfs(k+1,s);
}
void bdfs(int u,int fa){
	if (ff) return ;
	vis[u]=1,bl++;
	for (int i=head[u];i;i=E[i].next){
		int v=E[i].to;
		if (v==fa) continue;
		if (vis[v]){ ff=1; return ; }
		bdfs(v,u);
		if (ff) return ;
	}
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	t=read(); 
	while (t--){
		n=read(),m=read();
		if (m<=20){
			Sagiri=0;
			for (int i=1;i<=m;i++)
				e[i].u=read(),e[i].v=read();
			dfs(1,0);
			printf("%d\n",Sagiri);
		}
		cnt=f3=0; int res=0;
		for (int i=1;i<=n;i++) head[i]=out[i]=vis[i]=0;
		bool fl1=1,fl2=1,fl3=1;
		for (int i=1;i<=m;i++){
			int x=read(),y=read();
			if (x!=i||y!=i+1) fl1=0;
			if (x!=1||y!=i+1) fl2=0;
			if (x!=i||y!=(i==n ? 1:i+1)) fl3=0;
			append(x,y),append(y,x);
			out[x]++,out[y]++;
		}
		if (fl1){ printf("%d\n",min(m,2)); continue; }
		if (fl2){ printf("%d\n",m); continue; }
		if (fl3){ printf("%d\n",n==3 ? 3:2); continue; }
		for (int i=1;i<=n;i++){
			res=max(res,out[i]);
			if (!vis[i]){
				ff=0,bl=0;
				bdfs(i,0);
				if (ff&&bl==3) f3=1;
			}
		}
		if (f3) res=max(res,3);
		printf("%d\n",res);
	}
	return 0;
}
/*
只需要判断有没有3元环和出边取max就行了? 

1
10 5
3 7
9 5
6 1
6 8
1 7
*/
