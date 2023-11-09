#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=100005,INF=1e9,mod=998244353;
int _;
int n,q;
int a[maxn];
int tree[maxn<<2];

int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
} 

int lcm(int a,int b){
	return a*b/gcd(a,b);
}

void pushup(int p){
	tree[p]=lcm(tree[p<<1],tree[p<<1|1]);
}

void build(int l,int r,int p){
	if(l==r){
		tree[p]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	pushup(p);
}

int query(int l,int r,int s,int t,int p){
	if(s<=l and r<=t){
		return tree[p];
	}
	int mid=l+r>>1;
	if(s<=mid and mid<t){
		return lcm(query(l,mid,s,t,p<<1),query(mid+1,r,s,t,p<<1|1));
	}
	else if(s<=mid)return query(l,mid,s,t,p<<1);
	else if(t>mid)return query(mid+1,r,s,t,p<<1|1);
}

signed main(){
	ios::sync_with_stdio(0);
	freopen("boring.in","r",stdin); 
	freopen("boring.out","w",stdout); 
	cin>>n>>q;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	
	build(1,n,1);
	
	while(q--){
		int m;
		cin>>m;
		int l,r;
		cin>>l>>r;
		int ans=query(1,n,l,r,1);
		for(int i=2;i<=m;i++){
			cin>>l>>r;
			ans=lcm(ans,query(1,n,l,r,1))%mod;
		}
		cout<<ans<<endl;
	}
	
    return 0 ^ _ ^ 0;
}



