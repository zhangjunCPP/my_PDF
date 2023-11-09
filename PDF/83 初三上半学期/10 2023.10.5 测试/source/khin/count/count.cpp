# include <bits/stdc++.h>

using namespace std;

namespace kh {
  auto& cin(std::cin);
  auto& cout(std::cout);
  inline void writeln(__int128_t x) {
    static char stk[CHAR_BIT * sizeof(x)], *top(stk);
    while (*top++ = x % 10 + '0', x /= 10);
    while (cout.put(*--top), top != stk);
    cout.put('\n');
  }
  constexpr long N(100'000'000'005);
  constexpr int A(pow(N, 2.0 / 3.0));
  bool isprime[A + 1];
  int prime[A + 1], pi;
  int phi[A + 1];
  long sfi[A + 1];
  int lpf[A + 1];
  int exp[A + 1];
  int pow[A + 1];
  long cnv[A + 1];
  long n;
  __int128_t mem[N / A + 1];
  __int128_t ans;
  void init() {
    static bool once;
    if (once) return;
    else once = true;
    fill(isprime + 2, isprime + A + 1, true);
    phi[1] = 1, lpf[1] = 1, exp[1] = 0, pow[1] = 1, cnv[1] = 1;
    for (int i(2); i <= A; ++i) {
      if (isprime[i]) {
        prime[pi++] = i, phi[i] = i - 1;
        lpf[i] = i, exp[i] = 1, pow[i] = i;
        cnv[i] = 2 * i - 1;
      }
      for (int const p : prime) {
        if (i * p > A) break;
        isprime[i * p] = false;
        phi[i * p] = phi[i] * (p - bool(i % p));
        lpf[i * p] = min(lpf[i], p);
        exp[i * p] = p >= lpf[i] ? exp[i] : 0;
        pow[i * p] = p >= lpf[i] ? pow[i] : 1;
        exp[i * p] += p <= lpf[i] ? 1 : 0;
        pow[i * p] *= p <= lpf[i] ? p : 1;
        cnv[i * p] = (exp[i * p] + 1) * pow[i * p];
        cnv[i * p] -= exp[i * p] * (pow[i * p] / lpf[i * p]);
        cnv[i * p] *= cnv[i * p / pow[i * p]];
        if (!(i % p)) break;
      }
    }
    for (int i(1); i <= A; ++i) sfi[i] = sfi[i - 1] + phi[i];
    for (int i(1); i <= A; ++i) cnv[i] = cnv[i - 1] + (2 * cnv[i] - i);
  }
  __int128_t sumphi(long const x) {
    if (x <= A) return sfi[x];
    if (mem[n / x]) return mem[n / x];
    auto& res(mem[n / x]);
    res = __int128_t(x) * (x + 1) / 2;
    for (long i(2); i <= x; i = x / (x / i) + 1)
      res -= (x / (x / i) - i + 1) * sumphi(x / i);
    return res;
  }
  void main() {
    init(), cin >> n;
    if (n <= A) ans = cnv[n];
    else for (long i(1); i <= n; i = n / (n / i) + 1)
      ans += __int128_t(n / i) * (n / i) * (sumphi(n / (n / i)) - sumphi(i - 1));
    writeln(ans = 2 * ans - __int128_t(n) * n), ans = 0;
    if (n > A) memset(mem, 0, sizeof mem);
  }
}

int main() {
  int t((kh::cin >> t, t));
  for (int i(1); i <= t; ++i) kh::main();
}
