#include<bits/stdc++.h>
const int maxn = 2e5 + 10;
int n, m, k;
std::vector<std::pair<int, int> > G[maxn];
int d[maxn];
int dis[maxn];
bool vis[maxn];
std::priority_queue<int> Q[maxn]; 
int main() {
	freopen("maze.in", "r", stdin);
	freopen("maze.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	memset(dis, 0x3f, sizeof(dis)); 
	for (int i = 1; i <= k; i++) {
		int x;
		scanf("%d", &x);
		dis[x] = 0;
	}
	for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		G[x].emplace_back(y, z), G[y].emplace_back(x, z);
	}
	std::priority_queue<std::pair<int, int> > q;
	for (int i = 1; i <= n; i++)
		q.emplace(-dis[i], i);
	for (; ! q.empty(); ) {
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		if (dis[u] == dis[0] && dis[1] == dis[0]) {printf("-1\n"); return 0;}
		for (std::pair<int, int> i : G[u]) {
			int v = i.first, w = i.second;
			Q[v].push(dis[u] + w);
			if (int(Q[v].size()) > d[v] + 1) Q[v].pop();
			if (int(Q[v].size()) == d[v] + 1 && Q[v].top() < dis[v]) {dis[v] = Q[v].top(), q.emplace(-dis[v], v);};
		}
	}
	printf("%d\n", dis[1]);
	return 0;
}