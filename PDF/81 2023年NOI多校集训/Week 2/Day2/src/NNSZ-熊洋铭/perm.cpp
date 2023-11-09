/*#include <iostream>
#include <vector>

typedef long long LL;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int n;
	LL MODN;
	std::cin >> n >> MODN;
	std::vector <LL> frac(n + 1);
	frac[0] = 1;
	for(int i = 1; i <= n; ++i)	{
		(frac[i] = frac[i - 1] * i) %= MODN;
	}
	
	std::vector <LL> f[n + 1], ans(n + 1);
	for(int len = 1; len <= n; ++len) {
		LL __ans = 0;
		for(int i = 2; i <= len - 1; ++i) {
			f[i].resize(i);
			for(int j = 1; j < i; ++j) {
//				f[i][j] = ((len - i) * frac[len - j - 1] * (frac[j - 1] - ans[j - 1])) % MODN;
				(f[i][j] = (len - i) * (frac[len - 2] - ans[len - 2])) %= MODN;
				(__ans += f[i][j]) %= MODN;
				if(len == 5)	std::cerr << "f[" << i << "][" << j << "] = " << f[i][j] << '\n';
			}
		}
		ans[len] = __ans;
	}
	
	for(int i = 1; i <= n; ++i) {
		std::cerr << ans[i] << ' '; 
	}
	std::cerr << '\n';
	
	LL __ans = 0;
	for(int i = 1; i <= n; ++i) {
		__ans ^= ans[i];
	}
	
	std::cout << __ans << '\n';
	
	return 0;
}*/
/*
5 998244353

3 4 1 5 2
4 3 5 1 2
5 3 4 2 1
47
*/

/*
2 1
2 3 1 4 5
2 3 1 5 4
2 3 4 1 5
2 3 4 5 1
2 3 5 1 4
2 3 5 4 1
2 4 1 3 5
2 4 1 5 3
2 4 3 1 5
2 4 3 5 1
2 4 5 1 3
2 4 5 3 1
2 5 1 3 4
2 5 1 4 3
2 5 3 1 4
2 5 3 4 1
2 5 4 1 3
2 5 4 3 1

3 1
3 2 4 1 5
3 2 4 5 1
3 2 5 1 4
3 2 5 4 1
3 4 2 1 5
3 4 2 5 1
3 4 5 1 2
3 4 5 2 1
3 5 2 1 4
3 5 2 4 1
3 5 4 1 2
3 5 4 2 1

3 2
1 3 4 2 5
1 3 4 5 2
1 3 5 2 4
1 3 5 4 2

4 1
4 2 3 5 1
4 2 5 3 1
4 3 2 5 1
4 3 5 2 1
4 5 2 3 1
4 5 3 2 1

4 2
1 4 3 5 2
1 4 5 3 2

4 3
1 2 4 5 3
2 1 4 5 3
*/

// 看起来是个 DP，应该要想办法做到 O(n)。
// 容斥一下或许可做？

#include <iostream>
#include <algorithm>

int main() {
	freopen("perm.in", "r", stdin);
	freopen("perm.out", "w", stdout);
	
	int n, MODN;
	std::cin >> n >> MODN;
	long long f_ans[n + 1];
	int old_n = n;
	++n;
	while(n--) {
		int a[n + 1];
		for(int i = 1; i <= n; ++i) {
			a[i] = i;
		}
		int b[n + 1];
		long long ans = 0;
		do {
			for(int i = 1; i <= n; ++i) {
				b[a[i]] = i;
			}
			int flag = 1;
			for(int i = 1; i <= n; ++i) {
				if(b[i] < a[i])	{
					flag = 0;
					break;
				}
				if(b[i] > a[i])	{
					flag = 2;
					break;
				}
			}
			if(flag == 2)	(++ans) %= MODN;
		}	while(std::next_permutation(a + 1, a + n + 1));
		f_ans[n] = ans;
	}
	
	long long ans = 0;
	
	for(int i = 1; i <= old_n; ++i) ans ^= f_ans[i];
	
	std::cout << ans << '\n';
	
	return 0;
}

