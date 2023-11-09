#include<bits/stdc++.h>
#define int long long
#define rep(i,x,y) for (int i = (x); i <= (y); ++i)
#define drep(i,x,y) for (int i = (x); i >= (y); --i)
#define go(i,u) for (int i = head[u]; i; i = edge[i].next)
#define MP make_pair
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int N = 2e5 + 2;
int K, Q;
char s[N], t[N];
int n, m;
inline void solve () {
	scanf("%lld", &K);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	scanf("%lld", &Q);
	while (Q--) {
		scanf("%s", t + 1);
		m = strlen(t + 1);
		int ans = 0;
		rep (l, 1, n) {
			int r = l + m - 1;
			if (r > n) break;
			int lt = -1, fg = 1;
			rep (j, l, r) {
				if (s[j] != t[j - l + 1]) {
					if (lt == -1) lt = j;
					else {
						if (j - lt >= K) {
							fg = 0; break; }
					}
				}
			}
			ans += fg;
		}
		printf("%lld\n", ans);
	}
}
inline void freo () {
	freopen("match.in", "r", stdin), freopen("match.out", "w", stdout); }
signed main () {
	freo();
	int _ = 1;
	//cin >> _;
	while (_--) solve();
	
return 0;
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
