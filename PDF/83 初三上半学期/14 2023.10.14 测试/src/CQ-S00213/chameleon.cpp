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

const int N = 1e5 + 5;
int n, k, L, d[N], b[N];
vector <int> vl, vr;
double Ans[45];

int main() {
  freopen("chameleon.in", "r", stdin);
  freopen("chameleon.out", "w", stdout);
  scanf("%d%d%d", &n, &k, &L);
  rep(i, 1, n) {
    char opt;
    scanf("%d%d %c", &d[i], &b[i], &opt);
    if (opt == 'L') vl.push_back(i);
    else vr.push_back(i);
  }
  auto cmp = [&] (int x, int y) {
    return d[x] < d[y];
  };
  sort(vl.begin(), vl.end(), cmp);
  sort(vr.begin(), vr.end(), cmp);
  for (auto it : vr) Ans[b[it]] += L - d[it];
  for (auto it : vl) {
    double x = d[it];
    int las = -1;
    for (int i = 0, sz = vr.size(); i < sz; i ++) {
      if (d[vr[i]] > x) break;
      las = i;
    }
    int col = b[it], tim = 0;
    dep(i, las, 0) {
      int len = x - d[vr[i]] - tim * 2;
      tim += len / 2;
      Ans[col] += len / 2;
      if (len & 1) Ans[col] += 0.5, tim ++;
      col = (col + b[vr[i]]) % k;
      if (len & 1) Ans[col] += 0.5;
    }
    Ans[col] += x - tim;
  }
  rep(i, 0, k - 1) printf("%.1lf\n", Ans[i]);
  return 0;
}

