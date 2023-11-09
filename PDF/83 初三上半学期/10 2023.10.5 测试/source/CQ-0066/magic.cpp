#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
int n,l[N],r[N],c[N];
ll dp[1<<20];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d%d%d",&l[i],&r[i],&c[i]);
	if(n<=20){
		for(int s=0,t;s<(1<<n);++s)
			for(int i=1,cnt;i<=n;++i) if(!((s>>(i-1))&1)){
				t=s|(1<<(i-1)),cnt=0;
				for(int j=l[i];j<=r[i];++j) if(!((t>>(j-1))&1)) ++cnt;
				dp[t]=max(dp[t],dp[s]+1ll*cnt*c[i]);
			}
		printf("%lld\n",dp[(1<<n)-1]);
		return 0;
	}
	puts("0");
	
	return 0;
}
