#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i <= (b); i ++)
#define dep(i, a, b) for (int i = (a); i >= (b); i --)
using namespace std;
typedef pair <int, int> pii;

char buf[1 << 23], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
int read() {
  int s(0), f(1); char ch(getchar());
  while (!isdigit(ch)) f = ch == '-' ? -1 : 1, ch = getchar();
  while (isdigit(ch)) s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * f;
}

const int N = 2e5 + 5, mod = 998244353, P = mod - 1;
int n, Q, V, a[N], mark[N], pri[N], tot;
int cnt[20][N], Ans[N], pw[N];
pii q[N];

int ksm(int a, int b) {
  int s(1);
  for (; b > 0; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) s = 1ll * s * a % mod;
  return s;
}

int main() {
  freopen("ddickky.in", "r", stdin);
  freopen("ddickky.out", "w", stdout);
  n = read(), Q = read(), pw[0] = 1;
  rep(i, 1, n) a[i] = read(), V = max(V, a[i]), pw[i] = (pw[i - 1] << 1) % P;
  rep(i, 1, Q) q[i].fi = read(), q[i].se = read(), Ans[i] = 1;
  rep(i, 2, V) {
    if (!mark[i]) pri[++ tot] = i;
    rep(j, 1, tot) {
      if (pri[j] * i > V) break;
      mark[pri[j] * i] = 1;
      if (i % pri[j] == 0) break;
    }
  }
  rep(_, 1, tot) {
    int p = pri[_], mx(0);
    for (int i = V; i > 1; i /= p) mx ++;
    rep(i, 1, n) {
      rep(j, 0, mx) cnt[j][i] = cnt[j][i - 1];
      int num(0);
      for (int t = a[i]; t % p == 0; t /= p) num ++;
      cnt[num][i] ++;
    }
    rep(i, 1, Q) {
      int L = q[i].fi, R = q[i].se, sum(0), pre(0);
      rep(j, 0, mx) {
        int val = cnt[j][R] - cnt[j][L - 1];
        pre += val;
        sum += 1ll * j * (pw[val] - 1 + P) % P * pw[R - L + 1 - pre] % P;
        if (sum >= P) sum -= P;
      }
      Ans[i] = 1ll * Ans[i] * ksm(p, sum) % mod;
    }
  }
  rep(i, 1, Q) printf("%d\n", Ans[i]);
  return 0;
}

