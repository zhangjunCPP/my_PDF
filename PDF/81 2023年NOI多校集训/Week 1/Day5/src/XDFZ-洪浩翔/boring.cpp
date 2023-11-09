//Ϊʲô ? 
#include<bits/stdc++.h>
#define int long long
const int mod=998244353;
const int QWQ=2e5+5;
using namespace std;
inline int read(){
	char ch=getchar(); int x=0,f=1;
	while (ch<'0'||ch>'9'){ if (ch=='-') f=-1; ch=getchar(); }
	while ('0'<=ch&&ch<='9'){ x=(x<<3)+(x<<1)+(ch-'0'); ch=getchar(); }
	return x*f;
}
int s[QWQ<<2],arr[205][205]; 
int n,m,a[QWQ]; map<pair<int,int>,int> q;
int lcm(int a,int b){ return a/__gcd(a,b)*b; }
void make(int k,int l,int r){
	if (l==r){
		s[k]=a[l];
		return ;
	} int mid=(l+r)>>1;
	make(k<<1,l,mid);
	make(k<<1|1,mid+1,r);
	s[k]=lcm(s[k<<1],s[k<<1|1])%mod;
	q[{l,r}]=s[k]%mod;
}
int ask(int k,int l,int r,int ll,int rr){
	if (ll<=l&&rr>=r) return s[k]%mod;
	int mid=(l+r)>>1; int res=1;
	if (ll<=mid) res=lcm(res,ask(k<<1,l,mid,ll,rr)%mod)%mod;
	if (mid<rr) res=lcm(res,ask(k<<1|1,mid+1,r,ll,rr)%mod)%mod;
	return res;
}
signed main(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),q[{i,i}]=a[i];
	if (n<=200){
		for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++){
			arr[i][j]=a[i];
			for (int k=i+1;k<=j;k++)
				arr[i][j]=lcm(arr[i][j],a[k])%mod;
		} while (m--){
			int k,l,r;
			scanf("%lld%lld%lld",&k,&l,&r);
			int res=arr[l][r];
			for (int i=2;i<=k;i++){
				scanf("%lld%lld",&l,&r);
				res=lcm(res,arr[l][r])%mod;
			} printf("%lld\n",res);
		} return 0;
	}
	make(1,1,n);
	while (m--){
		int k=read(); int res=1;
		for (int i=1;i<=k;i++){
			int l=read(),r=read();
			if (!q[{l,r}]) q[{l,r}]=ask(1,1,n,l,r)%mod;
			res=lcm(res,q[{l,r}]%mod)%mod;
		} printf("%lld\n",res%mod);
	}
	return 0;
}
