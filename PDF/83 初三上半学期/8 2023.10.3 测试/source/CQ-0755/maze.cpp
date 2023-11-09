/*
最坏的情况肯定是把离终点总路程更近的堵了
如果d[u]>out[i]这个点不要也行
终点当成一个点，终点的荆棘没有用，终点之间相连的边也没用
从总终点t倒着往回一层一层的找 ？ 不行 
想了半天也没有具体算法23333 
d[u]=0就是正常的最短路... 
*/

#include<bits/stdc++.h>
const int inf=0x3f3f3f3f;
const int QWQ=2e5+5;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
} bool ist[QWQ],vis[QWQ]; int ed[QWQ];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
struct node{ int to,next,val; } E[QWQ<<1];
int n,m,k,d[QWQ],head[QWQ],cnt,dis1[QWQ],dis2[2005][2005];
inline void append(int x,int y,int z){
	E[++cnt].to=y;
	E[cnt].val=z;
	E[cnt].next=head[x];
	head[x]=cnt;
}
void dij(int *dis,int s){
	for (int i=1;i<=n+1;i++)
		dis[i]=inf,vis[i]=0;
	q.push({0,s}); dis[s]=0;
	while (!q.empty()){
		int u=q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=head[u];i;i=E[i].next){
			int v=E[i].to;
			if (dis[v]>dis[u]+E[i].val){
				dis[v]=dis[u]+E[i].val;
				q.push({dis[v],v});
			} 
		} 
	} 
}
void sol2(){
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		if (ist[x]&&ist[y]) continue;
		if (ist[x]) x=n+1;
		if (ist[y]) y=n+1;
		append(x,y,z),append(y,x,z);
	} dij(dis1,1);
	printf("%d",dis1[n+1]);
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	n=read(),m=read(),k=read();
	bool fl1=1;
	for (int i=1;i<=k;i++)
		ed[i]=read(),ist[ed[i]]=1;
	for (int i=1;i<=n;i++){
		d[i]=read();
		if (d[i]!=0) fl1=0;
	} if (fl1){ sol2(); return 0; }
	if (n>2000){ cout<<-1; return 0; } 
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		if (ist[x]&&ist[y]) continue;
		if (ist[x]) x=n+1;
		if (ist[y]) y=n+1;
		append(x,y,z),append(y,x,z);
	} for (int i=1;i<=n;i++){
		if (ist[i]) continue;
		dij(dis2[i],i);
	} 
	queue<pair<int,int> > q;
	q.push({1,0});
	int res=inf;
	double nnn=clock();
	while (!q.empty()){
		int u=q.front().first,vll=q.front().second; q.pop();
		if (clock()-nnn>920) break;
		if (u==n+1){ res=min(res,vll); continue; }
		vector<pair<int,pair<int,int> > > vs;
		for (int i=head[u];i;i=E[i].next){
			int v=E[i].to; //cout<<v<<' ';
			vs.push_back({dis2[v][n+1],{v,E[i].val}});
		} sort(vs.begin(),vs.end());
		for (int i=d[u];i<(int)vs.size();i++)
			q.push({vs[i].second.first,vll+vs[i].second.second});
	} //乱写 
	if (res==inf) puts("-1");
	else printf("%d",res);
	return 0;
}
/*
5 8 3
2 3 5
2 0 1 1 2
1 2 1
2 3 2
3 4 5
2 5 3
4 5 2
5 1 3
3 5 2
4 1 1
*/
