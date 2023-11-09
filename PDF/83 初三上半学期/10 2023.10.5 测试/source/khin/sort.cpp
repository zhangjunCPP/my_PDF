# include <bits/stdc++.h>

using namespace std;

namespace kh {
  constexpr int N(1'000'005);
  class segtree {
    constexpr static int V = N * (__lg(N) + 1) + 1;
    struct node { int l, r, s; };
    node v[V]; int n, r[N], p;
    void add(int& x, int l, int r, int y) {
      v[++p] = v[x], ++v[x = p].s;
      if (r - l == 1) return;
      if (y <= (l + r) / 2) add(v[x].l, l, (l + r) / 2, y);
      else                  add(v[x].r, (l + r) / 2, r, y);
    }
    int kth(int p, int q, int l, int r, int k) const {
      if (r - l == 1) return r;
      int const cl(v[v[q].l].s - v[v[p].l].s);
      if (k <= cl) return kth(v[p].l, v[q].l, l, (l + r) / 2, k);
      else return kth(v[p].r, v[q].r, (l + r) / 2, r, k - cl);
    }
    public:
    void init(int const n) { this->n = n; }
    void set(int const x, int const y)
    { add(r[x] = r[x - 1], 0, n, y); }
    int kth(int const l, int const r, int const k) const
    { return kth(this->r[l - 1], this->r[r], 0, n, k); }
  };
  int n, a[N], b[N];
  segtree seg;
  long slv(int const l, int const r) {
    if (r - l <= 0) return 0;
    int const mid(a[seg.kth(l, r, (r - l + 2) / 2)]);
    return r - l + 1 + slv(l, mid - 1) + slv(mid + 1, r);
  }
  void main() {
    cin >> n, seg.init(n);
    for (int i(1); i <= n; ++i) cin >> a[i], b[a[i]] = i;
    for (int i(1); i <= n; ++i) seg.set(i, b[i]);
    cout << slv(1, n) << endl;
  }
}

int main() { 
freopen("sort.in","r",stdin);
freopen("sort.out","w",stdout);

kh::main(); }
