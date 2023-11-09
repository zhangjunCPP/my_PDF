#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn=110;
int fac[maxn],inv[maxn],n,mod;

 void exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
inline void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	int x,y;
	exgcd(fac[n],mod,x,y);
	inv[n]=(x%mod+mod)%mod;
	inv[0]=1;
	for(int i=n-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}

int A(int n,int m){
	if(n<m) return 0;
	if(m==0) return 1;
	return 1ll*fac[n]*inv[n-m]%mod;
}
int C(int n,int m){
	if(n<m) return 0;
	if(m==0) return 1;
	return 1ll*fac[n]*inv[n-m]%mod*inv[m]%mod;
}

int f[maxn];

signed main(){
	
	scanf("%lld %lld",&n,&mod);
	
	init(n);
	
	int res=1;
	
	int inv2,tttt;
	exgcd(2,mod,inv2,tttt);
	inv2=(inv2%mod+mod)%mod;
	
	// printf("first : %d\n",inv2);
	
	for(int j=1;j<=n-2;j++){
		f[j]=0;
		for(int k=0;k<j;k++){
			if((j-k-1)&1) continue;
			int kkk=1;
			for(int now=j-k-1;now>=2;now-=2) kkk=kkk*C(now,2)%mod;
			f[j]=(f[j]+1ll*C(j-1,k)*kkk%mod)%mod;
		}
	}
	
	for(int i=4;i<=n;i++){
		int x=0;
		for(int j=1;j+2<=i;j++){
			int tt=f[j];
			// printf("kk%d\n",tt);
			for(int k=0;k<=i-j-2;k++){
				int tmp=1ll*A(i-j,k+2)*inv2%mod*fac[i-j-k-2]%mod;
				printf("%lld %lld : %lld\n",j,k,1ll*tmp*tt%mod);
				x=(x+1ll*tmp*tt%mod)%mod;
			}
		}
		printf("xxxxxxxxxxxxx%lld\n",x);
		res^=x;
	}
	
	printf("%lld\n",res);
	
	return 0;
}