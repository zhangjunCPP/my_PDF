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
int n, p, ans;
int vis[N], a[N], b[N], bc;
int stk[N][2], top[2];
inline void calc () {
	//rep (i, 1, n) a[i] = n - i + 1;
	top[0] = top[1] = bc = 0;
	rep (i, 1, n) {
		if (!top[0] || stk[top[0]][0] > a[i]) stk[++top[0]][0] = a[i];
		else {
			while (top[0] && stk[top[0]][0] < a[i]) {
				if (stk[top[0]][0] < stk[top[1]][1]) stk[++top[1]][1] = stk[top[0]--][0];
				else {
					while (top[1] && stk[top[1]][1] < stk[top[0]][0])
						b[++bc] = stk[top[1]--][1];
					stk[++top[1]][1] = stk[top[0]--][0];
				}
			}
			stk[++top[0]][0] = a[i];
		}
	}
	/*rep (i, 1, n) cout << b[i] << " ";
	cout << '\n';*/
	//cout << 1 << '\n';
	//cout << top[0] << " " << top[1] << '\n';
	while (top[0]) {
		if (stk[top[0]][0] < stk[top[1]][1]) stk[++top[1]][1] = stk[top[0]--][0];
		else {
			while (top[1] && stk[top[1]][1] < stk[top[0]][0])
				b[++bc] = stk[top[1]--][1];
			stk[++top[1]][1] = stk[top[0]--][0];
		}
	}
	//cout << top[1] << '\n';
	while (top[1]) b[++bc] = stk[top[1]--][1];
	int fg = 1;
	/*rep (i, 1, n) cout << a[i] << " ";
	cout << '\n';
	rep (i, 1, n) cout << b[i] << " ";
	cout << '\n';*/
	rep (i, 1, n) if (b[i] != i) {
		fg = 0; break; }
	if (!fg) return;
	/*rep (i, 1, n) cout << a[i] << " ";
	cout << '\n';*/
	ans += fg;
}
inline void dfs (int u) {
	if (u == n + 1) {
		calc();
		return;
	}
	rep (i, 1, n) if (!vis[i]) {
		vis[i] = 1, a[u] = i;
		dfs(u + 1);
		vis[i] = 0, a[u] = 0;
	}
}
inline void solve () {
	cin >> n >> p;
	int fac = 1;
	rep (i, 2, n) fac = fac * i % p;
	ans = 0;
	dfs(1);
	printf("%lld\n", (fac - ans % p + p) % p);
}
inline void freo () {
	freopen("sort.in", "r", stdin), freopen("sort.out", "w", stdout); }
signed main () {
	freo();
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) solve();
return 0;
} 
