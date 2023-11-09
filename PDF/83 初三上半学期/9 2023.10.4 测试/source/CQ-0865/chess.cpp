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

int main() {
  freopen("chess.in", "r", stdin);
  freopen("chess.out", "w", stdout);
  int p = read(), k = read();
  if (k == 1) {
    puts("1");
    rep(i, 0, p - 1) printf("%d ", i);
  }
  else if (p == 2) {
    int n = 1;
    while (k --) n = n * p;
    printf("%d\n", n * (n - 1) / 2);
    rep(i, 0, n - 1) rep(j, i + 1, n - 1)
      printf("%d %d\n", i, j);
  }
  return 0;
}

