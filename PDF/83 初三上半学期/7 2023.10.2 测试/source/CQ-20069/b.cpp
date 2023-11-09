#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+4;
int n,a[maxn],ans;
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=0;i<(1<<n);++i){
		int sum=0,cnt=0,tot=0;
		for(int j=1;j<=n;++j)
			if(i>>(j-1)&1)
				sum+=a[j],cnt++;
		for(int j=1;j<=n;++j)
			if((i>>(j-1)&1)&&a[j]*cnt>sum)
				tot++;
		ans=max(ans,tot);
	}
	printf("%lld",ans);
	return 0;
}
