#include <bits/stdc++.h>
#define int long long
void Freopen();
void Ft();
int rd();
const int N=2e5+10, M=2e5+10, inf=1e9+10, mod=998244353;
using namespace std;
int n, q;
int a[N], b[N], ans=1, f[20][20];
void dfs( int k, int l, int r, int n, int last) {
	if (r-last+1<n-k+1) return ;
	if (k==n+1) {
		int gc=b[1];
//		for ( int i=1; i<=n; i++) cout<<b[i];
//		cout<<endl;
		for ( int i=2; i<=n; i++) gc=__gcd(gc,b[i]);
//		cout<<gc<<endl;
		ans=ans*gc%mod;
		return ;
	}
	for ( int i=last; i<=r; i++){
		b[k]=a[i];
		dfs(k+1, l, r, n, i+1);
	}
}
signed main() {
	Freopen(); 
	n=rd(), q=rd();
	for ( int i=1; i<=n; i++) a[i]=rd();
	if (q<=20) {
		while (q--) {
			int l, r; cin>>l>>r;
			for ( int i=1; i<=r-l+1; i++){
				dfs(1, l, r, i, l);
			}
			cout<<ans<<endl;
			ans=1;
		}
		return 0;
	}
	for ( int i=1; i<=n; i++)
		for ( int j=i; j<=n; j++){
			ans=1;
			for ( int l=1; l<=j-i+1; l++)
				dfs(1, i, j, l, i);
			f[i][j]=ans;
		}
	while (q--) {
		int l, r; cin>>l>>r;
		cout<<f[l][r]<<endl;
	}
}
void Freopen() {
	freopen("ddickky.in", "r", stdin);
	freopen("ddickky.out", "w", stdout);
}
void Ft() {
	freopen("ddickky.in", "r", stdin);
	freopen("ddickky.out", "w", stdout);
}
int rd() {
	int x; scanf("%lld", &x);
	return x;
}

