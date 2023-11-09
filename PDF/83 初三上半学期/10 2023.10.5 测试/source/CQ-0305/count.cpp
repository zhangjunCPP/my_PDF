//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 10001
using namespace std;
typedef long long LL;
LL n;
void solve(){
	scanf("%lld",&n);
	LL ans=0;
	for(LL i=1;i<=n;i++)for(LL j=1;j<=n;j++)for(LL k=1,mk=(__int128)i*j/n;k<=mk;k++)if(!((__int128)i*j%k))++ans;
	printf("%lld\n",ans);
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--) solve();
	return 0;
}

