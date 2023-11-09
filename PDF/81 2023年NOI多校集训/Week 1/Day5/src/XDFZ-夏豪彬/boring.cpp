#include<bits/stdc++.h>
#define int __int128
#define ls k<<1
#define rs k<<1|1 
using namespace std;
inline int read(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
inline void write(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
inline void FRE(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
}
const int maxn=1e5+5;
const int mod=998244353;
int n,q;
int a[maxn];
int sum[4*maxn];
inline int qpow(int a,int b){
	int sum=1;
	while(b){
		if(b&1)sum=(sum*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return sum%mod;
}
inline void pushup(int k){
	int QMOD=qpow(__gcd(sum[ls],sum[rs]),mod-2);//
	sum[k]=sum[ls]*sum[rs]*QMOD%mod;
}
inline void built(int k,int l,int r){
	if(l==r){
		sum[k]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	built(ls,l,mid);
	built(rs,mid+1,r);
	pushup(k);
}
inline int query(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y)return sum[k];
	int mid=(l+r)>>1;
	int A=1,B=1;
	if(x<=mid)A=query(ls,l,mid,x,y)%mod;
	if(mid<y)B=query(rs,mid+1,r,x,y)%mod;
	return A*B*qpow(__gcd(A,B),mod-2)%mod; 
}
signed main(){
	FRE();
	n=read();
	q=read();
	for(int i=1;i<=n;++i)a[i]=read();
	built(1,1,n);
	while(q--){
		int k=read();
		int ans=1;
		for(int i=1;i<=k;++i){
			int L=read(),R=read();
			int res=query(1,1,n,L,R);
			ans=ans*res*qpow(__gcd(ans,res),mod-2)%mod;
		}
		write(ans);
		putchar('\n');
	}
}
