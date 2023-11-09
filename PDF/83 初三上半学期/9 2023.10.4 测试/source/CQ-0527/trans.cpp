#include<bits/stdc++.h>
using namespace std;
int t,n,m,x,y,diff,same,e[101][101],col[101],vis[101];
long long ans,k,d[101][101],s[101][101];
const int mod=1e9+7;
void dfs(int x){
	vis[x]=1;
	int now=k;
	for(int i=1;i<=n;i++) if(e[x][i]&&vis[i]) now--;
	col[x]=now>0?now:0;
	for(int i=1;i<=n;i++) if(e[x][i]&&!vis[i]) dfs(i);
}
void bfs(int x){
	if(x==n+1){
		long long now=1;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(e[i][j]) now=(now*(col[i]==col[j]?s[i][j]:d[i][j]))%mod;
		ans=(ans+now)%mod;
		return;
	}
	for(int i=1;i<=k;i++) col[x]=i,bfs(x+1);
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%lld",&n,&m,&k);
		bool choose=1;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) e[i][j]=0,d[i][j]=s[i][j]=1;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d%d",&x,&y,&diff,&same);
			if(diff!=1||same!=0) choose=0;
			e[x][y]=e[y][x]=1,s[x][y]=s[y][x]=s[x][y]*same%mod,d[x][y]=d[y][x]=d[x][y]*diff%mod;
		}
		if(n==2) printf("%lld\n",(s[1][2]*k%mod+d[1][2]*k%mod*(k-1)%mod)%mod);
		else if(choose){
			memset(col,0,sizeof(col));
			memset(vis,0,sizeof(vis));
			dfs(1);
			long long ans=1;
			for(int i=1;i<=n;i++) ans=ans*col[i]%mod;
			printf("%lld\n",ans);
		}
		else{
			memset(col,0,sizeof(col));
			ans=0,bfs(1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
