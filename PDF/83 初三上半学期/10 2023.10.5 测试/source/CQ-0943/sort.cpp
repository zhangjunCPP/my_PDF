#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i ++)
#define dep(i, a, b) for (int i = (a); i >= (b); i --)
using namespace std;
typedef vector <int> vint;

char buf[1 << 23], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
int read() {
  int s(0), f(1); char ch(getchar());
  while (!isdigit(ch)) f = ch == '-' ? -1 : 1, ch = getchar();
  while (isdigit(ch)) s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * f;
}

const int N = 7e5 + 5;
int Ans;

void solve(vint a) {
  if (a.size() <= 1) return;
  int mid = a[(a.size() - 1) / 2];
  vint al, ar;
  for (auto it : a) {
    Ans ++;
    if (it < mid) al.push_back(it);
    if (it > mid) ar.push_back(it);
  }
  solve(al), solve(ar);
}

int main() {
  freopen("sort.in", "r", stdin);
  freopen("sort.out", "w", stdout);
  int n = read();
  vint a(n);
  rep(i, 0, n - 1) a[i] = read();
  solve(a), printf("%d\n", Ans);
	return 0;
}

