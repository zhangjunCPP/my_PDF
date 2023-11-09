#include <iostream>
#include <cstdio>
using namespace std;
const int N = 5e5 + 5;
struct Edge {int now, nxt;} e[N << 1];
int head[N], cur;
void add(int u, int v) {e[++cur].now = v, e[cur].nxt = head[u], head[u] = cur;}
int a[N], lis[N], idx, mx, s;
void dfs(int u, int fa)
{
	if (u == s) return;
	int operat1, operat2;
	if (lis[idx] < a[u]) lis[++idx] = a[u], operat1 = - 1;
	else {int pos = lower_bound(lis + 1, lis + idx + 1, a[u]) - lis; operat1 = pos, operat2 = lis[pos]; lis[operat1] = a[u];}
	
	mx = max(mx, idx);
	for (int i = head[u]; i; i = e[i].nxt) {int v = e[i].now; if (v != fa) dfs(v, u);}
	
	if (operat1 == -1) idx--; else lis[operat1] = operat2;
}
int main()
{
	freopen("lis.in", "r", stdin);
	freopen("lis.out", "w", stdout);
	int n, ans = 2e9;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {int u, v; scanf("%d%d", &u, &v); add(u, v), add(v, u);}
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (s = 1; s <= n; s++)
	{
		mx = 0;
		for (int i = 1; i <= n; i++) idx = 0, dfs(i, 0);
		ans = min(ans, mx);
	}
	cout << ans;
	return 0;
}
