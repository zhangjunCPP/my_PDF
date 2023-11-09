#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5 + 5, M = 4e5 + 5;
const ll inf = 1e10, Max = 2e9;
int n, m, k, tot = 1;

int ed[N], deg[N];
vector<int> E[N], G[N];
vector<ll> cho[N];
ll dis[N];
int fir[N], ver[M], edge[M], nxt[M];
int ins[N], vis[N];
void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, nxt[tot] = fir[x], fir[x] = tot;
	E[x].push_back(y), G[x].push_back(z);
}
ll dfs(int x) {
	ins[x] = vis[x] = 1;
	if (ed[x]) {
		dis[x] = 0; ins[x] = 0;
		return 0;
	}
	for (int i = fir[x]; i; i = nxt[i]) {
		int y = ver[i], z = edge[i];
		if (ins[y]) {
			cho[x].push_back(inf);
		} else if (vis[y]) {
			cho[x].push_back(dis[y] + z);
		} else {
			cho[x].push_back(dfs(y) + z);
		}
	}
	sort(cho[x].begin(), cho[x].end());
	int siz = cho[x].size();
	if (deg[x] >= siz) dis[x] = inf;
	else dis[x] = cho[x][deg[x]];
	dis[x] = min(dis[x], inf);
	ins[x] = 0;
	return dis[x];
}
int main() {
	freopen("maze.in", "r", stdin);
	freopen("maze.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, x; i <= k; i++) {
		scanf("%d", &x), ed[x] = 1;
	}
	for (int i = 1; i <= n; i++) scanf("%d", &deg[i]);
	for (int i = 1, x, y, z; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	ll ans = dfs(1);
	if (ans > Max) {
		printf("%d", -1);
	} else {
		printf("%lld", ans);
	}
	return 0;
}
