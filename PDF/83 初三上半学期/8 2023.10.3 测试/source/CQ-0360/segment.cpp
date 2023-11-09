#include<bits/stdc++.h>
#define int long long
const int N=1e6+10,M=1e5+10,inf=3e9+7;
void Freopen();
void Ftest();
using namespace std;
int n,tot,ans=inf;
int a[N],s[N],dp[3000][3000];
void dfs( int k) {
	if (k>n) {
		int mi=inf,mx=0;
		for ( int i=1; i<=tot; i++) mi=min(mi,s[i]),
			mx=max(mx,s[i]);
		ans=min(ans,mx-mi);
		return ;
	}
	s[++tot]=a[k];
	dfs(k+1);
	tot--;
	s[++tot]=a[k]+a[k+1];
	dfs(k+2); 
	tot--;
}
signed main() {
	Freopen();
	cin>>n;
	for ( int i=1; i<=n; i++) cin>>a[i];
//	if (n<=25) {
		dfs(1);
		cout<<ans;
//		return 0;
//	}
	
}
void Freopen() {
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
}
void Ftest() {
	freopen(".txt","r",stdin);
	freopen(".txt","w",stdout);
}

