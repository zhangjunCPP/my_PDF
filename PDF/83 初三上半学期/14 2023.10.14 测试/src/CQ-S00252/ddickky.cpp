#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=2e5+10;
const int mod=998244353;
int n,q,a[N];
LL sum[N<<4],vis[3010][3010],ans;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void build(int u,int l,int r){
	if(l==r){sum[u]=a[l]%mod;return;}
	int mid=(l+r)>>1;
	build(u<<1,l,mid),build(u<<1|1,mid+1,r);
	sum[u]=gcd(sum[u<<1],sum[u<<1|1])%mod;
}
LL query(int u,int l,int r,int L,int R){
	if(L<=l&&R>=r)return sum[u]%mod;
	int mid=(l+r)>>1;
	LL res=0;
	if(L<=mid)res=gcd(res,query(u<<1,l,mid,L,R))%mod;
	if(R>mid)res=gcd(res,query(u<<1|1,mid+1,r,L,R))%mod;
	return res;
}
LL solve1(int l,int r){
	if(vis[l][r])return vis[l][r];
	return vis[l][r]=query(1,1,n,l,r);
}
int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;++i)a[i]=read();
	build(1,1,n);
	while(q--){
		int l=read(),r=read();
		ans=1ll;
		for(int i=l;i<=r;++i)
			for(int j=i;j<=r;++j)ans=ans*solve1(i,j)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
5 2
8 2 8 8 9
1 5
2 4
*/
