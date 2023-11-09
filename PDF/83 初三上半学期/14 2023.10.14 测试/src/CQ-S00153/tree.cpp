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
	int x=e[p].x,y=e[p].y;
	if(v[x]||v[y])dfs(p+1,jl);
	else{
		v[x]=1;jl.push_back(x);dfs(p+1,jl);v[x]=0;
		v[y]=1;jl.pop_back(),jl.push_back(y);dfs(p+1,jl);v[y]=0;
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	int flag=1,flag2=1;
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		if(x!=1)flag=0;
		if(x!=i||y!=i+1)flag2=0;
		e[i]={x,y};
	}
	if(flag){
		printf("%d",n);
		return 0;
	}
	if(flag2){
		ll a=3,b=2,c;
		if(n<=3)printf("%d\n",n);
		else{
			for(int i=4;i<=n;i++)c=b,b=a,a=(a+c)%mod;
			printf("%lld\n",a);
		}
		return 0;
	}
	
	vector<int>b;
	dfs(1,b);
	printf("%d\n",ans);
	return 0;
}
