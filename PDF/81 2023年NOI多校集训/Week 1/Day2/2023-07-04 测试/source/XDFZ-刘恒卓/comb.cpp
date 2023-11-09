// lhzawa(https://www.cnblogs.com/lhzawa/)
#include<bits/stdc++.h>
using namespace std;
const int _N = 3e3 + 10;
int h[_N][_N];
int vis[_N];
vector<int> vc[_N]; 
const int N = 1e5 + 10, M = 1e2 + 10;
int a[N], b[N], cnt[N], t[N], lst[N];
int belong[N];
vector<int> v[M];
int f[N];
int main() {
	freopen("comb.in", "r", stdin);
	freopen("comb.out", "w", stdout);
	int n;
	scanf("%d", &n);
	if (n <= 3000) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				h[i][j] += h[i - 1][j];
			}
			scanf("%d", &a[i]);
			h[i][a[i]]++;
		}
		for (int i = 1; i <= n; i++) {
			f[i] = f[i - 1];
			for (int i = 1; i <= n; i++){
				vis[i] = 0;
			} 
			for (int j = i - 1; j; j--) {
				if (! vis[a[j]]) {
					int c = a[j];
					vis[c] = 1;
					for (int k = 0; k < (int)(vc[c].size()) - 1; k++) {
						if (h[j - 1][a[i]] - h[vc[c][k]][a[i]] > 0) {
							f[i] = max(f[i], f[vc[c][k] - 1] + 4);
						}
					}
				}
			}
			vc[a[i]].push_back(i);
		}
		printf("%d", f[n]);
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		cnt[b[i]]++;
	}
	int _n = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[b[i]] == 2) {
			a[++_n] = b[i];
			t[a[_n]] ? lst[_n] = t[a[_n]] : t[a[_n]] = _n;
		}
	}
	n = _n;
	if (! n) {
		printf("0");
		return 0;
	}
	int sr = sqrt(n);
	for (int i = 1; i <= n; i++) {
		belong[i] = (i - 1) / sr + 1;
	}
	int al = belong[n];
	for (int i = 1; i <= n; i++) {
		if (lst[i]) {
			v[belong[i]].push_back(lst[i]);
		}
	}
	for (int i = 1; i <= al; i++) {
		v[i].push_back(-1), v[i].push_back(n + 1);
		sort(v[i].begin(), v[i].end());
	}
	function<int (int, int, int)> query = [&sr](int l, int r, int w) -> int {
		if (l > r) {
			return -1;
		} 
		if (belong[l] == belong[r]) {
			int ans = -1;
			for (int i = l; i <= r; i++) {
				if (lst[i] && lst[i] < w) {
					ans = max(ans, lst[i]);
				}
			}
			return ans;
		}
		int ans = -1;
		for (int i = l; i <= sr * belong[l]; i++) {
			if (lst[i] && lst[i] < w) {
				ans = max(ans, lst[i]);
			}
		}
		for (int i = sr * (belong[r] - 1) + 1; i <= r; i++) {
			if (lst[i] && lst[i] < w) {
				ans = max(ans, lst[i]);
			}
		}
		for (int i = belong[l] + 1; i <= belong[r] - 1; i++) {
			ans = max(ans, v[i][lower_bound(v[i].begin(), v[i].end(), w) - v[i].begin() - 1]);
		}
		return ans;
	};
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		if (lst[i]) {
			int p = query(lst[i] + 1, i - 1, lst[i]);
			if (p != -1) {
				f[i] = max(f[i], f[p - 1] + 4);
			}		
		}
	}
	printf("%d\n", f[n]);
	return 0;
}
