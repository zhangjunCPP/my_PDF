#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10,mod=998244353;
int n,q,a[maxn];
signed main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,l,r;i<=q;i++){
		int ans=1;
		cin>>l>>r;
		for(int j=1;j<(1<<(r-l+1));j++){
			int gcd=0;
			for(int k=0;k<(r-l+1);k++){
				if((j>>k)&1)gcd=__gcd(gcd,a[l+k]);
			}
			ans=ans*gcd%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
