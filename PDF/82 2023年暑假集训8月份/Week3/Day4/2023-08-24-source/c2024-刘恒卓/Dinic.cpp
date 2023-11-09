#include<bits/stdc++.h>
using ll = long long;
const ll inf = 0x3f3f3f3f3f3f;
const int N = 1e2 + 10, M = 5e3 + 10;
int v[M * 2], nxt[M * 2], fir[N], ft = 1;
ll w[M * 2];
void Add(int u, int v, ll w, int flag = 1) {
	ft++, ::v[ft] = v, ::w[ft] = w, nxt[ft] = fir[u], fir[u] = ft;
	flag && (Add(v, u, 0, 0), 1);
}
ll dis[N];
int hd[N];
bool BFS(int n, int s, int t) {
	for (int i = 1; i <= n; i++) {
		dis[i] = inf, hd[i] = fir[i];
	}
	dis[s] = 0;
	std::queue<int> q;
	for (q.push(s); ! q.empty(); ) {
		int u = q.front();
		q.pop();
		for (int i = fir[u]; i; i = nxt[i]) {
			int v = ::v[i];
			if (dis[u] + 1 < dis[v] && w[i]) {
				dis[v] = dis[u] + 1, q.push(v);
			} 
		}
	}
	return dis[t] != inf;
}
ll DFS(int u, int t, ll flow = inf) {
	if (u == t) {
		return flow;
	}
	ll rest = flow;
	for (int &i = hd[u]; i; i = nxt[i]) {
		int v = ::v[i];
		if (dis[u] + 1 == dis[v] && w[i]) {
			ll k = DFS(v, t, std::min(w[i], rest));
			k == 0 && (dis[v] = inf, 0);
			rest -= k, ::w[i] -= k, ::w[i ^ 1] += k;
			if (! rest) {
				return flow;
			}
		}
	}
	return flow - rest; 
}
ll Dinic(int n, int s, int t) {
	ll ans = 0;
	for (; BFS(n, s, t); ans += DFS(s, t));
	return ans;
}
int main() {
	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= m; i++) {
		int x, y;
		ll z;
		scanf("%d%d%lld", &x, &y, &z);
		Add(x, y, z);
	}
	printf("%lld\n", Dinic(n, s, t));
	return 0;
}

