#include<bits/stdc++.h>
#define int long long
const int N=1e6+10,M=1e5+10,inf=1e9,mod=1e9+7;
void Freopen();
void Ftest();
int rd() {
	int x; scanf("%lld",&x);
	return x;
}
using namespace std;
int n,m,k,tot;
struct node {
	int x,y,d,s;	
} br[N];
struct MP {
	int x,y;	
} mp[N];
int d[200][200],s[200][200],king[200];
int vis[200][200],V[200];
int ans=0,f;
void init() {
	ans=0;
	for ( int i=1; i<=n; i++) V[i]=0;
	for ( int i=1; i<=n; i++)
		for ( int j=i; j<=n; j++)
			d[i][j]=s[i][j]=1,vis[i][j]=0;
	tot=0;
}
int chk1() {
	for ( int i=1; i<=m; i++) {
		int d=br[i].d,s=br[i].s;
		if (d!=1||s!=0) return 0;
	}
	return 1;
}
void dfs( int dep) {
	if (dep==n+1) {
		int res=1;
		for ( int i=1; i<=tot; i++) {
			int u=mp[i].x,v=mp[i].y;
			if (king[u]!=king[v]) res*=d[u][v],res%=mod;
			else res*=s[u][v],res%=mod;
		}
		ans+=res,ans%=mod;
		return ;
	}
	for ( int i=1; i<=k; i++) {
		king[dep]=i;
		dfs(dep+1);
	}
}
void solve() {
	n=rd(),m=rd(),k=rd();
	init();
	for ( int i=1; i<=m; i++){
		br[i]={rd(),rd(),rd(),rd()};	
		if (br[i].x>br[i].y) swap(br[i].x,br[i].y);
		if (!vis[br[i].x][br[i].y]) mp[++tot]={br[i].x,br[i].y};
		vis[br[i].x][br[i].y]=1;
		d[br[i].x][br[i].y]=d[br[i].x][br[i].y]*br[i].d%mod;
		s[br[i].x][br[i].y]=s[br[i].x][br[i].y]*br[i].s%mod;
	}
	if (n==2) {
		cout<<k*s[1][2]%mod+k*(k-1)%mod*d[1][2]%mod<<endl;
		return ;
	}
	if (chk1()) {
		ans=1;
		for ( int i=0; i<n; i++) ans=ans*(k-i)%mod;
		cout<<ans<<endl;
		return ;
	}
	ans=0;
	dfs(1);
	cout<<ans<<endl;
	return ;		
}
signed main() {
	Freopen();
	for ( int t=rd(); t; t--) solve();
}
void Freopen() {
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
}
void Ftest() {
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}

