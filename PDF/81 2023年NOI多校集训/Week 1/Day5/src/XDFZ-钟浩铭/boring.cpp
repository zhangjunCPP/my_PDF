#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e6+10;
const ll mod=998244353;
int n,q,len;
ll a[MAXN],num[MAXN];
//inline int read(){
//	int x=0,f=1; char ch=getchar();
//	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
//	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
//	return x*f;
//}
ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
}
signed main(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int t=1;t<=q;t++){
		int k,l,r; scanf("%d",&k);
		len=0;
		for(int i=1;i<=k;i++){
			scanf("%d%d",&l,&r);
			ll lcm=1;
			for(int x=l;x<=r;x++)
				lcm=lcm*a[x]/gcd(lcm,a[x])%mod;
			num[++len]=lcm%mod;
		}
		ll lcm1=1; 
		for(int x=1;x<=len;x++)
			lcm1=lcm1*num[x]/gcd(lcm1,num[x])%mod;
		printf("%lld\n",(lcm1+mod)%mod);
	}
	return 0;
}
