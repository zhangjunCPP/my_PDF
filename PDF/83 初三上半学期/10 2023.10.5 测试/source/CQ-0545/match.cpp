#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=1e6+5;
int n,m;
int d[N];
vector<int> E[N]; 
int dep[N],fa[N],ok;
void dfs(int u){
	if(ok)return;
	for(int v:E[u]){
		if(v==fa[u])continue;
		if(dep[v]){
			if(dep[v]==dep[u]+2||dep[u]==dep[v]+2){
				ok=1;
				return;
			}continue;
		}else{
			dep[v]=dep[u]+1;fa[v]=u;
			dfs(v); 
		} 
	}
}
void solve(){
	n=rd(),m=rd();for(int i=1;i<=n;i++)d[i]=0,E[i].clear();
	for(int i=1;i<=m;i++){
		int u=rd(),v=rd();
		d[u]++,d[v]++;
		E[u].push_back(v);
		E[v].push_back(u); 
	}int ans=0;for(int i=1;i<=n;i++)ans=max(ans,d[i]);
	if(ans>=3) 
	printf("%d\n",ans);
	else{
		for(int i=1;i<=n;i++)dep[i]=0,fa[i]=0;
		ok=0;
		for(int i=1;i<=n;i++)if(!dep[i]){
			dep[i]=1;
			dfs(i);
		}
		printf("%d\n",max(ok*3,ans));
	}
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int t=rd();
	while(t--)solve();
	return 0;
}
