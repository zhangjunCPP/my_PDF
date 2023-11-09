#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+10;
const __int128 mod=998244353;
int n,q,a[N];
__int128 s[N*4];
//int ksm(int x,int y){
//	int ans=1;
//	while(y){
//		if(y&1)ans=ans*x%mod;
//		x=x*x%mod;
//		y>>=1;
//	}
//	return ans;
//}
__int128 gcd(__int128 x,__int128 y){
	if(y==0)return x;
	return gcd(y,x%y);
}
__int128 lcm(__int128 x,__int128 y){
	return x*y/gcd(x,y);
//	return x*y%mod*ksm(gcd(x,y),mod-2)%mod;
}
void build(int k,int l,int r){
	if(l==r){
		s[k]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	s[k]=lcm(s[k<<1],s[k<<1|1]);
}
__int128 qjcx(int k,int l,int r,int x,int y){
	if(l>=x&&r<=y){
		return s[k];
	}
	int mid=(l+r)>>1;
	__int128 s=1;
	if(mid>=x)s=lcm(s,qjcx(k<<1,l,mid,x,y));
	if(y>mid)s=lcm(s,qjcx(k<<1|1,mid+1,r,x,y));
	return s;
}
signed main(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]); 
	build(1,1,n);
	for(int i=1;i<=q;i++){
		int k,l,r;
		__int128 ans=1;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&l,&r);
			ans=lcm(ans,qjcx(1,1,n,l,r));
		}
		long long anss=ans%mod; 
		printf("%lld\n",anss);
	}
	return 0;
}
/*
10 4
2 7 4 3 5 1 3 9 5 1
5 2 2 4 4 6 6 7 7 10 10
2 1 4 8 8
3 1 3 2 2 7 9
2 1 1 2 2
*/
