#include<bits/stdc++.h>
#define int long long
const int N=1e6+10,M=1e5+10,inf=1e9;
void Freopen();
void Ftest();
int rd() {
	int x; scanf("%lld",&x);
	return x;
}
using namespace std;
int k,q;
char s[N];
char p[N];
signed main() {
	Freopen();
	k=rd();
	scanf("%s",s+1);
	int n=strlen(s+1);
	q=rd();
	while (q--) {
		scanf("%s",p+1);
		int m=strlen(p+1);
		int ans=0;
		for ( register int l=1; l<=n; l++){
			int r=l+m-1,mx=-inf,mi=inf,f=1;
			if (r>n) break ;
			for ( register int i=l; i<=r; i++) {
				if (mx-mi>=k) {
					f=0;
					break ;
				}
				if (s[i]!=p[i-l+1]) 
					mx=max(mx,i),mi=min(mi,i);
			}
			if (!f) continue ;
			if (mx-mi<k) ans++;
		}
		printf("%lld\n",ans);
	}
}
/*
2
baccbcbabc
7
a
abc
aaa
bbb
abbb
acbbc
iamasuperlongstring
*/
void Freopen() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
}
void Ftest() {
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}

