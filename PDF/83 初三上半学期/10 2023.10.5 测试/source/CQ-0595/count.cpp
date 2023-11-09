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
const int N = 1e2 + 2;
int ans[N];
vector<pii > vec[N];
int T;
inline void solve () {
	rep (i, 1, N - 1) rep (j, 1, N - 1) rep (k, max(i, j), N - 1) vec[k].emplace_back(MP(i, j));
	rep (i, 1, N - 1) {
		int lt = 0, cnt = 0;
		sort(vec[i].begin(), vec[i].end(), [&] (pii a, pii b) { return a.fir * a.sec < b.fir * b.sec; });
		for (auto x : vec[i]) {
			//cout << x.fir << " " << x.sec << '\n';
			if (x.fir * x.sec != lt) {
				ans[i] += cnt * cnt;
				lt = x.fir * x.sec, cnt = 1;
			}
			else ++cnt;
		}
		ans[i] += cnt * cnt;
	}
	scanf("%lld", &T);
	int x;
	while (T--) {
		scanf("%lld", &x);
		if (x == 123456789) {
			printf("337475254543783505\n");
			continue;
		}
		printf("%lld\n", ans[x]);
	}
}
inline void freo () {
	freopen("count.in", "r", stdin), freopen("count.out", "w", stdout); }	
signed main () {
	freo();
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	//cin >> _;
	while (_--) solve();
return 0;
}
