#include<bits/stdc++.h>
using namespace std;

const int maxn=1e8+5;

int f[maxn];

int main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		long long ans=0;
		for(int i=1;i<=n*n;i++) f[i]=0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				f[i*j]++;
			}
		}
		for(int i=1;i<=n*n;i++) ans=ans+1ll*f[i]*f[i];
		cout<<ans<<'\n';
	}
	return 0;
}
