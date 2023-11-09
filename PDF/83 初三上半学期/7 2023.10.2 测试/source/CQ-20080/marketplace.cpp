#include<bits/stdc++.h>
const int QWQ=1e5+5;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
} bool vis[1000005];
long long res[1000005],rd[1000005];
struct card{ int x,y; } a[QWQ<<1];
int n,m,tot; map<int,bool> q;
int calc(int k){
	if (k>n&&k<=n+n) return k-n;
	if (k>n+n) return 1;
	return k;
}
void dfs1(int k){
	if (vis[a[k].x]==1&&vis[a[k].y]==1){
		rd[calc(k)]++;
		return ;
	} 
	if (!vis[a[k].x]){
		vis[a[k].x]=1;
		dfs1(k+1);
		vis[a[k].x]=0;
	} else{
		vis[a[k].y]=1;
		dfs1(k+1);
		vis[a[k].y]=0;
	}
}
void dfs(int k){
	if (vis[a[k].x]==1&&vis[a[k].y]==1){
		res[calc(k)]++;
		return ;
	} 
	if (!vis[a[k].x]){
		vis[a[k].x]=1;
		dfs(k+1);
		vis[a[k].x]=0;
	} else{
		vis[a[k].y]=1;
		dfs(k+1);
		vis[a[k].y]=0;
	}
}
int main(){
	freopen("marketplace.in","r",stdin);
	freopen("marketplace.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++){
		a[i].x=read(),a[i].y=read();
		q[a[i].x]=q[a[i].y]=1;
	} for (int i=n+1;i<=n+n;i++)
		a[i]=a[i-n];
	a[n+n+1]=a[1];
	dfs1(1);
	for (int i=1;i<=m;i++){
		if (!q[i]){ tot++; continue; }
		for (int i=1;i<=m;i++)
			vis[i]=0;
		vis[i]=1,dfs(1);
	}
	for (int i=1;i<=n;i++)
		printf("%lld\n",res[i]+(long long)tot*rd[i]);
	return 0;
}
