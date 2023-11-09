# include <bits/stdc++.h>

using namespace std;

namespace kh {
  auto& cin(std::cin);
  auto& cout(std::cout);
  template <typename T>
    constexpr T& cmin(T& a, T const& b)
    { return a = ::std::min(a, b); }
  template <typename T>
    constexpr T& cmax(T& a, T const& b)
    { return a = ::std::max(a, b); }
  constexpr int N(1'000'005);
  int n, m;
  vector<int> adj[N];
  int ans;
  void main() {
    cin >> n >> m;
    for (int i(1); i <= m; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for (int i(1); i <= n; ++i)
      cmax(ans, int(adj[i].size()));
    if (ans < 3)
      for (int i(1); i <= n; ++i)
        for (int const j : adj[i]) for (int const k : adj[i])
          if (j != k && find(adj[j].begin(), adj[j].end(), k) != adj[j].end())
            ans = max(ans, 3);
    cout << ans << '\n', ans = 0;
    fill(adj + 1, adj + n + 1, vector<int>());
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  kh::cin.tie(nullptr);
  int t((kh::cin >> t, t));
  for (int i(1); i <= t; ++i) kh::main();
}
