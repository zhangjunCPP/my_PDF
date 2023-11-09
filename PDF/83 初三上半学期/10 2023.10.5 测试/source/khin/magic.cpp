# include <bits/stdc++.h>

using namespace std;

namespace kh {
  template <typename T>
    constexpr T& cmin(T& a, T const& b)
    { return a = ::std::min(a, b); }
  template <typename T>
    constexpr T& cmax(T& a, T const& b)
    { return a = ::std::max(a, b); }
  constexpr int N(1'005);
  constexpr int fc[]{ 1, 1, 2, 6, 24, 120, 720, 5'040, 40'320 };
  int n, l[N], r[N], c[N];
  int pp[fc[8]][8], qq[fc[8]], ss[fc[8]], tt[fc[8]], pr[fc[8]];
  long f[N][fc[7]];
  inline int val(int const s, int const t) {
    if (!(1 <= s && s <= n)) return 0;
    if (!(1 <= t && t <= n)) return 0;
    return l[s] <= t && t <= r[s] ? c[s] : 0;
  }
  inline int enc(int const (&p)[7]) {
    int res(0);
    for (int j(0); j != 7; ++j)
      for (int k(j); k != 7; ++k)
        if (p[k] < p[j]) res += fc[6 - j];
    return res;
  }
  inline int enc(int const (&p)[8]) {
    int res(0);
    for (int j(0); j != 8; ++j)
      for (int k(j); k != 8; ++k)
        if (p[k] < p[j]) res += fc[7 - j];
    return res;
  }
  void main() {
    cin >> n;
    for (int i(1); i <= n; ++i) cin >> l[i] >> r[i] >> c[i];
    int p[]{ 0, 1, 2, 3, 4, 5, 6, 7 };
    for (int i(0); i != fc[8]; ++i) {
      int s[7], t[7], x(0), y(0);
      for (int j(0); j != 8; ++j) {
        if (p[j] != 0) s[x++] = p[j] - 1;
        if (p[j] != 7) t[y++] = p[j] - 0;
      }
      memcpy(pp[i], p, sizeof p);
      qq[i] = find(p, p + 8, 0) - p;
      ss[i] = enc(s), tt[i] = enc(t);
      while (pr[i] != 8 && p[pr[i]] == 7 - pr[i]) ++pr[i];
      next_permutation(p, p + 8);
    }
    for (int i(1); i <= n; ++i)
      for (int j(0); j != fc[8]; ++j) {
        if (pr[j] < 8 - i) continue;
        long v(0);
        for (int k(0); k != qq[j]; ++k) v += val(i - pp[j][k], i);
        for (int k(7); k != qq[j]; --k) v += val(i, i - pp[j][k]);
        cmax(f[i][tt[j]], f[i - 1][ss[j]] + v);
      }
    cout << *max_element(f[n], f[n] + fc[7]) << endl;
  }
}

int main() { 
freopen("magic.in","r",stdin);
freopen("magic.out","w",stdout);
kh::main(); }
