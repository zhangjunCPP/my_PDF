#include<bits/stdc++.h>
#define int long long
const int N=1e6+10,M=1e5+10,inf=1e9,mod=998244353;
void Freopen();
using namespace std;
int sb,mx,n,ans;
int a[200][200],s[N],vis[N],x[N];
void dfs( int k) {
	if ( k==sb+1) {
		int res=0;
		for ( int i=1; i<=sb; i++){
			int tot=0;
			for ( int j=i+1; j<=sb; j++) 
				if (s[i]>s[j]) tot++;
			res=res*10+tot;
		}
		mx=max(mx,res);
		return ;
	}
	for ( int i=1; i<=x[k]; i++) {
		if (vis[a[k][i]]) continue;
		vis[a[k][i]]=1;
		s[k]=a[k][i];
		dfs(k+1);
		vis[a[k][i]]=0;
	}
}
void dfs2( int k) {
	if ( k==sb+1) {
		int res=0;
		for ( int i=1; i<=sb; i++){
			int tot=0;
			for ( int j=i+1; j<=sb; j++) 
				if (s[i]>s[j]) tot++;
			res=res*10+tot;
		}
		if (res==mx) ans=(ans+1)%mod;
		return ;
	}
	for ( int i=1; i<=x[k]; i++) {
		if (vis[a[k][i]]) continue;
		vis[a[k][i]]=1;
		s[k]=a[k][i];
		dfs2(k+1);
		vis[a[k][i]]=0;
	}
}
signed main() {
	Freopen();
	cin>>sb;
	for ( int i=1; i<=sb; i++) {
		cin>>x[i];
		for ( int j=1; j<=x[i]; j++) cin>>a[i][j];
	}
	dfs(1);
	memset(vis,0, sizeof vis);
	dfs2(1);
	cout<<ans;
}
void Freopen() {
	freopen("marketeers.in","r",stdin);
	freopen("marketeers.out","w",stdout);
}
/*
4
5
7 11 3 10 1
3
8 6 4
1
15
3
1 5 99

13
*/
