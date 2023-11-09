#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const long long mod=998244353;
long long a[N];
long long gcd(long long x,long long y)
{
	if(x%y==0)
	{
		return y;
	}
	return gcd(y,x%y);
}
struct Seg{
	int l,r;
	long long lcm;
};
Seg tree[N*4];
void push_up(int p)
{
	long long temp=gcd(tree[p*2].lcm,tree[p*2+1].lcm);
    long long mulsum=tree[p*2].lcm*tree[p*2+1].lcm;
	tree[p].lcm=mulsum/temp%mod;
}
void build(int p,int l,int r)
{
	tree[p].l=l,tree[p].r=r;
	if(l==r)
	{
		tree[p].lcm=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	push_up(p);
}
long long ask(int p,int l,int r)
{
    if(l==tree[p].l && tree[p].r==r)
    {
    	return tree[p].lcm%mod;
	}
	int mid=(tree[p].l+tree[p].r)/2;
	if(l>mid)
	{
		return ask(p*2+1,l,r)%mod;
	}
	else if(r<=mid)
	{
		return ask(p*2,l,r)%mod;
	}
	else
	{
		long long ans,L=ask(p*2,l,mid)%mod,R=ask(p*2+1,mid+1,r)%mod;
		long long temp=gcd(L,R);
		long long mulsum=L*R;
		ans=(mulsum/temp)%mod;
		return ans;
	}
}
int main(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	build(1,1,n);
	for(int i=1;i<=q;++i)
	{
		int k;
		long long sum=1;
		scanf("%d",&k);
		while(k--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			long long lcm=ask(1,l,r);
			long long temp=gcd(sum,lcm);
			long long mulsum=sum*lcm;
			sum=(mulsum/temp)%mod;
		}
		printf("%lld\n",sum%mod);
	}
}
