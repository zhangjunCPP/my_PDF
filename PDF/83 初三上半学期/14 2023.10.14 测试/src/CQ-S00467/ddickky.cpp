#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int MAXN=2e5+10;
inline void Freopen(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
}
template <typename T>
inline void read(T &x){
	bool f=0; x=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
}
template <typename T,typename ...Args>
inline void read(T &x,Args &...args){read(x); read(args...);}
int n,q;
int a[MAXN],tree[MAXN<<2],G[MAXN<<2];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
#define lson (p<<1)
#define rson (p<<1|1)
void build(int p,int l,int r){
	if(l==r){tree[p]=a[l]; G[p]=a[l]; return ;}
	int mid=(l+r)>>1;
	build(lson,l,mid); build(rson,mid+1,r);
	G[p]=gcd(G[lson],G[rson]);
	tree[p]=G[p]*tree[lson]%mod*tree[rson]%mod;
}
int query(int p,int l,int r,int L,int R){
	if(L<=l && r<=R){return tree[p];}
	int mid=(l+r)>>1,res=1;
	if(L<=mid) res=res*query(lson,l,mid,L,R)%mod;
	if(R>mid) res=res*query(rson,mid+1,r,L,R)%mod;
	return res;
}
signed main(){
	Freopen();
	for(int i=1;i<=MAXN;i++) tree[i]=1,G[i]=1;
	read(n,q);
	for(int i=1;i<=n;i++) read(a[i]);
	build(1,1,n);
	while(q--){
		int l,r; read(l,r);
//		for(int i=1;i<=(1<<n)-1;i++) printf("%d ",tree[i]);
		printf("%lld\n",query(1,1,n,l,r));
	}
	return 0;
} 
/*
3 1
2 4 3
1 3

5 2
8 2 8 8 9
1 5
2 4

3 1
2 4 6
1 3
*/
