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
#define R register
const int QWQ=1005;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
} bool vis[QWQ];
struct node{ int to,next,val; } E[QWQ<<1];
int n,m,q,cnt,head[QWQ],dis[QWQ][QWQ];
inline void append(const int &x,const int &y,const int &z){
	E[++cnt].to=y;
	E[cnt].val=z;
	E[cnt].next=head[x];
	head[x]=cnt;
}
inline void bfs(const int &s){
	queue<pair<int,int> > q;
	q.push({s,1});
	while (!q.empty()){
		int u=q.front().first;
		int vl=q.front().second; q.pop();
		dis[s][u]=max(dis[s][u],vl);
		for (R int i=head[u];i;i=E[i].next){
			R int v=E[i].to;
			if (vl*E[i].val>m) continue;
			q.push({v,vl*E[i].val});
		}
	}
}
int main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	memset(dis,-1,sizeof(dis));
	n=read(),m=read(),q=read();
	for (R int i=2;i<=m;i++){
		R int x=read(),y=read();
		append(x,y,i),append(y,x,i);
	} for (R int i=1;i<=n;i++) bfs(i);
	while (q--){
		R int s=read(),t=read();
		printf("%d\n",dis[s][t]);
	} 
	return 0;
}

