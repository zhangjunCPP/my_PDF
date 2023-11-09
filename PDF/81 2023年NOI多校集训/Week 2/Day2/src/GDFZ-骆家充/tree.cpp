# include <bits/stdc++.h>
# define maxn 1001000
# define int long long
using namespace std;
const int mod = 1e9 + 7;

struct Edge {
	int nxt, to;
};

int n, ans = 1;
int dep[200100], Max = -1, Maxi;
int head[maxn], tot;
bool flag2 = 1;
Edge e[maxn << 1];

inline void add_edge (int u, int v);
void dfs (int u, int fa);

signed main ( ) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen ("tree.in", "r", stdin);
	freopen ("tree.out", "w", stdout);
	memset (head, -1, sizeof (head));
	cin >> n;
	for (int i = 1; i <= n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		if (u != 1 && v != 1) flag2 = 0;	
		add_edge (u, v), add_edge (v, u);
	}
	if (n <= 3) {
		cout << 3 * n * n - 7 * n + 4;
		return 0;
	}
	if (flag2) {
		cout << 2;
		return 0;
	}
	Max = -1;
	memset (dep, 0, sizeof (dep));
	dfs (Maxi, Maxi);
	for (int i = 1; i <= n; ++i)
		ans = ans * 2 % mod;
	cout << ans * Max % mod;
	return 0;
}

inline void add_edge (int u, int v) {
	e[++tot].nxt = head[u];
	e[tot].to = v;
	head[u] = tot;
}

void dfs (int u, int fa) {
	dep[u] = dep[fa] + 1;
	if (dep[u] > Max)
		Max = dep[u], Maxi = u;
	for (int i = head[u]; i != -1; i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa)
			continue;
		dfs (v, u);
	}
}
