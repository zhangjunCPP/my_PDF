#include<bits/stdc++.h>
#define ll long long
#define lson k<<1
#define rson k<<1|1
using namespace std;
const int N=1e5+15;
const int mod=998244353;
int n,q;
ll a[N];
ll ksm(ll x,ll y) {
	ll ans=1;
	while(y) {
		if(y&1) ans=( ans*x )%mod;
		x=( x*x )%mod; y>>=1;
	}
	return ans;
}

ll t[N<<4],t2[N<<4];
void bird(int k,int l,int r) {
	if(l==r) { t[k]=t2[k]=a[l]; return ; }
	int mid=( ( l+r )>>1 );
	bird(lson,l,mid);
	bird(rson,mid+1,r);
	t[k]=__gcd( t[lson],t[rson] );
	t2[k]=( t2[lson]*t2[rson] )%mod;
	//cout<<l<<" "<<r<<" "<<t[k]<<endl;
}

ll gdc,angdc;
void alt(int k,int l,int r,int x,int y) {
	if( x<=l&&r<=y ) {
		gdc=__gcd( gdc,t[k] );
		//cout<<lcm<<" ";
		return ;
	}
	int mid=( ( l+r )>>1 );
	if(x<=mid) alt(lson,l,mid,x,y);
	if(y>mid) alt(rson,mid+1,r,x,y);
}

ll esm=1;
void alt2(int k,int l,int r,int x,int y) {
	if( x<=l&&r<=y ) {
		esm=( esm*t2[k] )%mod;
		return ;
	}
	int mid=( ( l+r )>>1 );
	if(x<=mid) alt2(lson,l,mid,x,y);
	if(y>mid) alt2(rson,mid+1,r,x,y);
}

int main() {
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	bird(1,1,n);
	while(q--) {
		int k,l,r;
		scanf("%d",&k); 
		angdc=0; ll jj=1;
		int ml=0,mr=n;
		for(int i=1;i<=k;i++) {
			scanf("%d%d",&l,&r);
			gdc=0; alt(1,1,n,l,r);
			angdc=__gcd( angdc,gdc );
			esm=1; alt2(1,1,n,l,r);
			//cout<<esm<<" ";
			jj=( jj*esm )%mod;
			jj=( jj*ksm(gdc,mod-2) )%mod;
			
			//cout<<jj<<" "; 
			ml=max(ml,l); mr=min(mr,r);
		}
		//cout<<jj<<endl;
		esm=1; alt2(1,1,n,ml,mr);
		//cout<<ml<<" "<<mr<<endl; 
		esm=( esm*ksm( angdc,mod-2 ) )%mod;
		//cout<<esm<<" "<<jj<<endl;
		if(k==1) esm=1;
		//cout<<"what???";
		//cout<<gdc<<" "; 
		ll ans=( jj*ksm(esm,mod-2) )%mod;
		//puts("");
		printf("%lld\n",ans);
	}
	return 0;
}
