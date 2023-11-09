#include <iostream>
#include <cstdio>
#include <algorithm>
#include <array>

const int MAXN = 17;
const int MODN = 998244353;

int n, ans;
int a[MAXN], b[MAXN], c[MAXN];

void calc() {
	b[0] = 2 * b[1] - b[2];
	for(int i = 1, j = 1; i <= n; ++i) {
		if(abs(b[i + 1] - b[i]) == 1)   {
			for(j = i + 1; j <= n; ++j) {
				if(b[j - 1] - b[j] == b[i] - b[i + 1])  {
					;
				}
				else    {
					break;
				}
			}
			for(int k = i; k < j; ++k)  {
				c[k] = j - i;
			}
			i = j - 1;
		}
		else    {
			c[i] = 1;
		}
	}
}

int main()	{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cerr.tie(nullptr);
	freopen("gap.in", "r", stdin);
	freopen("gap.out", "w", stdout);

	std::cin >> n;
	for(int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}

	for(int i = 1; i <= n; ++i) {
		b[i] = i;
	}

	int cnt = 0;
	do	{
		++cnt;
		calc();
		bool flag = 1;
		for(int i = 1; i <= n; ++i) {
			if(a[i] != c[i])    flag = 0;
		}
		(ans += flag) %= MODN;
		
	}	while(std::next_permutation(b + 1, b + 1 + n));
	
	std::cout << ans << std::endl;

	return 0;
}

