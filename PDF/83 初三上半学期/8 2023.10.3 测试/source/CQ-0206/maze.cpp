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
const int N = 5e5 + 2, INF = 1e18 + 2;
int n, m, K;
int s[N], d[N];
int head[N], pos;
struct Edge { int to, next, dis; }edge[N << 1];
inline void add_edge (int u, int v, int w) {
	edge[++pos] = (Edge) {v, head[u], w}, head[u] = pos; }
bool isout[N];
priority_queue<pii , vector<pii >, greater<pii > > q;
vector<int> t[N];
int f[N];
bool vis[N];
inline void freo () {
	freopen("maze.in", "r", stdin), freopen("maze.out", "w", stdout); }
signed main () {
	freo();
	scanf("%lld%lld%lld", &n, &m, &K);
	rep (i, 1, n) f[i] = INF;
	rep (i, 1, K) scanf("%lld", &s[i]), isout[s[i]] = 1, f[s[i]] = 0;
	rep (i, 1, n) {
		scanf("%lld", &d[i]);
		if (isout[i]) d[i] = 0;
	}
	int u, v, w;
	rep (i, 1, m) {
		scanf("%lld%lld%lld", &u, &v, &w);
		add_edge(u, v, w), add_edge(v, u, w);
	}
	rep (i, 1, K) q.push(MP(f[s[i]], s[i]));
	while (!q.empty()) {
		int u = q.top().sec;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		go (i, u) {
			int v = edge[i].to, w = edge[i].dis;
			if (isout[v]) continue;
			t[v].emplace_back(f[u] + w);
			if ((int) t[v].size() >= d[v] + 1) {
				sort(t[v].begin(), t[v].end());
				f[v] = t[v][d[v]];
				q.push(MP(f[v], v));
			}
		}
	}
	/*rep (i, 1, n) cout << f[i] << " ";
	cout << '\n';*/
	if (f[1] == INF) printf("-1\n");
	else printf("%lld\n", f[1]);
return 0; 
}
/*
5 8 3
2 3 5
2 0 1 1 2
1 2 1
2 3 2
3 4 5
2 5 3
4 5 2
5 1 3
3 5 2
4 1 1
*/
