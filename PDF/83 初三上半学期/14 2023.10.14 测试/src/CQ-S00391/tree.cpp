#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+10,mod=998244353;
struct edge{
	int fm,to,nxt;
}e[maxn<<2];
int head[maxn],tot;
void add(int u,int v){
	e[++tot].fm=u;
	e[tot].to=v;
	e[tot].nxt=head[u];
	head[u]=tot;
}
bool col[maxn];
int dfs(int i){
	if(i>=tot)return 1;
	if(col[e[i].fm]!=0||col[e[i].to]!=0)return dfs(i+1);
	int ans=0;
	col[e[i].fm]=1;ans=(ans+dfs(i+1))%mod;col[e[i].fm]=0;
	col[e[i].to]=1;ans=(ans+dfs(i+1))%mod;col[e[i].to]=0;
	return ans;
} 
int n;
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		add(u,v);add(v,u);
	}
	cout<<dfs(1);
	return 0;
}
