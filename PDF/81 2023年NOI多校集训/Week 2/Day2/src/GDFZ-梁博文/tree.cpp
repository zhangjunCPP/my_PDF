#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e6 + 5, mod = 1e9 + 7;
struct Edge {int now, nxt;} e[N << 1];
int head[N], cur;
void add(int u, int v) {e[++cur].now = v, e[cur].nxt = head[u], head[u] = cur;}
namespace Math {
	int qpow(int x, int y)
	{
		int ans = 1;
		while (y)
		{
			if (y & 1) ans = 1ll * ans * x % mod;
			x = 1ll * x * x % mod;
			y >>= 1;
		}
		return ans;
	}
	int fac[N], infac[N];
	void init(int n)
	{
		fac[0] = infac[0] = 1; for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
		infac[n] = qpow(fac[n], mod - 2); for (int i = n - 1; i; i--) infac[i] = 1ll * infac[i + 1] * (i + 1) % mod;
	}
	int A(int n, int m) {if (n < 0 || m < 0 || n - m < 0) return 0; return 1ll * fac[n] * infac[n - m] % mod;}
	int C(int n, int m) {if (n < 0 || m < 0 || n - m < 0) return 0; return 1ll * fac[n] * infac[m] % mod * infac[n - m] % mod;}
} using namespace Math;
int n;
void solveA()
{
	int ans = 0, val = 0;
	if (n & 1) val = 4; else val = 2;
	ans = (ans + 1ll * ((n - 1) / 2) * val) % mod;
	val = val * 3ll % mod, ans = (ans + 1ll * ((n - 1) / 2 + 1) * val) % mod;
	for (int i = (n - 1) / 2 + 2; i < n - 1; i++) val = val * 4ll % mod, ans = (ans + 1ll * i * val) % mod;
	val = qpow(2, n - 1), ans = (ans + 1ll * (n - 1) * val) % mod;
	cout << ans;
}
void solveB() {cout << qpow(2, n + 1);}
int tmpu[N], tmpv[N];
int dep[N], jump[N][25];
void dfs(int u, int fa)
{
	dep[u] = dep[fa] + 1, jump[u][0] = fa;
	for (int i = 1; i <= 22; i++) jump[u][i] = jump[jump[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = e[i].nxt) {int v = e[i].now; if (v != fa) dfs(v, u);}
}
int LCA(int u, int v)
{
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 20; ~i; i--)
		if (dep[u] - dep[v] >= (1 << i))
			u = jump[u][i];
	if (u == v) return u;
	for (int i = 20; ~i; i--)
		if (jump[u][i] != jump[v][i])
			u = jump[u][i], v = jump[v][i];
	return jump[u][0];
}
int dis(int u, int v) {return dep[u] + dep[v] - 2 * dep[LCA(u, v)];}

int tmp[N];

void solve0()
{
	for (int i = 1; i < n; i++) add(tmpu[i], tmpv[i]), add(tmpv[i], tmpu[i]);
	dfs(1, 0);
	int ans = 0;
	for (int s = 0; s < (1 << n); s++)
	{
		int mx = 0;
		for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (i != j && (bool)(s & (1 << (i - 1))) == (bool)(s & (1 << (j - 1))))
						mx = max(mx, dis(i, j));
		tmp[mx]++;
		ans = (ans + mx) % mod;
	}
	cout << ans;
}
int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	bool subtaskA = true, subtaskB = true;
	scanf("%d", &n);
	if (n == 2) return puts("2"), 0;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v), tmpu[i] = u, tmpv[i] = v;
		if (u + 1 != v && u != v + 1) subtaskA = false;
		if (u != 1 && v != 1) subtaskB = false;
	}
	if (n <= 10) return solve0(), 0;
	if (subtaskA) return solveA(), 0;
	if (subtaskB) return solveB(), 0;
	solve0();
	return 0;
}
/*
8
1 2
1 3
1 4
2 5
2 6
6 8
4 7
*/
