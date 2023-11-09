#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct node {
	int v, i;
};
int t, n, m, flag;
int d[N], vis[N];
vector <int> DF;
vector <node> G[N];

void dfs (int u, int fa, int ye) {
	for (auto &v : G[u])
		if (ye == -1)
			dfs (v.v, u, fa);
		else
			if (v.v == ye) {
				++vis[v.i], flag = max (flag, vis[v.i]);
//		printf ("%d %d %d %d %d\n", u, fa, ye, vis[v.i], v.i);
			}
				
	return;
}
void DFS (int u, int fa, int ye) {
	for (auto &v : G[u])
		if (ye == -1)
			DFS (v.v, u, fa);
		else
			if (v.v == ye)
				vis[v.i] = 0;
	return;
}

int main () {
	freopen ("match.in", "r", stdin);
	freopen ("match.out", "w", stdout);
	scanf ("%d", &t); 
	while (t--) {
		scanf ("%d %d", &n, &m);
		for (int i = 1, u, v; i <= m; ++i) {
			scanf ("%d %d", &u, &v);
			++d[u];
			++d[v];
			G[u].push_back ({v, i});
			G[v].push_back ({u, i});
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			ans = max (ans, d[i]);
		if (ans != 1 && ans != 0) {
			for (int i = 1; i <= n; ++i) {
				flag = 0;
				dfs (i, -1, -1);
				if (d[i] + flag > ans)
					ans = d[i] + flag;
				DFS (i, -1, -1);
			}
		}
		printf ("%d\n", ans);
		for (int i = 1; i <= n; ++i) {
			d[i] = vis[i] = 0;
			G[i].clear ();
		}
		DF.clear ();
	}
	return 0;
} 
/*
对于一个皮配
最多只有一个端点连接边数>1（因为无重边自环）
所以直接取边数最多的端点的边数 
如果有三元环两条边为端点u的出边
可选一组出边都有一个相同的三元环，d[u] += 组数 
*/
