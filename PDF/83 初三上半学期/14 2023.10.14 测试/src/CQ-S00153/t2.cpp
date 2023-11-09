#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10,mod=998244353;
struct node{
	int x,y;
}e[N];
map<vector<int>,int>vis;
int n,ans,v[N];
void dfs(int p,vector<int>jl){
	if(p==n){
		if(!vis[jl])vis[jl]=1,ans++;
		return ;
	}
	int x=1,y=p+1;
	if(v[x]||v[y]){dfs(p+1,jl);}
	else{
		
	v[x]=1;jl.push_back(x);dfs(p+1,jl);v[x]=0;
	v[y]=1;jl.pop_back(),jl.push_back(y);dfs(p+1,jl);v[y]=0;}
}
int main(){
	//freopen("ex_tree2.in","r",stdin);
	//freopen("tree.out","w",stdout);
	for(n=2;n<=10;n++){ans=0;vis.clear();
	vector<int>b;
	dfs(1,b);
	printf("%d\n",ans);}
	return 0;
}
