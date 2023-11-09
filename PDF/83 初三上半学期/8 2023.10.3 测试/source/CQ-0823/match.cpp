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
int n, m, vis[2][N];
vector <int> p[N];

int main() {
  freopen("match.in", "r", stdin);
  freopen("match.out", "w", stdout);
  n = read(), m = read();
  rep(i, 1, n) {
    int num = read();
    while (num --) p[i].push_back(read());
    reverse(p[i].begin(), p[i].end());
  }
  if (n == 2) {
    rep(i, 1, 2) for (auto it : p[i]) vis[i - 1][it] = 1;
    dep(i, m, 1) if (vis[0][i] & vis[1][i]) {
      int ok(0);
      rep(j, i + 1, m) if (!vis[0][j] && !vis[1][j]) {
        ok = 1;
        if (vis[0][j - 1]) {
          rep(k, 1, j - 1) vis[0][k] = 0;
          vis[0][j] = 1;
        }
        else if (vis[1][j - 1]) {
          rep(k, 1, j - 1) vis[1][k] = 0;
          vis[1][j] = 1;
        }
        break;
      }
      if (!ok) {
        puts("-1");
        return 0;
      }
      break;
    }
    dep(i, m, 1) printf("%d", vis[0][i] | vis[1][i]);
  }
  else puts("-1");
  return 0;
}

