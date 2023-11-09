//the code is from chenjh
#include<cstdio>
#include<algorithm>
#define MAXN 1000005
using namespace std;
const int mod=998244353;
int n;
int f[MAXN][3];
int u[MAXN],v[MAXN];
bool vis[MAXN];
int ans=0;
void dfs(const int pos){
	if(pos>=n){
		if(++ans>=mod) ans-=mod;
		return;
	}
	if(!vis[u[pos]] && !vis[v[pos]]){
		vis[u[pos]]=1;
		dfs(pos+1);
		vis[u[pos]]=0;
		vis[v[pos]]=1;
		dfs(pos+1);
		vis[v[pos]]=0;
	}
	else dfs(pos+1);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	f[1][1]=f[1][2]=1;
	bool s4=1,s5=1;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		s4&=(u[i]==1&&v[i]==i+1),s5&=(u[i]==i&&v[i]==i+1);
	}
	if(s4) return printf("%d\n",n),0;
	if(s5){
		int F[2]={2,1};
		for(int i=3;i<=n;i++) F[i&1]=(F[i&1]+F[(i&1)^1])%mod;
		printf("%d\n",F[n&1]);
		return 0;
	}
	dfs(1);printf("%d\n",ans);
	return 0;
}

