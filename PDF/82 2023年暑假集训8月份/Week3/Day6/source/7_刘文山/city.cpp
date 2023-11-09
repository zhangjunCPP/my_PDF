#include<bits/stdc++.h>
using namespace std;
int n,k;
const int maxn=2e5+5;
vector<int> G[maxn];
int col[maxn],b[maxn],siz[maxn],vis[maxn];
int ans=0x3f3f3f3f;
int sum=0;
inline void dfs2(int x,int fa){
	sum++;
	for(auto y:G[x]){
		if(y==fa || !vis[col[y]]) continue;
		dfs2(y,x);
	}
}
inline void dfs(int now,int cnt,int SIZ){
	if(cnt-1>ans) return ;
	if(now==k+1){
		if(cnt==0) return ;
		int czc=0;
		for(int i=1;i<=k;i++){
			if(vis[i]){
				czc=i;
				break;
			}	
		}
		sum=0;
		dfs2(b[czc],b[czc]);
		if(sum==SIZ){
			ans=min(ans,cnt-1);
		}
		return ;
	}
	int op=rand()&1;
	if(op){
		vis[now]=1;
		dfs(now+1,cnt+1,SIZ+siz[now]);
		vis[now]=0;
		dfs(now+1,cnt,SIZ);
	}
	else{
		vis[now]=0;
		dfs(now+1,cnt,SIZ);
		vis[now]=1;
		dfs(now+1,cnt+1,SIZ+siz[now]);
		vis[now]=0;
	}
} 
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout); 
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		cin>>col[i];
		b[col[i]]=i;
		siz[col[i]]++;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

