#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i ++)
#define dep(i, a, b) for (int i = (a); i >= (b); i --)
using namespace std;

const int N = 2e5 + 5, B = 1145141, mod = 1e9 + 9;
char s[N], t[N];
int n, m, lim, T, hah[N], pw[N];
int tmp[N];

int geth(int* hah, int l, int r) {
  if (l > r) return 0;
  return (hah[r] - 1ll * hah[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}

int main() {
  freopen("match.in", "r", stdin);
  freopen("match.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> lim >> (s + 1) >> T, n = strlen(s + 1);
  pw[0] = 1;
  rep(i, 1, N - 5) pw[i] = 1ll * pw[i - 1] * B % mod;
  rep(i, 1, n) hah[i] = (1ll * hah[i - 1] * B + s[i] - 'a' + 1) % mod;
  while (T --) {
    cin >> (t + 1), m = strlen(t + 1);
    if (m < lim) {
      cout << n - m + 1 << '\n';
      continue;
    }
    rep(i, 1, m) tmp[i] = (1ll * tmp[i - 1] * B + t[i] - 'a' + 1) % mod;
    int Ans(0);
    rep(i, 1, n - m + 1) {
      int L = i, R = i + m - 1;
      int l = 1, r = m, lcp1(0), lcp2(0);
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (geth(hah, L, L + mid - 1) == geth(tmp, 1, mid))
          lcp1 = mid, l = mid + 1;
        else r = mid - 1;
      }
      l = 1, r = m;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (geth(hah, R - mid + 1, R) == geth(tmp, m - mid + 1, m))
          lcp2 = mid, l = mid + 1;
        else r = mid - 1;
      }
      Ans += (lcp1 + lcp2 + lim >= m); 
    }
    cout << Ans << '\n';
  }
  return 0;
}

