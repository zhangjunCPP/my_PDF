#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
inline int read(){
    char ch=getchar();int sum=0,f=1;
    while(!isdigit(ch))f=(ch=='-')?-1:1,ch=getchar();
    while(isdigit(ch))sum=(sum<<1)+(sum<<3)+(ch^48),ch=getchar();
    return sum*f;
}
const int maxn=2e5+4;
int n,mod;
int sum[maxn],inv[maxn];
int fast_pow(int x,int y){
	int res=1;
	for(;y;y>>=1,x=x*x%mod)if(y&1)res=res*x%mod;
	return res; 
}
void init(){
	sum[0]=1;inv[0]=fast_pow(sum[0],mod-2);
	for(int i=1;i<maxn;++i)sum[i]=sum[i-1]*i%mod,inv[i]=fast_pow(sum[i],mod-2);
}
int C(int n,int m){
	if(m==0)return 1;
	if(n==m)return 1;
	return sum[n]*inv[n-m]%mod*inv[m]%mod;
}
signed main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	n=read();mod=read();
	init();
	int ans=0;
	for(int i=1;i<=n;++i){
		int cnt=1;
		for(int j=1;j<=i/2;++j){
			int x=i,yuan=1;
			for(int k=1;k<=j;++k){
				yuan=yuan*C(x,2)%mod;
				x-=2;
			}
			cnt=(cnt+yuan*inv[j]%mod)%mod;
		}
		ans=ans^((sum[i]-cnt+mod)%mod*inv[2]%mod);
	}
	printf("%lld",ans);
	return 0;
}
