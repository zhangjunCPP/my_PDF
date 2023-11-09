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

const int N = 1e5 + 5, B = 1145141, mod = 1e9 + 9;
char s[N];
int pw[N], hah[N], Ans[N];

int geth(int l, int r) {
  return (hah[r] - 1ll * hah[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}

int main() {
  freopen("ccfc.in", "r", stdin);
  freopen("ccfc.out", "w", stdout);
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  pw[0] = 1;
  rep(i, 1, n) pw[i] = 1ll * pw[i - 1] * B % mod;
  dep(i, n, 1) {
    int t = n - i + 1;
    hah[i] = s[i] - 'a' + 1;
    rep(j, i + 1, n) hah[j] = (1ll * hah[j - 1] * B + s[j] - 'a' + 1) % mod;
    rep(l, 1, (t - 1) / 3) {
      int val = geth(i, i + l - 1);
      if (geth(i + l, i + 2 * l - 1) == val && geth(n - l + 1, n) == val) Ans[i] ++;
    }
  }
  rep(i, 1, n) printf("%d ", Ans[i]);
  return 0;
}

