# include <bits/stdc++.h>
# define int long long
using namespace std;

int n, mod, ans;
int jie = 1;
int pre1, pre2, now;

signed main ( ) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen ("perm.in", "r", stdin);
	freopen ("perm.out", "w", stdout);
	cin >> n >> mod;
	if (n <= 2) {
		cout << 0;
		return 0;
	}
	for (int i = 3; i <= n; ++i) {
		int k1 = i - 1, k2 = i - 2;
		jie = jie * k2 % mod;
		int tmp1 = k1 * pre2 % mod;
		int tmp2 = (k1 * k2 >> 1) % mod;
		now = (pre1 + tmp1 + (jie * tmp2 % mod)) % mod;
		pre2 = pre1, pre1 = now;
		ans = ans ^ now;
	}
	cout << ans;
	return 0;
} 
