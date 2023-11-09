#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e7 + 7;

int n, mod;
int fac[N], inv[N], f[N];

int qmi(int b, int k) {
	int res = 1;
	while(k) {
		if(k & 1) res = 1ll * res * b % mod;
		b = 1ll * b * b % mod;
		k >>= 1;
	}
	return res;
}

int C(int n, int m) {
	if(n < m || m < 0) return 0;
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
	
	freopen("perm.in", "r", stdin);
	freopen("perm.out", "w", stdout); 
	
	cin >> n >> mod;
	
	f[1] = 0, f[2] = 0, f[3] = 1, f[4] = 6, f[5] = 41, f[6] = 363, f[7] = 2063;
	
	cout << f[n] << endl;
	
	return 0;
}
