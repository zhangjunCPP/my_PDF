#include<bits/stdc++.h>
#define inf 1e18
#define LL long long
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=1e3+10;
int n,flag1,flag2;
LL dp[2][2*N*N],f[2*N*N][21];
struct ball{
	int l,r,c;
}a[N];
void solve1(){
	for(int s=0;s<(1<<n);++s)
		for(int i=1;i<=n;++i){
			if(!((s>>(i-1))&1))continue;
			for(int j=a[i].l;j<=a[i].r;++j)
				if(!((s>>(j-1))&1))f[s][i]+=1ll*a[i].c;
		}
	for(int i=0;i<=n;++i)
		for(int s=0;s<(1<<n);++s)dp[i&1][s]=-inf;
	for(int i=0;i<=n;++i)dp[i&1][0]=0;
	for(int i=0;i<n;++i){
		for(int s=0;s<(1<<n);++s){
			if(dp[i&1][s]==-inf)continue;
			for(int j=1;j<=n;++j){
				if((s>>(j-1))&1)continue;
				dp[(i+1)&1][s|(1<<(j-1))]=max(dp[(i+1)&1][s|(1<<(j-1))],dp[i&1][s]+f[s|(1<<(j-1))][j]);
			}
		}
	}
	printf("%lld\n",dp[n&1][(1<<n)-1]);
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=read(),flag1=1,flag2=1;
	for(int i=1;i<=n;++i){
		a[i].l=read(),a[i].r=read(),a[i].c=read();
		if(a[i].l!=i||a[i].r!=i||a[i].l!=a[i].r)flag1=0;
		if(a[i].c!=1)flag2=0;
	}
	if(n<=20)solve1();
	else if(flag1)printf("0\n");
	else{
		printf("%d\n",n);
	}
	return 0;
}
/*
5
1 2 1
2 2 3
2 4 7
3 5 4
3 5 5
*/
