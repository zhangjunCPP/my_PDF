#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, K = 2.2e5 + 10;
int a[N];
int ipr[N], pr[N];
struct qc {
	int id, l, r;
};
qc o[K];
int mx[K];
long long val[K];
const long long mod = 998244353;
int mxm[30];
int main() {
	freopen("boring.in", "r", stdin);
	freopen("boring.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int len = 0;
	for (int i = 1; i <= q; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int l, r;
			scanf("%d%d", &l, &r);
			o[++len] = {i, l, r};
		}
	}
	int mxa = 0;
	for (int i = 1; i <= n; i++) {
		mxa = max(mxa, a[i]);
	}
	int m = 0;
	for (int i = 2; i <= mxa; i++) {
		if (! ipr[i]) {
			pr[++m] = i;
			for (int j = i + i; j <= mxa; j += i) {
				ipr[j] = 1;
			}
 		}
	}
	for (int i = 1; i <= q; i++) {
		val[i] = 1;
	}
	stable_sort(o + 1, o + len + 1, [](const qc& a, const qc& b) {
		return a.r < b.r;
	});
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= q; j++) {
			mx[j] = 0;
		}
		int lim = -1;
		for (long long x = 1; x <= (long long)(mxa); x *= 1ll * pr[i], lim++);
		for (int j = 0; j <= lim; j++) {
			mxm[j] = 0;
		}
		for (int pos = 1, j = 1; j <= len; j++) {
			for (; pos <= o[j].r; pos++) {
				int cnt = 0;
				for (; a[pos] % pr[i] == 0; a[pos] /= pr[i], cnt++);
				mxm[cnt] = pos;
			}
			int v = 0;
			for (int k = 0; k <= lim; k++) {
				if (mxm[k] >= o[j].l) {
					v = k;
				}
			}
			mx[o[j].id] = max(mx[o[j].id], v);
		}
		for (int j = 1; j <= q; j++) {
			for (int k = 1; k <= mx[j]; k++) {
				val[j] = (val[j] * 1ll * pr[i]) % mod;
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		printf("%lld\n", val[i]);
	}
	return 0;	
} 
