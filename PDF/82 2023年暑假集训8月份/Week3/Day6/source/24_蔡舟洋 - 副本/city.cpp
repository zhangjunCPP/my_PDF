#include<bits/stdc++.h>
using namespace std;
const int N=22;
int n,k;
vector<int> E[N];
int c[N],ans;
int now,pos[N],can[N],vis[N];
void dfs(int x,int cnt){
	if(x==k+1){
		int hv=0,st;
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++)if(pos[c[i]])can[i]=1,hv++,st=i;else can[i]=0;
		int s=1;
		queue<int> q;
		q.push(st),vis[st]=1;
		while(q.size()){
			int u=q.front();q.pop();
			for(int v:E[u])if(!vis[v]&&can[v]){
				q.push(v),s++,vis[v]=1;
			}
		}
		if(s==hv)ans=min(ans,cnt-1);
		return;
	}
	pos[x]=1;
	dfs(x+1,cnt+1);
	pos[x]=0;
	dfs(x+1,cnt);
}
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	scanf("%d%d",&n,&k);ans=k;
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),E[u].push_back(v),E[v].push_back(u);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]); 
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
