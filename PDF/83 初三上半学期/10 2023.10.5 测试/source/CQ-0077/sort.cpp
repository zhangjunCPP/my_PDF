#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mid ((l+r)>>1)
#define ls (rt<<1)
#define rs (rt<<1|1)
#define pb push_back
#define pii pair<ll,ll>
const ll N=5e5+5,mod=998244353,inf=0x3f3f3f3f,INF=1e18;
int n,a[N];
int ans1,L[N],R[N];
void Sort(int l,int r) {
	if(l>=r) return;
	int len=r-l+1;
	int Mid=a[l+(int)ceil(1.0*len/2)-1];
	int lenL=0,lenR=0;
	for(int i=l;i<=r;i++){
		if(a[i]<Mid) L[++lenL]=a[i];
		if(a[i]>Mid) R[++lenR]=a[i];
	}
	ans1+=r-l+1;
	a[l+lenL]=Mid;
	for(int i=l;i<=l+lenL-1;i++) a[i]=L[i-l+1];
	for(int i=r;i>=r-lenR+1;i--) a[i]=R[i-r+lenR];
	Sort(l,l+lenL-1);
	Sort(r-lenR+1,r);
}
void solve() {
	Sort(1,n);
	printf("%d",ans1);
}
signed main() {
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve();
	return 0;
}
