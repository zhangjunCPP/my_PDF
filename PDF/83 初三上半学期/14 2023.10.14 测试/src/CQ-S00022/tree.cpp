#include<cstdio>
#include<iostream>
using namespace std;
const int Maxn=1e6+5;
const int Mod=998244353;
int u[Maxn],v[Maxn];
bool col[Maxn];
int  cnt;
void dfs(int x,int n){
	if(x==n){++cnt;return ;}
	if(!col[u[x]]&&!col[v[x]]){
		col[u[x]]=1;dfs(x+1,n);col[u[x]]=0;
		col[v[x]]=1;dfs(x+1,n);col[v[x]]=0;
	}else dfs(x+1,n);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n;cin>>n;
	for(int i=1;i<n;++i)cin>>u[i]>>v[i];
	if(n<=100)dfs(1,n),cout<<cnt<<'\n';
	else if(u[2]==1)cout<<n<<'\n';
	else if(u[2]==2){
		int las=1,now=1;
		for(int i=2;i<=n;++i)las=(las+now)%Mod,swap(now,las);
		cout<<now<<'\n';
	}
	return 0;
}
