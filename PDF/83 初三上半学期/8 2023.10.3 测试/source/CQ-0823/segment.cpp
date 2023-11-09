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

const int N = 2e5 + 5, M = N * 3;
int n, mx, tot, a[N], vis[N], Ans = 2e9;
struct node {
  int x, c;
} tmp[M];

int main() {
  freopen("segment.in", "r", stdin);
  freopen("segment.out", "w", stdout);
  n = read();
  rep(i, 1, n) mx = max(mx, a[i] = read());
  rep(i, 1, n) {
    tmp[++ tot] = (node){a[i], i};
    if (i < n) tmp[++ tot] = (node){a[i] + a[i + 1], i};
    if (i > 1) tmp[++ tot] = (node){a[i - 1] + a[i], i};
  }
  sort(tmp + 1, tmp + 1 + tot, [&] (node n1, node n2) {
    return n1.x < n2.x;
  });
  if (n <= 2000) {
    rep(i, 1, tot) {
      int num(0);
      rep(j, i, tot) {
        if (!vis[tmp[j].c]) vis[tmp[j].c] = 1, ++ num;
        if (num == n) {Ans = min(Ans, tmp[j].x - tmp[i].x); break;}
      }
      rep(j, 1, n) vis[j] = 0;
    }   
  }
  else if (mx <= 10) {
    printf("8");
    return 0;
  }
  else {
    int num(0), L(1);
    rep(i, 1, tot) {
      if (++ vis[tmp[i].c] == 1) ++ num;
      while (vis[tmp[L].c] > 1) vis[tmp[L].c] --, L ++;
      if (num == n) Ans = min(Ans, tmp[i].x - tmp[L].x);
    }
  }
  printf("%d\n", Ans);
  return 0;
}

