#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+25;
const int inf=0x3f3f3f3f;
int n,a[N];
int ans=inf;
void dfs(int now,int maxn,int minn) {
	if(now>n) { ans=min(ans,maxn-minn); return ; }
	int xpm=maxn,xpn=minn;
	if(now!=n) {
		xpm=max( xpm,a[now]+a[now+1] );
		xpn=min( xpn,a[now]+a[now+1] );
		if(xpm-xpn<ans) dfs(now+2,xpm,xpn);	
	} xpm=maxn,xpn=minn;
	xpm=max( xpm,a[now] );
	xpn=min( xpn,a[now] );
	if(xpm-xpn<ans) dfs(now+1,xpm,xpn);	
} 
signed main() {
//	freopen("ex_segment2.in","r",stdin);
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	dfs(1,0,inf); printf("%lld",ans);
	return 0;
}
