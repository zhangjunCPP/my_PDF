#include<bits/stdc++.h>
using namespace std;
int a[500010],p[25],cnt[25][25],mask[25];
int dp[500010],from[500010],stk[500010],tp;
//找前面mex=0,1,2,3...20的最大的pos
int main(){
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	for(int mex=0;mex<=21;mex++){
		cnt[mex][a[i]]++,mask[mex]|=1<<a[i];
		while(p[mex]+1<i&&__builtin_ctz(~(mask[mex]^(cnt[mex][a[p[mex]+1]]==1?1<<a[p[mex]+1]:0)))>=mex)
		p[mex]++,mask[mex]^=--cnt[mex][a[p[mex]]]?0:1<<a[p[mex]];
		if(__builtin_ctz(~mask[mex])>=mex&&dp[p[mex]]+mex>dp[i])dp[i]=dp[p[mex]]+mex,from[i]=p[mex];
	}for(int pos=n;pos;pos=from[pos])stk[++tp]=from[pos]+1;
	printf("%d %d\n",dp[n],tp);
	for(;tp;tp--)printf("%d ",stk[tp]);
	return 0;
}
