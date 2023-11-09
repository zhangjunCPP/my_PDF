#include<bits/stdc++.h>
#define rep(i,x,y) for (int i = (x); i <= (y); ++i)
#define drep(i,x,y) for (int i = (x); i >= (y); --i)
#define go(i,u) for (int i = head[u]; i; i = edge[i].next)
#define MP make_pair
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int N = 2e5 + 2;
int n, a[N];
long long ans;
inline void calc (vector<int> q) {
	//for (auto x : q) cout << x << " ";
	//cout << '\n' << ans << '\n';
	int n = (int) q.size(), mid = q[((n + 1) >> 1) - 1];
	if (n == 1) return;
	vector<int> ql, qr;
	rep (i, 0, n - 1) {
		++ans;
		if (q[i] < mid) ql.emplace_back(q[i]);
		else if (q[i] > mid) qr.emplace_back(q[i]);
	}
	if (!ql.empty()) calc(ql);
	if (!qr.empty()) calc(qr);
}
inline void solve () {
	scanf("%d", &n);
	vector<int> q;
	rep (i, 1, n) scanf("%d", &a[i]), q.emplace_back(a[i]);
	calc(q);
	printf("%lld\n", ans);
}
inline void freo () {
	freopen("sort.in", "r", stdin), freopen("sort.out", "w", stdout); }
signed main () {
	freo();
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	//cin >> _;
	while (_--) solve();
return 0;
}
/*
5
4 3 5 1 2
*/
