// lhzawa(https://www.cnblogs.com/lhzawa)
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, K = 5e2 + 10;
int t[N];
int num[K], hd[K];
long long c[K];
long long f[N];
int main() {
	freopen("happy.in", "r", stdin);
	freopen("happy.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d%lld", &num[i], &c[i]);
		hd[i] = 1;
	}
	long long o;
	scanf("%lld", &o);
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1] + o;
		for (int j = 1; j <= k; j++) {
			for (; t[i] - t[hd[j]] + 1 > num[j]; hd[j]++);
			f[i] = min(f[i], f[hd[j] - 1] + c[j]);
		}
		printf("%lld\n", f[i] - f[i - 1]);
	} 
	return 0;
}
