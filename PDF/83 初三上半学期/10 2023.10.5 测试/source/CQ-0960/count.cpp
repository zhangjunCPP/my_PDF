#include <bits/stdc++.h> 


using namespace std;
// 有可能是直接推狮子？？？ 
typedef long long ll;
int T, n;
int app[1000005];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			app[i * j]++;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n * n; i++) {
		ans += (ll)app[i] * app[i];
		app[i] = 0;
	}
	printf("%lld\n", ans);
}
int main() {
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
