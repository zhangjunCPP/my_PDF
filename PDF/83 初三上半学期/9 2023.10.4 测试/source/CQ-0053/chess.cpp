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
const int N = 2e3 + 2;
int n, p, K, a[N][N][2];
int t[N];
vector<int> ans[N * N];
int ansc;
map<pii, int> mp;
inline void solve () {
	cin >> p >> K;
	n = 1;
	rep (i, 1, K) n *= p;
	printf("%lld\n", (n - 1) / (p - 1) * n / p);
	int opt = 0, m = n / p;
	rep (i, 1, m) rep (j, 1, p) a[i][j][opt] = (i - 1) * p + j;
	rep (i, 1, m) {
		++ansc;
		rep (j, 1, p) ans[ansc].emplace_back(a[i][j][opt]);
	}
	rep (_, 1, (n - 1 - (p - 1)) / (p - 1)) {
		int cnt = 0;
		rep (j, 1, p) for (int i = 1; i <= m; i += p) {
			++cnt;
			rep (k, i, i + p - 1) a[cnt][k - i + 1][opt ^ 1] = a[k][j][opt];
		}
		opt ^= 1;
		rep (i, 1, m) {
			++ansc;
			rep (j, 1, p) ans[ansc].emplace_back(a[i][j][opt]);
		}
		int delta = 0;
		rep (i, 1, m) {
			if (delta) {
				rep (j, 1, p) t[j] = a[i][j][opt];
				rep (j, 1, delta) a[i][j][opt] = t[p - delta + j];
				rep (j, delta + 1, p) a[i][j][opt] = t[j - delta];
			}
			++delta;
			if (delta == p) delta = 0;
		}
	}
	/*rep (_, 1, ansc) {
		rep (i, 0, p - 1) rep (j, i + 1, p - 1) {
			if (mp.find(MP(ans[_][i], ans[_][j])) != mp.end()) return printf("-1\n"), void();
			else mp[MP(ans[_][i], ans[_][j])] = mp[MP(ans[_][j], ans[_][i])] = 1;
		}
	}*/
	rep (i, 1, ansc) {
		sort(ans[i].begin(), ans[i].end());
		for (auto x : ans[i]) printf("%lld ", x - 1);
		printf("\n");
	}
}
inline void freo () {
	freopen("chess.in", "r", stdin), freopen("chess.out", "w", stdout); }
signed main () {
	freo();
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	//cin >> _;
	while (_--) solve();
return 0;
} 
