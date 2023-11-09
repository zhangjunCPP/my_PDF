
#include<bits/stdc++.h>
using namespace std; 
namespace io{
	template<typename T> void read(T &x){
		x=0; bool f=0; char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()){
			if(ch=='-'){
				f=1;
			}
		} 
		for(;ch>='0'&&ch<='9';ch=getchar()){
			x=(x<<1)+(x<<3)+(ch^48);
		}
		x=f?-x:x;
	}
	template<typename T> void write(T x){
		if(x<0){
			x=-x,putchar('-');
		}
		if(x>9){
			write(x/10);
		}
		putchar(x%10+'0');
	}
}
using ll=unsigned __int128;
const ll p=998244353;
const int N=1e5+5;
int n,q;
ll a[N];
ll gcd(ll x,ll y){
	if(!y){
		return x;
	}
	return gcd(y,x%y);
}
ll lcm(ll x,ll y){
	return x*y/gcd(x,y)/*%p*/;
}
struct segment_tree{
	#define ls (rt<<1)
	#define rs (rt<<1|1)
	#define mid ((l+r)>>1)
	ll lm[N<<2];
	void push_up(int rt){
		lm[rt]=lcm(lm[ls],lm[rs]);
	}
	
	void build(int rt,int l,int r){
		if(l==r){
			lm[rt]=a[l];
			return ;
		}
		build(ls,l,mid),build(rs,mid+1,r);
		push_up(rt); 
	}
	ll query(int rt,int l,int r,int L,int R){
		if(L<=l&&r<=R){
			return lm[rt]; 
		}
		ll res=1;
		if(L<=mid){
			res=lcm(res,query(ls,l,mid,L,R))/*%p*/;
		}
		if(R>mid){
			res=lcm(res,query(rs,mid+1,r,L,R))/*%p*/;
		}
		return res;
	}
	#undef ls
	#undef rs
	#undef mid
}sgt;

signed main(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	io::read(n),io::read(q);
	for(int i=1;i<=n;i++){
		io::read(a[i]);
	}
	sgt.build(1,1,n);
	for(;q--;){
		ll ans=1;
		int k;
		io::read(k);
		for(int i=1;i<=k;i++){
			int l,r;
			io::read(l),io::read(r);
			ans=lcm(ans,sgt.query(1,1,n,l,r))/*%p*/;
		}
		io::write(ans%p),putchar('\n');
	}
	return 0;
}
