#include<bits/stdc++.h>
using ULL = unsigned long long;
const ULL p1 = 13331ULL, p2 = 998244853ULL;
const int maxn = 1e5 + 10;
char s[maxn];
ULL P1[maxn], H2[maxn];
ULL P2[maxn], H1[maxn];
int pre[maxn];
int main() {
	freopen("ccfc.in", "r", stdin);
	freopen("ccfc.out", "w", stdout);
	scanf("%s", s + 1);
	int n = strlen(s + 1);
    std::reverse(s + 1, s + n + 1);
	P1[0] = 1ULL;
	for (int i = 1; i <= n; i++) P1[i] = P1[i - 1] * p1;
	for (int i = 1; i <= n; i++) H1[i] = H1[i - 1] * p1 + s[i];
	P2[0] = 1ULL;
	for (int i = 1; i <= n; i++) P2[i] = P2[i - 1] * p2;
	for (int i = 1; i <= n; i++) H2[i] = H2[i - 1] * p2 + s[i];
    for (int i = 2, j = 0; i <= n; i++) {
        for (; j && s[j + 1] != s[i]; j = pre[j]);
        j += s[j + 1] == s[i], pre[i] = j;
    }
	std::function<std::pair<ULL, ULL> (int, int)> VAL = [](int l, int r) -> std::pair<ULL, ULL> {
		return {H1[r] - H1[l - 1] * P1[r - l + 1], H2[r] - H2[l - 1] * P2[r - l + 1]};
	};
	for (int i = n; i >= 1; i--) {
		int cnt = 0;
		for (int j = pre[i]; j; j = pre[j]) {
            if (j + j + j + 1 > i) continue;
			if (VAL(1, j) == VAL(i - j + 1, i) && VAL(1, j) == VAL(i - j - j + 1, i - j))
				cnt++;
        }
		printf("%d ", cnt);
	}
	return 0;
}