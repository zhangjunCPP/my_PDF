#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, mod, ans = 0, f[10000010], pi[10000010];
int main()
{
	freopen("perm.in", "r", stdin);
	freopen("perm.out", "w", stdout);
	ll i, j, p;
	scanf("%lld%lld", &n, &mod);
	pi[0] = 1;
	for(i = 1; i <= n; i++) pi[i] = pi[i - 1] * i % mod;
	f[1] = 0; f[2] = 0;
	for(i = 3; i <= n; i++){
		f[i] = (f[i - 1] + (i - 1) * f[i - 2] + (i - 1) * (i - 2) / 2 % mod * pi[i - 2]) % mod;
		ans ^= f[i];
	}
	printf("%lld", ans);
	return 0;
}
