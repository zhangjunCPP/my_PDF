#include<bits/stdc++.h>
using namespace std;
const int N = 15, M = 3e2 + 10;
int u[M], v[M];
int fa[N + 5], d[N + 5];
int mxs[1 << N];
long long val[1 << N];
int main() {
	freopen("subgraph.in", "r", stdin);
	freopen("subgraph.out", "w", stdout);
	int n, m;
	long long X, Y, Z;
	scanf("%d%d%lld%lld%lld", &n, &m, &X, &Y, &Z);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u[i], &v[i]);
	}
	for (int s = 1; s < (1 << n); s++) {
		for (int i = 1; i <= n; i++) {
			d[i] = 0, fa[i] = i;
		}
		function<int (int)> getfa = [&getfa](int u) -> int {
			return fa[u] == u ? u : (fa[u] = getfa(fa[u]));
		};
		function<void (int, int)> merge = [&getfa](int u, int v) -> void {
			u = getfa(u), v = getfa(v);
			if (u == v) {
				return ;
			}
			fa[u] = v;
			return ;
		};
		for (int i = 1; i <= m; i++) {
			if (((s >> (u[i] - 1)) & 1) == 1 && ((s >> (v[i] - 1)) & 1) == 1) {
				val[s] += X, merge(u[i], v[i]), d[u[i]]++, d[v[i]]++;
			}
			if (((s >> (u[i] - 1)) & 1) == 1 && ((s >> (v[i] - 1)) & 1) == 0) {
				val[s] += Z;
			}
			if (((s >> (u[i] - 1)) & 1) == 0 && ((s >> (v[i] - 1)) & 1) == 1) {
				val[s] += Z;
			}
		}
		int mx = 0x3f3f3f, f = -1;
		for (int i = 1; i <= n; i++) {
			if ((s >> (i - 1)) & 1) {
				val[s] -= Y, mx = min(mx, d[i]);
				if (f == -1) {
					f = getfa(i);
				}
				else if (getfa(i) != f) {
					f = 0;
				}
			}
		}
		if ((! f) || (! mx)) {
			continue;
		}
		mxs[s] = mx;
		for (int t = s & (s - 1); t; t = (t - 1) & s) {
			if (mx >= mxs[t]) {
				mxs[t] = 0;
			}
		}
	}
	long long mxval = LLONG_MIN;
	int mxk = 0;
	for (int s = 0; s < (1 << n); s++) {
		if (mxs[s]) {
			if (val[s] > mxval) {
				mxval = val[s], mxk = 0;
			} 
			if (val[s] == mxval) {
				mxk = max(mxk, mxs[s]);
			}
		}
	}
	printf("%d %lld", mxk, mxval);
	return 0;
}
