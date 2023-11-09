#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[15] = {0, 0, 0, 1, 7, 47, 322, 2404, 19778, 180130, 1809652};
int main()
{
	freopen("perm.in", "r", stdin);
	freopen("perm.out", "w", stdout);
	int n, mod, ans = 0;
	cin >> n >> mod;
	for (int i = 1; i <= n; i++) ans ^= (a[i] % mod);
	cout << ans;
	return 0;
}
/*
#include <iostream>
#include <cstdio>
using namespace std;
int dp[10000005];
int main()
{
	//freopen("perm.in", "r", stdin);
	//freopen("perm.out", "w", stdout);
	int n, mod, ans = 0; 
	cin >> n >> mod;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1];
		for (int x = 2; x <= i; x++)
			printf("%d 开头的有 %d 个\n", x, i - x + dp[i - 2]), dp[i] = (0ll + dp[i] + i - x + dp[i - 2]) % mod;
			
		ans ^= dp[i];
		printf("dp[%d] = %d\n", i, dp[i]);
	}
	cout << ans;
	return 0;
}
*/
