#include<bits/stdc++.h>
#define rep(i,x,y) for (int i = (x); i <= (y); ++i)
#define drep(i,x,y) for (int i = (x); i >= (y); --i)
#define go(i,u) for (int i = head[u]; i; i = edge[i].next)
#define MP make_pair
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int N = 1e6 + 2;
int n, m, ans;
int head[N], pos;
struct Edge { int to, next; }edge[N << 1];
inline void add_edge (int u, int v) {
	edge[++pos] = (Edge) {v, head[u]}, head[u] = pos; }
int du[N], dep[N], fath[N];
inline void dfs (int u, int fa) {
	dep[u] = dep[fa] + 1, fath[u] = fa;
	go (i, u) {
		int v = edge[i].to;
		if (v == fa) continue;
		if (dep[v]) {
			if (fath[fath[u]] == v) ans = max(ans, 3);
			continue;
		}
		dfs(v, u);
	}
}
inline void solve () {
	scanf("%d%d", &n, &m);
	rep (i, 1, n) head[i] = du[i] = dep[i] = fath[i] = 0;
	pos = ans = 0;
	int u, v;
	rep (i, 1, m) {
		scanf("%d%d", &u, &v), add_edge(u, v), add_edge(v, u);
		++du[u], ++du[v];
	}
	rep (i, 1, n) if (!dep[i])
		dfs(i, 0);
	rep (i, 1, n) ans = max(ans, du[i]);
	printf("%d\n", ans);
}
inline void freo () {
	freopen("match.in", "r", stdin), freopen("match.out", "w", stdout); }
signed main () {
	freo();
	int _ = 1;
	scanf("%d", &_);
	while (_--) solve();
return 0;
}
/*
3
4 1
2 3
1 0
5 4
3 2
5 3
5 1
4 5
*/
/*
16
7 3
7 5
5 1
1 7
1 0
1 0
3 3
1 2
2 3
3 1
10 5
3 7
9 5
6 1
6 8
1 7
6 1
6 3
1 0
21 9
21 16
14 20
14 6
4 17
17 5
4 9
18 3
15 8
12 15
1 0
8 0
3 0
1 0
6 1
3 2
1 0
19 1
19 17
13 8
11 13
6 5
6 10
4 11
2 6
11 2
10 7
2 9
1 0
*/
