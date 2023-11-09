#include<bits/stdc++.h>
#define int long long
const int N=1e6+100,M=1e5+10,inf=1e9;
void Freopen();
void Ftest();
using namespace std;
int n,ans;
int sum[N],a[N];
signed main() {
//	Ftest();
	Freopen();
	cin>>n;
	for ( int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for ( int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];	
	for ( int i=1; i<=n; i++) {
		int t=upper_bound(a+1,a+i,sum[i]/i)-a;
		ans=max(ans,i-t+1);
	}
	cout<<ans;
}
void Freopen() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
}
void Ftest() {
	freopen("ex_A2.in","r",stdin);
//	freopen("b.out","w",stdout);
}

