#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t;
void solve(){
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j) ans+=n;
			else{
				t=__gcd(i,j);
				ans+=2*(n*t/j);
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
