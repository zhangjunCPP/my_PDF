#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
const int INF=0x3f3f3f3f;
int t,n,m,vis[maxn],len,f[maxn],flag,du[maxn];
vector<int>g[maxn];
void dfs(int x,int fa){
	f[x]=fa;vis[x]=1;
	for(auto k:g[x]){
		if(k==fa)continue;
		if(vis[k]){
			if(f[f[x]]==k)flag=1;
		}
		else len++,dfs(k,x);
	}
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;flag=0;
		for(int i=1;i<=n;i++)g[i].clear(),vis[i]=f[i]=du[i]=0;
		for(int i=1;i<=m;i++){
			int x,y;cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
			du[x]++,du[y]++;
			if(du[x]>=3||du[y]>=3)flag=1;
		}
		int ans=0;
		if(flag==1)ans=3;
		else{
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					len=0;dfs(i,0);
					if(len>=2)ans=max(ans,2);
					if(flag){
						ans=3;break;
					}
				}
			}
		}
		if(ans>=2)cout<<ans<<"\n";
		else if(m!=0)cout<<1<<"\n";
		else cout<<0<<"\n";
	}
	return 0;
}
//无向图最大匹配能轻易做出来？好牛
//答案小于等于3 然后乱搞 
