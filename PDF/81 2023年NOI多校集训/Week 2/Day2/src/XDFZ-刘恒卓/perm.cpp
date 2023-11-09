#include<bits/stdc++.h>
using namespace std;
const int N = 16;
int p[N], q[N];
long long val[N];
int main() {
	freopen("perm.in", "r", stdin);
	freopen("perm.out", "w", stdout);
	int m;
	long long mod;
	scanf("%d%lld", &m, &mod);
	int ans = 0;
	for (int n = 1; n <= m; n++) {
		for (int i = 1; i <= n; i++) {
			p[i] = i;
		}
		memset(val, 0, sizeof(val));
		do {
			for (int i = 1; i <= n; i++) {
				q[p[i]] = i;
			}
			for (int i = 1; i <= n && p[i] <= q[i]; i++) {
				if (p[i] < q[i]) {
					val[i - 1]++;
					break;
				}
			}
		}
		while(next_permutation(p + 1, p + n + 1));
		int a = 0;
		for (int i = 0; i < n; i++) {
			a = (a + val[i]) % mod;
		}
		ans ^= a;
	}
	printf("%d\n", ans);
	return 0;
}
