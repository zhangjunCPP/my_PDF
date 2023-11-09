#include<bits/stdc++.h>
#define int long long
const int N=1e6+10,M=1e5+10,inf=1e9+7;
void Freopen();
void Ftest();
int rd();
using namespace std;
void solve() {
	int n,ans=0;
	n=rd();
	for ( register int i=1; i<=n*n; i++) {
		int o=0,f=0;
		for ( register int j=1; j*j<=i; j++) 
			if (i%j==0&&i/j<=n&&j<=n) {
				o++;
				if (j*j==i) f=1;
			}
		if (f) {
			ans+=4*(o-1)+1;
			ans+=4*(o-1)*(o-2)+4*(o-1);
		}
		else {
			ans+=4*(o);
			ans+=4*(o-1)*(o);
		}
	}
	printf("%lld\n",ans);
}
signed main() {
	Freopen();
	for ( int t=rd(); t; t--) solve();
}
void Freopen() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
}
void Ftest() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
}
int rd() {
	int x; scanf("%lld",&x);
	return x;
}


