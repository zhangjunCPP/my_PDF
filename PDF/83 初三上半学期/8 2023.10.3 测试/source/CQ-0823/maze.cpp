#include <bits/stdc++.h>
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

const int N = 2e5 + 5;
int n, m, k, s[N], d[N], du[N], dis[N];
int head[N], to[N << 1], nxt[N << 1], ecnt = 1, cost[N << 1];

void add(int u, int v, int w) {
  to[++ ecnt] = v, nxt[ecnt] = head[u], head[u] = ecnt, cost[ecnt] = w;
  ++ du[u];
}

priority_queue <pii, vector <pii>, greater <pii> > q; 

int main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  n = read(), m = read(), k = read();
  rep(i, 1, k) s[i] = read();
  rep(i, 1, n) d[i] = read();
  rep(i, 1, m) {
    int u = read(), v = read(), w = read();
    add(u, v, w), add(v, u, w);
  }
  rep(i, 1, n) d[i] = min(d[i], du[i]);
  memset(dis, 0x3f3f3f3f, sizeof dis);
  int inf = dis[0];
  rep(i, 1, k) dis[s[i]] = d[s[i]] = 0, q.push(pii(0, s[i]));
  while (!q.empty()) {
    int u = q.top().second, bu = q.top().first;
    q.pop();
    if (d[u] -- != 0) continue;
    dis[u] = bu;
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
      if (dis[v] == inf) q.push(pii(dis[u] + cost[i], v));
  }
  printf("%d\n", dis[1] == inf ? -1 : dis[1]);
  return 0;
}

