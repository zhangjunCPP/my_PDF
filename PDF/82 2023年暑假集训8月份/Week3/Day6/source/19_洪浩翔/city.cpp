#include<bits/stdc++.h>
const int QWQ=2005;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
} bool choose[QWQ]; int vis[QWQ],bl,can[QWQ];
struct node{ int to,next; } E[QWQ<<1];
int n,co,cnt,head[QWQ],c[QWQ],col[QWQ],out=22;
inline void append(int x,int y){
	E[++cnt].to=y;
	E[cnt].next=head[x];
	head[x]=cnt;
}
void bdfs(int u,int fa,int need){
	vis[u]=bl;
	for (int i=head[u];i;i=E[i].next){
		int v=E[i].to;
		if (v==fa||vis[v]) continue;
		if (col[v]!=need) continue;
		bdfs(v,u,need);
	}
}
void dfs(int k){
	if (k>co){
		int res=0,p=0;
		for (int i=0;i<=n;i++)
			vis[i]=can[i]=0; bl=0;
		for (int i=1;i<=co;i++)
			if (choose[i]) res++;
		for (int i=1;i<=n;i++)
			if (choose[c[i]]) col[i]=0;
			else col[i]=c[i];
		for (int i=1;i<=n;i++)
			if (!vis[i]) bl++,bdfs(i,0,col[i]);
		for (int i=1;i<=n;i++)
			if (can[col[i]]==0) can[col[i]]=vis[i];
			else if (can[col[i]]!=vis[i]) can[col[i]]=-1;
		for (int i=0;i<=co;i++){
			if (can[i]==-1) continue;
			if (can[i]==0) continue;
			out=min(max(0,res-1),out);
			return ;
		}
		return ;
	} 
	choose[k]=1;
	dfs(k+1);
	choose[k]=0;
	dfs(k+1);
}
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	n=read(),co=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		append(x,y),append(y,x);
	} for (int i=1;i<=n;i++) c[i]=read();
	if (n<=20){ dfs(1); printf("%d",out); return 0; }
	else puts("0");
	return 0;
}

