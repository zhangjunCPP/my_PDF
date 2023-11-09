#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<bitset>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e7+10;
const int INF=0x3f3f3f3f;
const long long LINF=0x3f3f3f3f3f3f3f3f;
int n,mod;
long long ans=1;
long long fac[MAXN],inv[MAXN],facinv[MAXN];
long long f[MAXN],g[MAXN];
long long C(int N,int M){
	if(M==0){
		return 1;
	}
	return fac[N]*facinv[N-M]%mod*facinv[M]%mod;
}
signed main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	scanf("%d%d",&n,&mod);
	fac[0]=1;
	fac[1]=1;
	facinv[0]=0;
	inv[1]=1;
	facinv[1]=1;
	for(int i=2;i<=n;i++)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
		facinv[i]=facinv[i-1]*inv[i]%mod;
	}
	g[1]=1;
	g[2]=2;
	g[3]=4;
	for(int i=4;i<=n;i++)
	{
		g[i]=(g[i-2]*(i-1)%mod+g[i-1])%mod;
	}
	f[1]=0;
	f[2]=0;
	f[3]=1;
	for(int i=4;i<=n;i++)
	{
		f[i]=(i*f[i-1]+C(i-1,2)*g[i-3])%mod;
//		printf("f(%d)=%lld\n",i,f[i]);
		ans^=f[i];
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
7 998244353
Q(p)pi=i
pi<Q(p)i
*/
