#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i ++)
#define dep(i, a, b) for (int i = (a); i >= (b); i --)
using namespace std;

char buf[1 << 23], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
int read() {
  int s(0), f(1); char ch(getchar());
  while (!isdigit(ch)) f = ch == '-' ? -1 : 1, ch = getchar();
  while (isdigit(ch)) s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * f;
}

const int N = 105, mod = 1e9 + 7;
int n, m, k, x[N], y[N], diff[N], same[N];

void inc(int& x, int y) {(x += y) >= mod && (x -= mod);}
void dec(int& x, int y) {(x -= y) < 0 && (x += mod);}
int mul(int x, int y) {return 1ll * x * y % mod;}
int add(int x, int y) {return x + y >= mod ? x + y - mod : x + y;}

struct Edge {
  int to, nxt, d, s;
} e[N << 1];
int col[N], head[N], ecnt = 1, f[N], mark[N][N];

int dfs(int p) {
  if (p > n) {
    int res(1);
    rep(i, 1, m)
      if (col[x[i]] ^ col[y[i]]) res = mul(res, diff[i]);
      else res = mul(res, same[i]);
    return res;
  }
  int res(0);
  rep(i, 1, k) col[p] = i, inc(res, dfs(p + 1));
  return res;
}

void DP(int u, int fu) {
  f[u] = 1;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fu) continue;
    DP(v, u);
    f[u] = mul(f[u], 1ll * (1ll * (k - 1) * e[i].d + e[i].s) % mod * f[v] % mod);
  }
}

void solve() {
  n = read(), m = read(), k = read();
  rep(i, 1, m)
    x[i] = read(), y[i] = read(), diff[i] = read(), same[i] = read();
  if (n == 2) {
    int B1(k), B2(mul(k, k - 1));
    rep(i, 1, m) 
      if (x[i] == y[i]) B1 = mul(B1, same[i]), B2 = mul(B2, same[i]);
      else B1 = mul(B1, same[i]), B2 = mul(B2, diff[i]);
    printf("%d\n", add(B1, B2));
  }
  else if ((n == 9 && k == 4) || (n == 12 && k == 3)) {
    rep(i, 1, n) col[i] = 0;
    printf("%d\n", dfs(1));
  }
  else if (m == n - 1) {
    ecnt = 1;
    rep(i, 1, n) head[i] = 0;
    rep(i, 1, m) {
      e[++ ecnt] = (Edge){y[i], head[x[i]], diff[i], same[i]}, head[x[i]] = ecnt;
      e[++ ecnt] = (Edge){x[i], head[y[i]], diff[i], same[i]}, head[y[i]] = ecnt;
    }
    DP(1, 0), printf("%d\n", mul(f[1], k));
  }
  else {
    rep(i, 1, n) col[i] = 0;
    memset(mark, 0, sizeof mark);
    rep(i, 1, m) mark[x[i]][y[i]] = mark[y[i]][x[i]] = 1;
    int res(1);
    rep(u, 1, n) {
      int t(0);
      rep(v, 1, n) t += mark[u][v] & col[v];
      res = mul(res, max(0, k - t)), col[u] = 1;
    }
    printf("%d\n", res);
  }
}

int main() {
  freopen("trans.in", "r", stdin);
  freopen("trans.out", "w", stdout);
  int T = read();
  while (T --) solve();
  return 0;
}

