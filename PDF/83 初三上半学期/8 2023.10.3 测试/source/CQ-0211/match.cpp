#include<bits/stdc++.h>
using namespace std;
const int N=1e6+16;
int n,m,maxn;
long long b[N],a[N],ans;
void dfs(int now,long long xp) {
	if(now>n) { ans=min(ans,xp); return ; }
	for(int i=b[now];i<=maxn;i++) {
		if( i&xp ) continue;
		int sp=xp; sp|=i; a[now]=i;
		dfs(now+1,sp);
	}
} int cnt[N];
signed main() {
//	freopen("ex_match3.in","r",stdin);
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&n,&m); maxn=(1<<m)-1; ans=maxn;
	for(int i=1;i<=n;i++) {
		int k; scanf("%d",&k);
		if(k>m) { puts("-1"); return 0; }
		while(k--) {
			int x; scanf("%d",&x);
			b[i]|=(1<<(x-1));
		}
	} dfs(1,0); int tot=0;
	while(ans) cnt[++tot]=ans&1, ans>>=1;
	for(int i=m;i>tot;i--) putchar('0');
	for(int i=tot;i>=1;i--) printf("%d",cnt[i]);
	return 0;
}
