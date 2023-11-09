#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f;
const int N=2e5+17;
int n,m,k;
int s[N],d[N];
int v[N<<1],nxt[N<<1],w[N<<1],head[N],tot;
ll dis[N];
vector<ll>come[N];
queue<int>q;
void add(int fr,int to,int dist){
	v[++tot]=to;
	nxt[tot]=head[fr];
	w[tot]=dist;
	head[fr]=tot;
}
signed main(){
//	freopen("D:\\down\\maze\\ex_maze4.in","r",stdin);
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&s[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		dis[i]=inf;
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=k;i++){
		dis[s[i]]=0;
		q.push(s[i]);
	}
	while(!q.empty()){
		int pos=q.front();
		q.pop();
		if(dis[pos]==inf){
			sort(come[pos].begin(),come[pos].end());
			dis[pos]=come[pos][d[pos]];
		}
		for(int j=head[pos];j!=0;j=nxt[j]){
			if(dis[v[j]]==inf){
				come[v[j]].push_back(dis[pos]+w[j]);
				if(d[v[j]]+1==come[v[j]].size()){
					q.push(v[j]);
				}
			}
		}
	}
	if(dis[1]>=inf){
		printf("-1");
		return 0;
	}
	printf("%lld",dis[1]);
}
