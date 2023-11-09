#include<bits/stdc++.h>
using LL = long long;
const LL mod = 1000000007;
const int maxn = 5e2 + 10;
int n;
char s[maxn];
LL C[maxn][maxn];
LL f[2][maxn][maxn][3];
int main() {
	freopen("jumpgo.in", "r", stdin);
	freopen("jumpgo.out", "w", stdout);
	scanf("%d%s", &n, s + 1);
	for (int i = 0; i <= n; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	f[0][0][0][0] = 1; 
	for (int id = 1, now = 1; id <= n; id++, now ^= 1) {
		int lst = now ^ 1;
		for (int i = 0; i <= (id >> 1); i++)
		for (int j = 0; j <= id - (i << 1); j++)
		for (int k : {0, 1, 2}) {
			f[now][i][j][k] = 0;
			if (s[id] == '1' && k == 2) continue;
			if (s[id] == '0' && k < 2) continue;
			if (s[id] != '1') {
				if (j) f[now][i][j][2] = (f[lst][i][j - 1][0] + f[lst][i][j - 1][1] + f[lst][i][j - 1][2]) % mod;
			}
			if (s[id] != '0') {
				f[now][i][j][1] = (f[lst][i][j][0] + f[lst][i][j][2]) % mod;
				if (i) f[now][i][j][0] = f[lst][i - 1][j][1];
			}
		}
	}
	LL ans = 0;
	for (int i = 0; i <= (n >> 1); i++)
	for (int j = 0; j <= n - (i << 1); j++)
	for (int k : {0, 1, 2})
		ans = (ans + C[i + j][i] * f[n & 1][i][j][k]) % mod;
	printf("%lld\n", ans);
	return 0;
} 
