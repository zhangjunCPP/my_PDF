#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
void solve(){
	scanf("%lld",&n);
	int ans=0;
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			for(int c=ceil(1.0*a*b/n);c<=n;c++){
				int d=a*b/c;
				if(d*c==a*b)ans++;
				if(!d)break;
			}
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%lld",&T);
	while(T--)solve();
	return 0;
}
