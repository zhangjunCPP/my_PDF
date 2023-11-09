/*
Sakurajima Mai,
Eriri Spencer,
Izumi Sagiri,
Keqing,
Hu tao,
Ganyu
say,"With our sincere wishes to HHX: never to debug code"
*/

#include<bits/stdc++.h>
const int QWQ=3e5+5;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
} int rt,siiz,sss;
struct node{ int to,next; } E[QWQ<<1];
int n,head[QWQ],cnt,siz[QWQ],root,son[QWQ];
inline void append(int x,int y){
	E[++cnt].to=y;
	E[cnt].next=head[x];
	head[x]=cnt;
}
inline void get_sub1(){
	for (int i=1;i<=n;i++){
		int pre=i-1,back=n-i;
		if (pre>back) printf("%d\n",i/2);
		else printf("%d\n",(n-i+1)/2+i);
	}
}
inline void get_sub2(){
	for (int i=1;i<=n;i++)
		if (i==1) printf("2\n");
		else printf("1\n");
}
inline void init(){
	for (int i=0;i<=n;i++)
		siz[i]=son[i]=0;
	root=siiz=0;
}
void dfs(int u,int fa,int no){
	siz[u]=1;
	for (int i=head[u];i;i=E[i].next){
		int v=E[i].to;
		if (v==fa||v==no) continue;
		dfs(v,u,no);
		siz[u]+=siz[v];
		if (siz[son[u]]<siz[v])
			son[u]=v;
	}
}
void getroot(int u,int fa,int no){
	for (int i=head[u];i;i=E[i].next){
		int v=E[i].to;
		if (v==fa||v==no) continue;
		getroot(v,u,no);
	} if (son[u]&&siz[son[u]]<=sss/2) rt=u;
}
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	n=read(); bool fl1=1,fl2=1;
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		if (!(x==i&&y==i+1)) fl1=0;
		if (!(x==1&&y==i+1)) fl2=0;
		append(x,y),append(y,x);
	}
	if (fl1){ get_sub1(); return 0; }
	if (fl2){ get_sub2(); return 0; }
	for (int i=1;i<=n;i++){
		init();
		for (int j=1;j<=n;j++)
			if (i!=j&&!siz[j]){
				dfs(j,0,i); rt=0;
				sss=siz[j];
				getroot(j,0,i);
				if (siiz<siz[j])
					siiz=siz[j],root=rt;
			}
		printf("%d\n",root);
	}
	return 0;
}

