#include <bits/stdc++.h>
using namespace std;
int n, ans, mx, a[500010], hd[500010], e[500010][2], fa[4010][4010], f[4010][4010];
void dfs(int u, int rt){
	int i, v;
	f[rt][u] = 1;
	for(v = fa[rt][u]; v > 0; v = fa[rt][v]){
		if(a[v] < a[u]) f[rt][u] = max(f[rt][u], f[rt][v] + 1);
	}
	for(i = hd[u]; i > 0; i = e[i][0]){
		v = e[i][1];
		if(v != fa[rt][u]){
			fa[rt][v] = u; dfs(v, rt);
		}
	}
}
void dfs2(int u, int rt, int x){
	if(u == x) return;
	mx = max(mx, f[rt][u]);
	int i, v;
	for(i = hd[u]; i > 0; i = e[i][0]){
		v = e[i][1];
		if(v != fa[rt][u]) dfs2(v, rt, x);
	}
}
int main()
{
	freopen("lis.in", "r", stdin);
	freopen("lis.out", "w", stdout);
	int i, u, v;
	scanf("%d", &n); ans = n + 1;
	for(i = 1; i <= n; i++){
		hd[i] = 0;
	}
	for(i = 1; i >> 1 < n - 1; i++){
		scanf("%d%d", &u, &v);
		e[i][0] = hd[u]; e[i][1] = v; hd[u] = i;
		i++;
		e[i][0] = hd[v]; e[i][1] = u; hd[v] = i;
	}
	for(i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(i = 1; i <= n; i++){
		fa[i][i] = 0; dfs(i, i);
	}
	for(i = 1; i <= n; i++){
		mx = 0;
		for(u = 1; u <= n; u++){
			dfs2(u, u, i);
		}
		ans = min(ans, mx);
	}
	printf("%d", ans);
	return 0;
}
