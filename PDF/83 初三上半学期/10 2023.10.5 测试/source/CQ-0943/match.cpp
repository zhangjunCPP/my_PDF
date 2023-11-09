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

const int N = 1e6 + 5;
int n, m;
set <int> s[N];

int main() {
  freopen("match.in", "r", stdin);
  freopen("match.out", "w", stdout);
  int T = read();
  while (T --) {
    n = read(), m = read();
    rep(i, 1, n) s[i].clear();
    while (m --) {
      int a = read(), b = read();
      if (a ^ b) s[a].insert(b), s[b].insert(a);
    }
    int Ans(0);
    rep(i, 1, n) {
      if ((int)s[i].size() > Ans) {
        Ans = s[i].size();
        if (Ans == 2) {
          int num(0), a[3] = {};
          for (int it : s[i]) a[num ++] = it;
          if (s[a[0]].count(a[1])) Ans ++;
        }
      }
    }
    printf("%d\n", Ans);
  }
	return 0;
}

