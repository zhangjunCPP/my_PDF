#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e5+2,INF=2e9;
int n,m,k,lf[N],d[N],ds[N],hd[N],nxt[N],to[N],cnt,w[N];
int vis[N],dis[N];
void add(int x,int y,int z){
	to[++cnt]=y;
	nxt[cnt]=hd[x];
	hd[x]=cnt;
	w[cnt]=z;
}
bool dfs(int x){
	vis[x]=1;
	if(lf[x]==1)return 1;
	for(int i=hd[x];i;i=nxt[i]){
		int y=to[i];
		if(vis[y]||lf[y]==-1)continue;
		if(dfs(y))return 1;
	}
	return 0;
}
int spfa(int s){
	for(int i=1;i<=n;i++){
		dis[i]=INF;
		vis[i]=0;
	}
	queue<int>q;
	q.push(s);
	dis[s]=0;vis[s]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=hd[x];i;i=nxt[i]){
			int y=to[i];
			if(lf[y]==-1)continue;
			if(dis[y]>dis[x]+w[i]){
				dis[y]=dis[x]+w[i];
				if(!vis[y]&&!lf[y]){
					q.push(y);
					vis[y]=1;
				}
			}
		}
	}
	int mn=INF;
	for(int i=1;i<=n;i++){
		if(lf[i]==1){
			mn=min(dis[i],mn);
		}
	}
	return mn;
}
int dfs(int x,int dis){
	if(lf[x]==1)return dis;
	vis[x]=1;
	vector<int>s;
	for(int i=hd[x];i;i=nxt[i]){
		int y=to[i];
		if(lf[y]==-1||vis[y])continue;
		s.push_back(dfs(y,dis+w[i]));

	}
	sort(s.begin(),s.end());
	vis[x]=0;
	return s[d[x]];
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x;i<=k;i++){
		cin>>x;
		lf[x]=1;
	}
	bool A=0;
	for(int i=1;i<=n;i++){
		cin>>d[i];
		if(d[i])A=1;
	}
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
		add(x,y,z),add(y,x,z);
		ds[x]++,ds[y]++;
	}
	for(int i=1;i<=n;i++){
		if(d[i]>=ds[i]||(i!=1&&d[i]>=ds[i]-1))lf[i]=-1;
	}
	if(lf[1]==-1||!dfs(1)){
		printf("-1");
		return 0;
	}
	if(!A){
		printf("%d",spfa(1));
		return 0;
	}
	memset(vis,0,sizeof(vis));
	printf("%d",dfs(1,0));
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
