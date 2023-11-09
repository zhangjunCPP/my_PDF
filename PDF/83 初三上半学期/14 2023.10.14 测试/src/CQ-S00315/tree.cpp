#include<bits/stdc++.h>
const int mod=998244353;
const int QWQ=1e6+5;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	return x*f;
} int Eriri,co[15];
struct line{ int u,v; } a[15];
struct node{ int to,next; } E[QWQ<<1];
int n,cnt,head[QWQ],f[QWQ];
inline void append(int x,int y){
	E[++cnt].to=y;
	E[cnt].next=head[x];
	head[x]=cnt;
}
void dfs(int k){
	if (k==n){
		Eriri++;
		return ;
	} if (!co[a[k].u]&&!co[a[k].v]){
		co[a[k].u]=1;
		dfs(k+1);
		co[a[k].u]=0;
		co[a[k].v]=1;
		dfs(k+1);
		co[a[k].v]=0;
	} else dfs(k+1);
}
inline void another(){
	for (int i=1;i<n;i++)
		a[i].u=read(),a[i].v=read();
	dfs(1);
	printf("%d",Eriri);
}
inline void worker(){
	f[0]=f[1]=1;
	for (int i=2;i<=n;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	printf("%d",f[n]);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read(); bool fl1=1,fl2=1;
	if (n<=10){ another(); return 0; }
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		if (x!=1||y!=i+1) fl1=0;
		if (x!=i||y!=i+1) fl2=0;
		append(x,y),append(y,x);
	}
	if (fl1){ printf("%d",n); return 0; }
	if (fl2){ worker(); return 0; }
	return 0;
}
