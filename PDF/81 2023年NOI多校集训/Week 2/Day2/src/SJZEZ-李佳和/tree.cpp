#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

#define int long long

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int n, ans, col[N], dep[N], maxd, cnt;
int h[N], ne[N << 1], e[N << 1], idx;
int fac[N], inv[N];
int din[N], f[N][25];

int qmi(int b, int k) {
	int res = 1;
	while(k) {
		if(k & 1) res = res * b % mod;
		b = b * b % mod;
		k >>= 1;
	}
	return res;
}

int C(int n, int m) {
	if(n < m || m < 0) return 0;
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void add(int a, int b) {
	ne[idx] = h[a], e[idx] = b, h[a] = idx ++;
	din[b] ++;
}

void solve1() {
	ans = 2;
	for(int i = 2, p = 8; i <= n - 1; ++ i) {
		int tmp = (ans * 2 % mod + p) % mod;
		if(i % 2) tmp -= 2;
		ans = tmp, p = p * 2 % mod;
	}
	cout << ans << endl;
}

void dfs2(int u, int fa) {
	dep[u] = dep[fa] + 1, f[u][0] = fa;
	for(int i = 1; i <= 20; ++ i) {
		f[u][i] = f[f[u][i - 1]][i - 1];
	}
	for(int i = h[u]; ~i; i = ne[i]) {
		int j = e[i];
		if(j == fa) continue;
		dfs2(j, u);
	}
}

int LCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 20; ~i; -- i) {
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
	}
	if(x == y) return x;
	for(int i = 20; ~i; -- i) {
		if(f[x][i] != f[y][i]) {
			x = f[x][i], y = f[y][i];
		}
	}
	return f[x][0];
}

void solve() {
	maxd = 0;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			if(col[i] == col[j]) {
				int l = LCA(i, j);
				maxd = max(maxd, dep[i] + dep[j] - 2 * dep[l]);
			}
		}
	}
	ans += maxd;
}

void dfs1(int u, int fa) {
	dep[u] = dep[fa] + 1;
	if(maxd == dep[u]) cnt ++;
	if(maxd < dep[u]) {
		maxd = dep[u];
		cnt = 1;
	}
	for(int i = h[u]; ~i; i = ne[i]) {
		int j = e[i];
		if(j == fa) continue;
		dfs1(j, u);
	}
}

void dfs(int id) {
	if(id > n) {
		solve();
		return ;
	}
	col[id] = 0;
	dfs(id + 1);
	col[id] = 1;
	dfs(id + 1);
}

signed main() {
	
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout); 
	
	memset(h, -1, sizeof h);
	
	fac[0] = inv[0] = 1;
	
	for(int i = 1; i < N; ++ i) fac[i] = fac[i - 1] * i % mod;
	
	inv[N - 1] = qmi(fac[N - 1], mod - 2);
	
	for(int i = N - 2; i; -- i) inv[i] = inv[i + 1] * (i + 1) % mod;
	
	cin >> n;
	
	bool flag = true;
	
	for(int i = 1; i <= n - 1; ++ i) {
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
		if(a != i || b != i + 1) flag = false;
	}
	
	if(flag) solve1();
	else if(din[1] == n - 1) {
		if(n <= 3) solve1();
		else cout << qmi(2, n + 1) << endl;
	} else if(n <= 10) {
		dfs2(1, 0);
		dfs(1);
		cout << ans << endl;
	} else {
		dfs1(1, 0);
		if(cnt <= 2) solve1();
		else cout << qmi(2, n + 1) * maxd % mod << endl;
	}
	
	return 0;
} 
