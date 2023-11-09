#include <bits/stdc++.h>
#define int long long
void Freopen();
void Ft();
int rd();
const int N=2e5+10, M=2e5+10, inf=1e9+10;
const unsigned long long bse=127;
using namespace std;
int n, q;
char s[N];
int size[N];
unsigned long long hh[N], hs[N][32], pw[N];
signed main() {
	Freopen();
//	Ft();
	n=rd();
	for ( int t=1; t<=n; t++) {
		scanf("%s", s+1);
		int len=strlen(s+1);
		pw[0]=1;
		for ( int i=1; i<=len; i++) hs[t][i]=hs[t][i-1]*bse+s[i],
			pw[i]=pw[i-1]*bse;
		size[t]=len;
	}
	q=rd();
//	if (n<=30000&&q<=30000) {
		while (q--) {
			scanf("%s", s+1);
			int len=strlen(s+1);
			for ( int i=1; i<=len; i++) hh[i]=0;
			for ( int i=1; i<=len; i++) hh[i]=hh[i-1]*bse+s[i];
			int ans=0;
			for ( int i=1; i<=n; i++) {
				ans++;
				for ( int j=1; j<=min(len, size[i]); j++) {
					if (hh[j]==hs[i][j]) ans++;
					else break ;
				}
				if (len==size[i]&&hh[len]==hs[i][size[i]]) break ;
			}
			printf("%lld\n", ans);
		}
		return 0;
//	}
//	while (q--) {
//		scanf("%s", s+1);
//		int len=strlen(s+1);
//		int ans=0;
		
//	}
}
void Freopen() {
	freopen("lihua.in", "r", stdin);
	freopen("lihua.out", "w", stdout);
}
void Ft() {
	freopen("ex_lihua3.in", "r", stdin);
	freopen("lihua.out", "w", stdout);
}
int rd() {
	int x; scanf("%lld", &x);
	return x;
}

