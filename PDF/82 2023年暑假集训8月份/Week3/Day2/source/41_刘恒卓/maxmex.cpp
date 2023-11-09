#include<bits/stdc++.h>
const int N = 1e5 + 10;
int n;
int a[N];
int cnt[N], tot;
void Insert(int w, int x) {
	tot -= (x < w && cnt[x] == 0), cnt[x]++;
}
void Delete(int w, int x) {
	cnt[x]--, tot += (x < w && cnt[x] == 0);
}
bool check(int w, int len) {
	tot = w;
	for (int i = 1; i < len; i++) {
		Insert(w, a[i]);
	}
	bool flg = 0;
	for (int i = len; i <= n; i++) {
		Insert(w, a[i]), i > len && (Delete(w, a[i - len]), 1);
		flg |= tot == 0;	
	}
	for (int i = n - len + 1; i <= n; i++) {
		Delete(w, a[i]);
	}
	return flg;
}
int ans_mx[N];
int main() {
	freopen("maxmex.in", "r", stdin);
	freopen("maxmex.out", "w", stdout);
	scanf("%d", &n);
	int mx = -1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		mx = std::max(mx, a[i] + 1);
	}
	int q;
	scanf("%d", &q);
	if (mx <= 110) {
		memset(ans_mx, -0x3f, sizeof(ans_mx));
		ans_mx[0] = 0;
		for (int i = 1; i <= mx; i++) {
			int l = i, r = n, v = n + 1;
			for (int mid; l <= r; ) {
				mid = (l + r) >> 1;
				if (check(i, mid)) {
					v = mid, r = mid - 1;
				} else {
					l = mid + 1;
				}
			}
			ans_mx[v] = i;
		}
		for (int i = 1; i <= n; i++) {
			ans_mx[i] = std::max(ans_mx[i - 1], ans_mx[i]);
		}
		for (int i = 1, x; i <= q; i++) {
			scanf("%d", &x);
			printf("%d\n", ans_mx[x]);
		}
		return 0;
	}
	for (int x; q; q--) {
		scanf("%d", &x);
		int l = 1, r = x, ans = 0;
		for (int mid; l <= r; ) {
			mid = (l + r) >> 1;
			if (check(mid, x)) {
			ans = mid, l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		printf("%d\n", ans);
	} 
	return 0;
}

