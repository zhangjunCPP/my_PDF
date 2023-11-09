#include<bits/stdc++.h>
#define int long long
#define mod 998244353
#define rep(i,x,y) for (int i = (x); i <= (y); ++i)
#define drep(i,x,y) for (int i = (x); i >= (y); --i)
#define go(i,u) for (int i = head[u]; i; i = edge[i].next)
#define MP make_pair
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int N = 2e5 + 2, MX = 5e2 + 2;
int n, Q;
struct Ques { int l, r; }ques[N];
int a[N];
vector<int> prim[N];
vector<int> pri;
bool vis[N];
int mx, cnt[22];
inline int ksm (int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = ret * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ret;
}
inline void get_prime () {
	rep (i, 2, N - 1) {
		if (!vis[i]) {
			pri.emplace_back(i);
			for (int j = i; j < N; j += i)
				prim[j].emplace_back(i), vis[j] = 1;
		}
	}
}
namespace Solve2 {
	vector<int> vec[N][22];
	int ans;
}
inline void solve2 () {
	using namespace Solve2;
	rep (i, 1, n) {
		int now = a[i];
		for (auto x : prim[a[i]]) {
			int cnt = 0;
			while (!(now % x)) now /= x, ++cnt;
			vec[x][cnt].emplace_back(i); 
			//cout << x << " " << cnt << " " << i << '\n';
		}
	}
	rep (_, 1, Q) {
		ans = 1;
		int L = ques[_].l, R = ques[_].r;
		for (auto x : pri) {
			int now = x, sum = 0, lim = 0;
			rep (i, 1, MX) {
				if (now > mx) break;
				int ob = L, l = 0, r = (int) vec[x][i].size() - 1, retL = -1, retR = -1;
				while (l <= r) {
					int mid = (l + r) >> 1;
					if (vec[x][i][mid] < ob) retL = mid, l = mid + 1;
					else r = mid - 1;
				}
				ob = R, l = 0, r = (int) vec[x][i].size() - 1;
				while (l <= r) {
					int mid = (l + r) >> 1;
					if (vec[x][i][mid] <= ob) retR = mid, l = mid + 1;
					else r = mid - 1;
				}
				cnt[i] = retR - retL, now = now * x;
				if (cnt[i]) lim = i;
			}
			drep (i, lim, 1) if (cnt[i]) {
				//cout << x << " " << i << '\n';
				ans = ans * ksm(ksm(x, i), (ksm(2, sum + cnt[i]) - ksm(2, sum) + mod) % mod) % mod;
				sum += cnt[i];
			}
		}
		printf("%lld\n", ans);
	}
}
inline void solve () {
	get_prime();
	cin >> n >> Q;
	rep (i, 1, n) cin >> a[i], mx = max(mx, a[i]);
	rep (i, 1, Q) cin >> ques[i].l >> ques[i].r;
	if (mx <= 450) return solve2(), void();
}
inline void freo () {
	freopen("ddickky.in", "r", stdin), freopen("ddickky.out", "w", stdout); }
signed main () {
	freo();
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	//cin >> _;
	while (_--) solve();
return 0;
}
/*
3 1
2 4 3
1 3
*/
/*
5 2
8 2 8 8 9
1 5
2 4
*/
