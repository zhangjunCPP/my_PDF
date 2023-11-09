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

const int N = 1005;
int f[N * N];

int main() {
  freopen("count.in", "r", stdin);
  freopen("count.out", "w", stdout);
  int T = read();
  while (T --) {
    int n = read(), Ans(0);
    rep(i, 1, n) rep(j, 1, n) f[i * j] ++;
    rep(i, 1, n * n) Ans += f[i] * f[i];
    printf("%d\n", Ans);
    rep(i, 1, n) rep(j, 1, n) f[i * j] --;
  }
	return 0;
}

