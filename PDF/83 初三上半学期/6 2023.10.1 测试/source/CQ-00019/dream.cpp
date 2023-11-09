#include<bits/stdc++.h>
template<typename T>
void read(T &x) {
	x = 0;
	char c = getchar();
	for (; ! isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
}
using LL = long long;
const LL mod = 1000000007;
const int maxn = 1e5 + 10;
int n, m, k;
LL dis[maxn], cnt[maxn];
bool vis[maxn];
std::vector<std::pair<int, LL> > G[maxn];
int deg[maxn];
LL ccnt[maxn];
void solve() {
	int st, ed;
	read(st), read(ed);
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	dis[st] = 0, cnt[st] = 1;
	std::priority_queue<std::pair<LL, int> > q;
	q.emplace(-dis[st], st);
	for (; ! q.empty(); ) {
		int u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (std::pair<int, LL> i : G[u]) {
			int v = i.first;
			LL w = i.second;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w, cnt[v] = 0;
				q.emplace(-dis[v], v);
			}
			if (dis[u] + w == dis[v])
				cnt[v] = (cnt[v] + cnt[u]) % mod;
		}
	}
//	for (int i = 1; i <= n; i++)
//		printf("%lld ", cnt[i]);
//	printf("\n");
	if (! k) {
		printf("%lld\n", cnt[ed]);
		return ;
	}
	memset(vis, 0, sizeof(vis));
	memset(deg, 0, sizeof(deg));
	q.emplace(dis[ed], ed);
	for (; ! q.empty(); ) {
		int u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (std::pair<int, LL> i : G[u]) {
			int v = i.first;
			LL w = i.second;
			if (dis[v] + w == dis[u])
				q.emplace(dis[v], v), deg[v]++;
		}
	}
	memset(ccnt, 0, sizeof(ccnt));
	for (int i = 1; i <= n; i++)
		if (vis[i] && i != ed && int(G[i].size()) > 1)
			for (std::pair<int, LL> j : G[i]) {
				int v = j.first;
				LL w = j.second;
				if (deg[i] > 1 || ! vis[v] || dis[i] + w > dis[v])
					ccnt[v] = (ccnt[v] + cnt[i]) % mod;
			}
//	for (int i = 1; i <= n; i++)
//		printf("%lld ", ccnt[i]);
//	printf("\n");
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	dis[ed] = 0, cnt[ed] = 1;
	q.emplace(-dis[ed], ed);
	for (; ! q.empty(); ) {
		int u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (std::pair<int, LL> i : G[u]) {
			int v = i.first;
			LL w = i.second;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w, cnt[v] = 0;
				q.emplace(-dis[v], v);
			}
			if (dis[u] + w == dis[v])
				cnt[v] = (cnt[v] + cnt[u]) % mod;
		}
	}
//	for (int i = 1; i <= n; i++)
//		printf("%lld ", cnt[i]);
//	printf("\n");
	LL ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + cnt[i] * ccnt[i] % mod) % mod;
	printf("%lld\n", ans);
}
int main() {
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
	int q, id;
	read(n), read(m), read(q), read(k), read(id);
	for (int i = 1; i <= m; i++) {
		int u, v;
		LL w;
		read(u), read(v), read(w);
		G[u].emplace_back(v, w), G[v].emplace_back(u, w);
	}
	for (; q; q--)
		solve();
	return 0;
}
