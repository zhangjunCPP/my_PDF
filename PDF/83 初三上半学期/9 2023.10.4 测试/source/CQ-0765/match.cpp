#include<bits/stdc++.h>
using ULL = unsigned long long;
const ULL p = 998244853;
const int maxn = 2e5 + 10;
ULL H[maxn], P[maxn];
char s[maxn], _t[maxn];
std::basic_string<char> t[maxn];
int len[maxn];
ULL _H[maxn];
int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	int k;
	scanf("%d%s", &k, s + 1);
	int n = strlen(s + 1);
	P[0] = 1;
	for (int i = 1; i <= n; i++) H[i] = H[i - 1] * p + s[i], P[i] = P[i - 1] * p;
	std::function<ULL (int, int)> VAL = [&](int l, int r) -> ULL {
		return H[r] - H[l - 1] * P[r - l + 1];
	};
	std::function<ULL (int, int)> _VAL = [&](int l, int r) -> ULL {
		return _H[r] - _H[l - 1] * P[r - l + 1];
	};
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		scanf("%s", _t + 1);
		len[i] = strlen(_t + 1);
		t[i] += ' ';
		for (int j = 1; j <= len[i]; j++) t[i] += _t[j];
	}
	for (int i = 1; i <= q; i++) {
		if (len[i] <= k) {printf("%d\n", n); continue;}
		if (len[i] > n) {printf("0\n"); continue;}
		for (int j = 1; j <= len[i]; j++) _H[j] = _H[j - 1] * p + t[i][j];
		int cnt = 0;
		for (int l = 1, r = len[i]; r <= n; l++, r++) {
			if (VAL(l, r) == _VAL(1, len[i])) {cnt++; continue;}
			int L = 1, R = len[i], totl = -1;
			for (; L <= R; ) {
				int mid = (L + R) >> 1;
				if (VAL(l, l + mid - 1) == _VAL(1, mid)) L = mid + 1;
				else totl = mid, R = mid - 1;
			}
			L = 1, R = len[i];
			int totr = -1;
			for (; L <= R; ) {
				int mid = (L + R) >> 1;
				if (VAL(l + mid - 1, r) == _VAL(mid, len[i])) R = mid - 1;
				else totr = mid, L = mid + 1;
			}
			cnt += totr - totl < k;
		}
		printf("%d\n", cnt);
	}
	return 0;
}